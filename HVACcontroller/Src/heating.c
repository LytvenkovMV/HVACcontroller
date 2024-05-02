
#include "heating.h"



void HEATING_InitState(HEATING_State *HeatingState)
{
	HeatingState->ProcessState = HEATING_OK;
	HeatingState->Plan = HEATING_MANUAL;
	HeatingState->CurrMode = HEATING_OFF;
	HeatingState->PrevMode = HEATING_OFF;
}



HEATING_UpdatingStatus HEATING_UpdateData(MESSAGE_ID *MessageID, SENSOR_Values *SensorValues, SETTING_Values *SettingValues, osMessageQId *SensorsQH, osMessageQId *SettingValuesQH, uint16_t *callsCnt)
{
	portBASE_TYPE xSensorStatus = pdFAIL, xSettingStatus = pdFAIL;
	
	/* Update sensor values */
	xSensorStatus = xQueuePeek(SensorsQH, SensorValues, 0);

	if (xSensorStatus != pdPASS)
	{
		*MessageID = MESSAGE_20;
		return HEATING_UPDATING_FAIL;
	}

	/* Update setting once in 20 function calls */
	if ((*callsCnt) == 0)
	{
		/* Initialize counter */
		*callsCnt = 20;

		/* Try to receive settings */
		xSettingStatus = xQueuePeek(SettingValuesQH, SettingValues, 0);
		
		/* Return if they are not available */
		if (xSettingStatus != pdPASS)
		{
			*MessageID = MESSAGE_21;
			return HEATING_UPDATING_FAIL;
		}
	}
	else (*callsCnt)--;
	
	return HEATING_UPDATING_OK;
}



HEATING_Mode HEATING_SelectModeByTime(SETTING_Values *SettingValues, RTC_HandleTypeDef *HandleRTC)
{
	RTC_DateTypeDef Date;
	RTC_TimeTypeDef Time;
	SETTING_ArrayID ArrayID;
	int16_t modeSetting;

	HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
	
	switch (Date.WeekDay)
	{
		case RTC_WEEKDAY_MONDAY:		ArrayID = SETTING_ARRAY_10; break;
		case RTC_WEEKDAY_TUESDAY:		ArrayID = SETTING_ARRAY_11; break;
		case RTC_WEEKDAY_WEDNESDAY:		ArrayID = SETTING_ARRAY_12; break;
		case RTC_WEEKDAY_THURSDAY:		ArrayID = SETTING_ARRAY_13; break;
		case RTC_WEEKDAY_FRIDAY:		ArrayID = SETTING_ARRAY_14; break;
		case RTC_WEEKDAY_SATURDAY:		ArrayID = SETTING_ARRAY_15; break;
		case RTC_WEEKDAY_SUNDAY:		ArrayID = SETTING_ARRAY_16; break;
		default: ArrayID = SETTING_ARRAY_10;
	}
	
	modeSetting = SETTING_GetValue(ArrayID, (Time.Hours + 1), SettingValues);
	
	switch (modeSetting)
	{
		case 0: return HEATING_OFF;
		case 1: return HEATING_COMFORT;
		case 2: return HEATING_ECO;
		case 3: return HEATING_FRZ;
		default: return HEATING_OFF;
	}
}



void HEATING_UpdateMode(HEATING_State *HeatingState, SETTING_Values *SettingValues, osMessageQId *HeatingCmdQueueHandle, RTC_HandleTypeDef *HandleRTC)
{	
	portBASE_TYPE xStatus;
	COMMAND_HeatingCommand Command;

	/* Check for a new command from the buttons */
	xStatus = xQueueReceive(HeatingCmdQueueHandle, &Command, 0);
	
	/* If a new command is present */
	if (xStatus == pdPASS)
	{
		switch (Command)
		{
			case COMMAND_HEATING_TURN_OFF:
			{
				HeatingState->Plan = HEATING_MANUAL;
				HeatingState->CurrMode = HEATING_COOLING;
			}
			break;
			
			case COMMAND_HEATING_TURN_ON_COMF:
			{
				HeatingState->Plan = HEATING_MANUAL;
				HeatingState->CurrMode = HEATING_COMFORT;
			}
			break;
			
			case COMMAND_HEATING_TURN_ON_ECO:
			{
				HeatingState->Plan = HEATING_MANUAL;
				HeatingState->CurrMode = HEATING_ECO;
			}
			break;
			
			case COMMAND_HEATING_TURN_ON_FRZ:
			{
				HeatingState->Plan = HEATING_MANUAL;
				HeatingState->CurrMode = HEATING_FRZ;
			}
			break;
			
			case COMMAND_HEATING_TURN_ON_PROG:
			{
				HeatingState->Plan = HEATING_AUTOMATIC;
			}
			break;
			
			default:;
		}	
	}
	
	/* If the plan is automatic, update the mode by time */
	if ((HeatingState->Plan) == HEATING_AUTOMATIC) HeatingState->CurrMode = HEATING_SelectModeByTime(SettingValues, HandleRTC);
}



