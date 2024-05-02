
#include "sensor.h"
#include "sensor_config.h"



void SENSOR_CalibrateADC(ADC_HandleTypeDef *hadc1, ADC_HandleTypeDef *hadc2)
{
	HAL_StatusTypeDef Status1 = HAL_ERROR, Status2 = HAL_ERROR;

	/* Calibrate ADC1 */
	do
	{
		Status1 = HAL_ADCEx_Calibration_Start (hadc1);
		osDelay(50);
	}
	while (Status1 != HAL_OK);

	/* Calibrate ADC2 */
	do
	{
		Status2 = HAL_ADCEx_Calibration_Start (hadc2);
		osDelay(50);
	}
	while (Status2 != HAL_OK);
}



void SENSOR_StartADC(SENSOR_ADCvalues *ADCvalues, ADC_HandleTypeDef *hadc1, ADC_HandleTypeDef *hadc2)
{
	/* Start slave ADC */
	HAL_ADC_Start(hadc2);

	/* Start master ADC */
	HAL_ADCEx_MultiModeStart_DMA(hadc1, (uint32_t *)ADCvalues, 2);
}



//void SENSOR_CalculateInstCurrents(SENSOR_ADCvalues *ADCvalues, SENSOR_CurrentsStruct *Currents)
//{
//	/* If reference voltage is out of range */
//	if ((ADCvalues->Uref < SENSOR_UREF_LOWER_LIMIT) || (ADCvalues->Uref > SENSOR_UREF_UPPER_LIMIT))
//	{
//		Currents->Status = SENSOR_FAIL;
//	}
//	else
//	{
//		Currents->Status = SENSOR_OK;
//
//		/* Save previous values */
//		Currents->prevIL1 = Currents->currIL1;
//		Currents->prevIL3 = Currents->currIL3;
//
//		/* Calculate current values */
//		/* The values in relative units, not amperes */
//		Currents->currIL1 = ADCvalues->IL1 - ADCvalues->Uref + SENSOR_ADC1_ZERO_SHIFT;
//		Currents->currIL3 = ADCvalues->IL3 - ADCvalues->Uref + SENSOR_ADC2_ZERO_SHIFT;
//	}
//}
//
//
//
//void SENSOR_CalculateRMSCurrents(SENSOR_InstCurrents *InstCurrents, float rmsBufferL1[], float rmsBufferL2[], float rmsBufferL3[])
//{
//	float tempIL1 = 0, tempIL2 = 0, tempIL3 = 0;
//	float sumIL1 = 0, sumIL2 = 0, sumIL3 = 0;
//	float IL1 = 0, IL2 = 0, IL3 = 0;
//
//	/* Calculate RMS values */
//	for (uint16_t i = 0; i < SENSOR_INST_CURR_BUFFER_SIZE; i ++)
//	{
//		IL1 = InstCurrents->bufferIL1[i] * SENSOR_ADC1_COEFF;
//		IL3 = InstCurrents->bufferIL3[i] * SENSOR_ADC2_COEFF;
//		IL2 = IL1 + IL3;
//
//		sumIL1 += (IL1 * IL1);
//		sumIL2 += (IL2 * IL2);
//		sumIL3 += (IL3 * IL3);
//	}
//	tempIL1 = sqrtf(sumIL1 / SENSOR_RMS_CURR_BUFFER_SIZE);
//	tempIL2 = sqrtf(sumIL2 / SENSOR_RMS_CURR_BUFFER_SIZE);
//	tempIL3 = sqrtf(sumIL3 / SENSOR_RMS_CURR_BUFFER_SIZE);
//
//	/* Shift RMS current buffers to the left */
//	for (uint16_t i = 0; i < (SENSOR_RMS_CURR_BUFFER_SIZE - 1); i ++)
//	{
//		rmsBufferL1[i] = rmsBufferL1[i + 1];
//		rmsBufferL2[i] = rmsBufferL2[i + 1];
//		rmsBufferL3[i] = rmsBufferL3[i + 1];
//	}
//
//	/* Copy calculated values to the last buffers members */
//	rmsBufferL1[SENSOR_RMS_CURR_BUFFER_SIZE - 1] = tempIL1;
//	rmsBufferL2[SENSOR_RMS_CURR_BUFFER_SIZE - 1] = tempIL2;
//	rmsBufferL3[SENSOR_RMS_CURR_BUFFER_SIZE - 1] = tempIL3;
//}
//
//
//
//float SENSOR_CalculateMeanCurrent(float buffer[], uint16_t const bufferSize)
//{
//	float sum = 0, meanValue = 0;
//
//	for (uint16_t i = 0; i < bufferSize; i ++)
//	{
//		sum += buffer[i];
//	}
//
//	meanValue = sum / bufferSize;
//
//	return meanValue;
//}
//
//
//
//float SENSOR_CalculateMeanVoltage(uint16_t buffer[], uint16_t const bufferSize)
//{
//	float sum = 0, meanValue = 0;
//
//	for (uint16_t i = 0; i < bufferSize; i ++)
//	{
//		sum += buffer[i];
//	}
//
//	meanValue = sum / bufferSize;
//
//	return meanValue;
//}
//
//
//
//int8_t SENSOR_CalculateMeanTemperature(int8_t buffer[], uint16_t const bufferSize)
//{
//	float sum = 0, temp = 0;
//	int8_t meanValue = 0;
//
//	for (uint16_t i = 0; i < bufferSize; i ++)
//	{
//		sum += (float)buffer[i];
//	}
//
//	temp = sum / bufferSize;
//
//	meanValue = (int8_t)roundf(temp);
//
//	return meanValue;
//}








