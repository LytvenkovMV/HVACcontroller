
#include "regulator.h"



void REGULATOR_Init(REGULATOR_Status *Status)
{
	Status->State = REGULATOR_FAIL;
	Status->PIDdata.ek = 0;
	Status->PIDdata.ek_1 = 0;
	Status->PIDdata.ek_2 = 0;
	Status->PIDdata.uk = 0;
	Status->PIDdata.uk_1 = 0;
	Status->OutputCommand = REGULATOR_NO_CMD;
}



REGULATOR_OutputCommand REGULATOR_RegulateOnOff(uint16_t target, uint16_t hysteresis, int16_t current)
{
	/* If current value is above the dead zone return off command */
	if (current >= target) return REGULATOR_TURN_OFF_CMD;
	
	/* If current value is below the dead zone return on command */
	if (current <= (target - hysteresis)) return REGULATOR_TURN_ON_CMD;
	
	/* When value is in the dead zone return no command */
	return REGULATOR_NO_CMD;
}



REGULATOR_OutputCommand REGULATOR_RegulatePID(uint16_t target, int16_t current, uint16_t Kp, uint16_t Ki, uint16_t Kd, REGULATOR_PIDdata *Data)
{
	/********************* REGULATOR FORMULA ***********************
	 * u(k) = u(k-1) + Kp * (d0 * e(k) + d1 * e(k-1) + d2 * e(k-2)),
	 *
	 * when
	 * d0 = 1 + (Ts / Ti) + (Td / Ts)
	 * d1 = - 1 - 2 * (Td / Ts)
	 * d2 = Td / Ts
	 *
	 * u	- regulator output
	 * e	- error signal
	 * Kp	- proportional coefficient
	 * Ts	- sampling period
	 * Ti	- integral constant
	 * Td	- derivative constant
	 */
	
	int16_t d0, d1, d2;
	int16_t ek, ek_1, ek_2;
	int16_t uk, uk_1;
	
	/* Calculate coefficients */
	d0 = 1 + Ki + Kd;
	d1 = - 1 - 2 * Kd;
	d2 = Kd;
	
	/* Calculate errors */
	ek = target - current;
	ek_1 = Data->ek;
	ek_2 = Data->ek_1;
	
	/* Calculate output */
	uk_1 = Data->uk;
	uk = uk_1 + Kp * ((d0 * ek) + (d1 * ek_1) + (d2 + ek_2));
	
	/* Save errors */
	(Data->ek) = ek;
	(Data->ek_1) = ek_1;
	(Data->ek_2) = ek_2;

	/* Save output */
	(Data->uk) = uk;
	(Data->uk_1) = uk_1;
	
	/* Return command */
	if ((uk_1 <= 0) && (uk > 0)) return REGULATOR_TURN_ON_CMD;
	if ((uk_1 >= 0) && (uk < 0)) return REGULATOR_TURN_OFF_CMD;
	
	return REGULATOR_NO_CMD;
}