void HEATING_TurnOnPump(SETTING_Values *SettingValues)
{
	int16_t pumpSetting;
	
	/* Check if the pump is in use */
	pumpSetting = SETTING_GetValue(SETTING_ARRAY_05, 1, SettingValues);
	if (pumpSetting != 1)
	{
		OUTPUT_ChangeState(OUTPUT_COOLANT_PUMP, OUTPUT_ON);
	}
}



void HEATING_TurnOffPump(void)
{
	OUTPUT_ChangeState(OUTPUT_COOLANT_PUMP, OUTPUT_OFF);
}



void HEATING_TurnOnHeaters(SETTING_Values *SettingValues)
{	
	int16_t usedHeaterSetting;
	
	/* Check used heater setting */
	usedHeaterSetting = SETTING_GetValue(SETTING_ARRAY_05, 2, SettingValues);
	switch (usedHeaterSetting)
	{
		case 0: OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_1, OUTPUT_ON); break;
		case 1: OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_2, OUTPUT_ON); break;
		default:
		{
			OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_1, OUTPUT_ON);
			osDelay(30);
			OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_2, OUTPUT_ON);	
		}
	}
}



void HEATING_TurnOffHeaters(void)
{
	OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_1, OUTPUT_OFF);
	osDelay(20);
	OUTPUT_ChangeState(OUTPUT_COOLANT_HEATER_2, OUTPUT_OFF);
}



void HEATING_TurnOn(SETTING_Values *SettingValues, osMessageQId *LedQueueHandle)
{
	HEATING_TurnOnPump(SettingValues);
	LED_SendQuery(LED1, LED_ON, LedQueueHandle, 100);
}



void HEATING_TurnOff(osMessageQId *LedQueueHandle)
{
	HEATING_TurnOffHeaters();
	LED_SendQuery(LED1, LED_OFF, LedQueueHandle, 100);
}



void HEATING_Trip(HEATING_State *HeatingState, osMessageQId *LedQueueHandle)
{
	HeatingState->ProcessState = HEATING_FAIL;
	HEATING_TurnOff(LedQueueHandle);
	HeatingState->CurrMode = HEATING_COOLING;
	LED_SendQuery(LED4, LED_ON, LedQueueHandle, 100);
}



HEATING_CoolingState HEATING_CoolDown(SETTING_Values *SettingValues, uint16_t *callsCnt, uint16_t const HeatingPeriodMs)
{
	int16_t coolingTimeSetting;
	uint16_t callsNumber;
	
	/* Get setting */
	coolingTimeSetting = SETTING_GetValue(SETTING_ARRAY_05, 3, SettingValues);
	
	/* Calculate the number of function calls that are needed to provide the delay */
	callsNumber = coolingTimeSetting * 60000 / HeatingPeriodMs;
	
	if ((*callsCnt) >= callsNumber)
	{
		*callsCnt = 0;
		HEATING_TurnOffPump();
		return HEATING_COOLING_COMPLETE;
	}
	else (*callsCnt)++;
	
	return HEATING_COOLING_NOT_COMPLETE;
}



void HEATING_Reset(HEATING_State *HeatingState, osMessageQId *HeatingResetQueueHandle, osMessageQId *LedQueueHandle)
{
	portBASE_TYPE xStatus;
	uint16_t temp;
	
	xStatus = xQueueReceive(HeatingResetQueueHandle, &temp, 0);
	if (xStatus == pdPASS)
	{
		HeatingState->ProcessState = HEATING_OK;
		LED_SendQuery(LED4, LED_OFF, LedQueueHandle, 100);
	}
}