SENSOR_Status SENSOR_CheckRXData(AM2320_RXData *Data)
{
	uint16_t rxCRC = 0, calcCRC = 0;
	uint8_t message[6];

	message[0] = Data->functionCode;
	message[1] = Data->numberOfBytes;
	message[2] = Data->humidityHighByte;
	message[3] = Data->humidityLowByte;
	message[4] = Data->tempHighByte;
	message[5] = Data->tempLowByte;

	/* Calculate CRC */
	calcCRC = AM2320_CalcCRC16(message);

	/* Get received CRC */
	rxCRC = (Data->crcHighByte << 8) | Data->crcLowByte;

	/* If calculated CRC and received CRC are equal, return OK */
	if (calcCRC == rxCRC) return SENSOR_OK;

	return SENSOR_FAIL;
}



void SENSOR_GetSensorFromADC(SENSOR_Struct *Sensor, uint16_t buffer[SENSOR_ADC_BUFFER_SIZE], uint32_t const ADCcoeff)
{
	uint32_t sum = 0;
	uint16_t ADCmeanValue = 0;
	uint32_t resistance1000000 = 0;
	int32_t temp100 = 0, temp10 = 0;
	int16_t	temp = 0;

	/* Calculate ADC mean value */
	for (uint16_t i = 0; i < SENSOR_ADC_BUFFER_SIZE; i ++)
	{
		sum += buffer[i];
	}
	ADCmeanValue = sum / SENSOR_ADC_BUFFER_SIZE;

	/* If ADC mean value is in the allowed limits */
	if ((ADCmeanValue >= SENSOR_ADC_LOWER_LIMIT) && (ADCmeanValue <= SENSOR_ADC_UPPER_LIMIT))
	{
		/* Calculate resistance in ohms multiplied by 1000000 */
		resistance1000000 = ADCmeanValue * ADCcoeff;

		/* To avoid operations with decimal numbers the sensor value will be the value of degrees Celsius multiplied by 100
		 * Thus the decimal digits of the temperature will be two last digits of the returned value
		 *
		 * in order to get value in degrees Celsius, divide by 100
		 * e.g. if returned value = -2563, then value in degrees Celsius = -256 / 100 = -25.63
		 * 		if returned value = +2341, then value in degrees Celsius = +234 / 100 = +23.41
		 *
		 */

		/* Calculate temperature in degrees Celsius multiplied by 100 */
		temp100 = PT100_CalcTemperature(resistance1000000);

		/* Round the temperate to get integer value */
		/* First rounding */
		if (temp100 >= 0)
		{
			if ((temp100 % 10) < 5) temp10 = temp100 / 10;
			else temp10 = (temp100 / 10) + 1;
		}
		else
		{
			if ((temp100 % 10) > -5) temp10 = temp100 / 10;
			else temp10 = (temp100 / 10) - 1;
		}
		/* Second rounding */
		if (temp10 >= 0)
		{
			if ((temp10 % 10) < 5) temp = temp10 / 10;
			else temp = (temp10 / 10) + 1;
		}
		else
		{
			if ((temp10 % 10) > -5) temp = temp10 / 10;
			else temp = (temp10 / 10) - 1;
		}

		/* Fill in sensor value */
		Sensor->Value = temp;
		Sensor->Status = SENSOR_OK;
	}
	else
	{
		Sensor->Status = SENSOR_FAIL;
	}
}