void REGULATOR_Regulate(REGULATOR_Status *Status, REGULATOR_SensorsData *SensorsData, REGULATOR_Settings *Settings)
{
	uint16_t targetTemp, targetTempHysteresis;
	int16_t currentTemp;

	/* Initialize temperature variables */
	/* Check parameter for regulation setting */
	switch (Settings->parameterForRegulation)
	{
		/* Outlet temperature */
		case 1:
		{
			/* Check the sensor is OK */
			if (SensorsData->OutletTempSensorStatus != SENSOR_OK)
			{
				Status->State = REGULATOR_FAIL;
				return;
			}
			
			targetTemp = Settings->outletTemp;
			targetTempHysteresis = Settings->outletTempHysteresis;
			currentTemp = SensorsData->outletCurrTemp;
			
		}
		break;
		
		/* Room temperature */
		default:
		{
			/* Check the sensor is OK */
			if (SensorsData->RoomTempSensorStatus != SENSOR_OK)
			{
				Status->State = REGULATOR_FAIL;
				return;
			}
			
			targetTemp = Settings->roomTemp;
			targetTempHysteresis = Settings->roomTempHysteresis;
			currentTemp = SensorsData->roomCurrTemp;
		}
	}	
	
	/* Correction for humidity */
	/* Check the correction is on */
	if ((Settings->humidityCorrectionCtrl) == 1)
	{
		/* Check the sensor is OK */
		if (SensorsData->RoomHumidSensorStatus != SENSOR_OK)
		{
			Status->State = REGULATOR_FAIL;
			return;
		}
		
		/* If humidity is lower than threshold decrease target temperature */
		if ((SensorsData->roomCurrHumidity) <= (Settings->humidityLowerThreshold)) targetTemp = targetTemp - (Settings->humidityCorrectionTemp);
		
		/* If humidity is upper than threshold increase target temperature */
		if ((SensorsData->roomCurrHumidity) >= (Settings->humidityUpperThreshold)) targetTemp = targetTemp + (Settings->humidityCorrectionTemp);
	}
	
	/* Regulation process */
	/* Check the regulator type setting */
	switch (Settings->regulatorType)
	{
		/* PID regulator */
		case 1:
		{
			Status->OutputCommand = REGULATOR_RegulatePID(targetTemp, currentTemp, Settings->Kp, Settings->Ki, Settings->Kd, &(Status->PIDdata));
			Status->State = REGULATOR_OK;
		}
		break;
		
		/* On/Off regulator */
		default:
		{
			Status->OutputCommand = REGULATOR_RegulateOnOff(targetTemp, targetTempHysteresis, currentTemp);
			Status->State = REGULATOR_OK;
		}
	}
}



void REGULATOR_Heating(REGULATOR_Status *Status, HEATING_Mode Mode, SETTING_Values *SettingValues, SENSOR_Values *SensorValues)
{
	REGULATOR_SensorsData Data;
	REGULATOR_Settings Settings;
	
	/* Fill in sensors data */
	/* Sensor statuses */
	Data.OutletTempSensorStatus	=	SensorValues->HeatingOutletTemp.Status;
	Data.RoomTempSensorStatus	=	SensorValues->RoomTemp.Status;
	Data.RoomHumidSensorStatus	=	SensorValues->RoomHumid.Status;
	/* Current values */
	Data.outletCurrTemp		=	SensorValues->HeatingOutletTemp.Value;
	Data.roomCurrTemp		=	SensorValues->RoomTemp.Value;
	Data.roomCurrHumidity	=	SensorValues->RoomHumid.Value;
	
	/* Fill in settings */
	/* Check current heating mode and get corresponding settings */
	switch (Mode)
	{
		case HEATING_COMFORT:
		{
			Settings.parameterForRegulation =	SETTING_GetValue(SETTING_ARRAY_06, 1, SettingValues);
			Settings.humidityCorrectionCtrl =	SETTING_GetValue(SETTING_ARRAY_06, 2, SettingValues);
			Settings.roomTemp =					SETTING_GetValue(SETTING_ARRAY_06, 3, SettingValues);
			Settings.roomTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_06, 4, SettingValues);
			Settings.outletTemp =				SETTING_GetValue(SETTING_ARRAY_06, 5, SettingValues);
			Settings.outletTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_06, 6, SettingValues);
			Settings.humidityLowerThreshold =	SETTING_GetValue(SETTING_ARRAY_06, 7, SettingValues);
			Settings.humidityUpperThreshold =	SETTING_GetValue(SETTING_ARRAY_06, 8, SettingValues);
			Settings.humidityCorrectionTemp =	SETTING_GetValue(SETTING_ARRAY_06, 9, SettingValues);
		}
		break;
		
		case HEATING_ECO:
		{
			Settings.parameterForRegulation =	SETTING_GetValue(SETTING_ARRAY_07, 1, SettingValues);
			Settings.humidityCorrectionCtrl =	SETTING_GetValue(SETTING_ARRAY_07, 2, SettingValues);
			Settings.roomTemp =					SETTING_GetValue(SETTING_ARRAY_07, 3, SettingValues);
			Settings.roomTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_07, 4, SettingValues);
			Settings.outletTemp =				SETTING_GetValue(SETTING_ARRAY_07, 5, SettingValues);
			Settings.outletTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_07, 6, SettingValues);
			Settings.humidityLowerThreshold =	SETTING_GetValue(SETTING_ARRAY_07, 7, SettingValues);
			Settings.humidityUpperThreshold =	SETTING_GetValue(SETTING_ARRAY_07, 8, SettingValues);
			Settings.humidityCorrectionTemp =	SETTING_GetValue(SETTING_ARRAY_07, 9, SettingValues);
		}
		break;

		default:
		{
			Settings.parameterForRegulation =	SETTING_GetValue(SETTING_ARRAY_08, 1, SettingValues);
			Settings.humidityCorrectionCtrl =	SETTING_GetValue(SETTING_ARRAY_08, 2, SettingValues);
			Settings.roomTemp =					SETTING_GetValue(SETTING_ARRAY_08, 3, SettingValues);
			Settings.roomTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_08, 4, SettingValues);
			Settings.outletTemp =				SETTING_GetValue(SETTING_ARRAY_08, 5, SettingValues);
			Settings.outletTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_08, 6, SettingValues);
			Settings.humidityLowerThreshold =	SETTING_GetValue(SETTING_ARRAY_08, 7, SettingValues);
			Settings.humidityUpperThreshold =	SETTING_GetValue(SETTING_ARRAY_08, 8, SettingValues);
			Settings.humidityCorrectionTemp =	SETTING_GetValue(SETTING_ARRAY_08, 9, SettingValues);
		}
	}

	Settings.regulatorType = SETTING_GetValue(SETTING_ARRAY_05, 4, SettingValues);
	Settings.Kp =	SETTING_GetValue(SETTING_ARRAY_05, 5, SettingValues);
	Settings.Ki =	SETTING_GetValue(SETTING_ARRAY_05, 6, SettingValues);
	Settings.Kd =	SETTING_GetValue(SETTING_ARRAY_05, 7, SettingValues);
	
	/* Regulation process */
	REGULATOR_Regulate(Status, &Data, &Settings);
}