void SENSOR_UpdateValues(SENSOR_Values *Values, AM2320_State *AM2320State, osMessageQId *RXDataQueueHandle, osMessageQId *ADCvaluesQueueHandle)
{
	portBASE_TYPE xRXDataQueueStatus = pdFAIL, xADCvaluesQueueStatus = pdFAIL;
	AM2320_RXData RXData;
	SENSOR_Status RXDataStatus = SENSOR_FAIL;
	SENSOR_ADCbuffer ADCbuffer;



	/************************************************** UPDATE ROOM TEMPERATURE AND HUMIDITY **************************************************/

	/* Receive RXData from queue */
	xRXDataQueueStatus = xQueueReceive(RXDataQueueHandle, &RXData, 0);

	/* If the queue is empty */
	if (xRXDataQueueStatus != pdPASS)
	{
		/* If timeout has elapsed */
		if (AM2320State->timeoutCnt >= 40)
		{
			AM2320State->timeoutCnt = 0;

			/* Switch to the failure state */
			AM2320State->Status = AM2320_FAIL;
			Values->RoomTemp.Status = SENSOR_FAIL;
			Values->RoomHumid.Status = SENSOR_FAIL;
		}
		else AM2320State->timeoutCnt ++;
	}
	else
	{
		/* Reset RX timeout counter */
		AM2320State->timeoutCnt = 0;

		/* Check RX data for the CRC errors */
		RXDataStatus = SENSOR_CheckRXData(&RXData);

		/* If CRC error */
		if (RXDataStatus != SENSOR_OK)
		{
			/* If errors counter exceeds limit */
			if (AM2320State->errorsCnt >= 5)
			{
				AM2320State->errorsCnt = 0;

				/* Switch to the failure state */
				AM2320State->Status = AM2320_FAIL;
				Values->RoomTemp.Status = SENSOR_FAIL;
				Values->RoomHumid.Status = SENSOR_FAIL;
			}
			else AM2320State->errorsCnt ++;
		}
		else
		{
			/* Reset errors counter */
			AM2320State->errorsCnt = 0;

			/* Switch to the OK state */
			AM2320State->Status = AM2320_OK;

			/* Update sensor values */
			Values->RoomTemp.Value = AM2320_CalcTemp(RXData.tempHighByte, RXData.tempLowByte);
			Values->RoomTemp.Status = SENSOR_OK;

			Values->RoomHumid.Value = AM2320_CalcHumidity(RXData.humidityHighByte, RXData.humidityLowByte);
			Values->RoomHumid.Status = SENSOR_OK;
		}
	}

	/******************************************************************************************************************************************/



	/*********************************************************** UPDATE ADC VALUES ************************************************************/

	/* Receive ADC values from queue */
	xADCvaluesQueueStatus = xQueueReceive(ADCvaluesQueueHandle, &ADCbuffer, 0);

	/* If the queue is empty */
	if (xADCvaluesQueueStatus != pdPASS)
	{
		/* Switch to the failure state */
		Values->VentInletTemp.Status = SENSOR_FAIL;
		Values->VentOutletTemp.Status = SENSOR_FAIL;
		Values->HeatingInletTemp.Status = SENSOR_FAIL;
		Values->HeatingOutletTemp.Status = SENSOR_FAIL;
	}
	else
	{
		/* Get ventilation inlet temperature */
		SENSOR_GetSensorFromADC(&(Values->VentInletTemp), ADCbuffer.BUFFERTSENS1, SENSOR_ADC_COEFF_1);

		/* Get ventilation outlet temperature */
		SENSOR_GetSensorFromADC(&(Values->VentOutletTemp), ADCbuffer.BUFFERTSENS2, SENSOR_ADC_COEFF_2);

		/* Get heating inlet temperature */
		SENSOR_GetSensorFromADC(&(Values->HeatingInletTemp), ADCbuffer.BUFFERTSENS3, SENSOR_ADC_COEFF_3);

		/* Get heating outlet temperature */
		SENSOR_GetSensorFromADC(&(Values->HeatingOutletTemp), ADCbuffer.BUFFERTSENS4, SENSOR_ADC_COEFF_4);
	}

  	/******************************************************************************************************************************************/
}



void SENSOR_GetCharValue(uint8_t number, SENSOR_Values *Values, char result[6])
{
	SENSOR_Type Type;
	SENSOR_Status Status = SENSOR_FAIL;
	int16_t value = 0;

	/* Get type, status and value */
	switch (number)
	{
	case 1:
	{
		Type = SENSOR_CONF_SENSOR01_TYPE;
		Status = Values->RoomTemp.Status;
		value =  Values->RoomTemp.Value;
	}
	break;

	case 2:
	{
		Type = SENSOR_CONF_SENSOR02_TYPE;
		Status = Values->RoomHumid.Status;
		value =  Values->RoomHumid.Value;
	}
	break;

	case 3:
	{
		Type = SENSOR_CONF_SENSOR03_TYPE;
		Status = Values->HeatingInletTemp.Status;
		value =  Values->HeatingInletTemp.Value;
	}
	break;

	case 4:
	{
		Type = SENSOR_CONF_SENSOR04_TYPE;
		Status = Values->HeatingOutletTemp.Status;
		value =  Values->HeatingOutletTemp.Value;
	}
	break;

	case 5:
	{
		Type = SENSOR_CONF_SENSOR05_TYPE;
		Status = Values->VentInletTemp.Status;
		value =  Values->VentInletTemp.Value;
	}
	break;

	case 6:
	{
		Type = SENSOR_CONF_SENSOR06_TYPE;
		Status = Values->VentOutletTemp.Status;
		value =  Values->VentOutletTemp.Value;
	}
	break;

	default:
	{
		strcpy(result, "");
		return;
	}
	}
	
	/* If status isn't OK return */
	if (Status != SENSOR_OK)
	{
		strcpy(result, SENSOR_CONF_FAIL);
		return;
	}

	/* Convert to char */
	switch (Type)
	{
		case SENSOR_INTEGER_DEGREE:
		{
			PRINT_Integer(value, PRINT_RIGHT_ALIGNMENT, result);
			strcat(result, SENSOR_CONF_DEGREE_UNIT);
		}
		break;

		case SENSOR_1_DECIMAL_DEGREE:
		{
			PRINT_Decimal1Place(value, PRINT_RIGHT_ALIGNMENT, result);
			strcat(result, SENSOR_CONF_DEGREE_UNIT);
		}
		break;

		case SENSOR_INTEGER_PERCENT:
		{
			PRINT_UnsignedInteger((uint16_t)value, PRINT_RIGHT_ALIGNMENT, result);
			strcat(result, SENSOR_CONF_PERCENT_UNIT);
		}
		break;

		case SENSOR_1_DECIMAL_PERCENT:
		{
			PRINT_UnsignedDecimal1Place((uint16_t)value, PRINT_RIGHT_ALIGNMENT, result);
			strcat(result, SENSOR_CONF_PERCENT_UNIT);
		}
		break;

		case SENSOR_2_DECIMAL_PERCENT:
		{
			PRINT_UnsignedDecimal2Place((uint16_t)value, result);
			strcat(result, SENSOR_CONF_PERCENT_UNIT);
		}
		break;

		default:
		{
			strcpy(result, "    ?");
		}
	}
}