void REGULATOR_Ventilation(REGULATOR_Status *Status, SETTING_Values *SettingValues, SENSOR_Values *SensorValues)
{
	REGULATOR_SensorsData Data;
	REGULATOR_Settings Settings;

	/* Fill in sensors data */
	/* Sensor statuses */
	Data.OutletTempSensorStatus	=	SensorValues->VentOutletTemp.Status;
	Data.RoomTempSensorStatus	=	SensorValues->RoomTemp.Status;
	Data.RoomHumidSensorStatus	=	SensorValues->RoomHumid.Status;
	/* Current values */
	Data.outletCurrTemp		=	SensorValues->VentOutletTemp.Value;
	Data.roomCurrTemp		=	SensorValues->RoomTemp.Value;
	Data.roomCurrHumidity	=	SensorValues->RoomHumid.Value;

	/* Fill in settings */
	Settings.parameterForRegulation =	SETTING_GetValue(SETTING_ARRAY_02, 1, SettingValues);
	Settings.humidityCorrectionCtrl =	SETTING_GetValue(SETTING_ARRAY_02, 2, SettingValues);
	Settings.outletTemp =				SETTING_GetValue(SETTING_ARRAY_02, 3, SettingValues);
	Settings.outletTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_02, 4, SettingValues);
	Settings.roomTemp =					SETTING_GetValue(SETTING_ARRAY_02, 5, SettingValues);
	Settings.roomTempHysteresis =		SETTING_GetValue(SETTING_ARRAY_02, 6, SettingValues);
	Settings.humidityLowerThreshold =	SETTING_GetValue(SETTING_ARRAY_02, 7, SettingValues);
	Settings.humidityUpperThreshold =	SETTING_GetValue(SETTING_ARRAY_02, 8, SettingValues);
	Settings.humidityCorrectionTemp =	SETTING_GetValue(SETTING_ARRAY_02, 9, SettingValues);

	Settings.regulatorType = SETTING_GetValue(SETTING_ARRAY_01, 3, SettingValues);
	Settings.Kp =	SETTING_GetValue(SETTING_ARRAY_01, 4, SettingValues);
	Settings.Ki =	SETTING_GetValue(SETTING_ARRAY_01, 5, SettingValues);
	Settings.Kd =	SETTING_GetValue(SETTING_ARRAY_01, 6, SettingValues);

	/* Regulation process */
	REGULATOR_Regulate(Status, &Data, &Settings);
}
