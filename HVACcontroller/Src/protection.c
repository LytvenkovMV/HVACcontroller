
#include "protection.h"



PROTECTION_State PROTECTION_OverTemp(int16_t currTemp, int16_t upperLimit)
{
	/* Compare current temperature and limit */
	if (currTemp >= upperLimit) return PROTECTION_TRIPPED;
	
	return PROTECTION_RELEASED;
}



PROTECTION_State PROTECTION_FastTempRise(int16_t currTemp, int16_t prevTemp, int16_t riseUpperLimit, uint16_t minuteCoeff)
{
	uint16_t currTempRise;
	
	/* Check the temperature are rising */
	if (currTemp > prevTemp)
	{	
		/* Calculate current temperature rise during the heating protection period */
		currTempRise = currTemp - prevTemp;
		
		/* Calculate current temperature rise during one minute */
		currTempRise = currTempRise * minuteCoeff;
		
		/* Compare current temperature rise and rise upper limit */
		if (currTempRise >= riseUpperLimit) return PROTECTION_TRIPPED;
	}
	
	return PROTECTION_RELEASED;
}



PROTECTION_State PROTECTION_DiffTemp(int16_t inletTemp, int16_t outletTemp, int16_t lowerLimit)
{	
	uint16_t diffTemp;

	/* Check the outlet temperature are bigger than inlet  */
	if (outletTemp > inletTemp)
	{	
		/* Calculate temperature difference */
		diffTemp = outletTemp - inletTemp;
		
		/* Compare temperature difference and lower limit */
		if (diffTemp <= lowerLimit) return PROTECTION_TRIPPED;
	}
	
	return PROTECTION_RELEASED;
}



PROTECTION_TempProtResult PROTECTION_TempProtection(PROTECTION_SensorsData *Data, PROTECTION_Settings *Settings, uint16_t const protPeriodMs, uint16_t *callsCnt)
{
	PROTECTION_State State;
	uint16_t minuteCoeff;
	uint16_t callsNumber;
	
	/* Calculate coefficient for calculation of the rise during one minute */
	minuteCoeff = 60000 / protPeriodMs;
	
	/* Outlet temperature protection */
	/* Check the protection is on */
	if ((Settings->outletTempCtrl) == 1)
	{
		/* Check the sensor is OK */
		if (Data->OutletSensorStatus != SENSOR_OK) return PROTECTION_SENSOR_FAIL;
		
		/* Overtemp protection */
		State = PROTECTION_OverTemp(Data->outletCurrTemp, Settings->outletTempUpperLimit);
		if (State != PROTECTION_RELEASED) return PROTECTION_OUTLET_OVERTEMP;
		
		/* Fast temperature rise protection */
		State = PROTECTION_FastTempRise(Data->outletCurrTemp, Data->outletPrevTemp, Settings->outletTempRiseUpperLimit, minuteCoeff);
		if (State != PROTECTION_RELEASED) return PROTECTION_OUTLET_FAST_TEMP_RISE;
	}
	
	/* Difference temperature protection */
	/* Check the protection is on */
	if ((Settings->diffTempCtrl) == 1)
	{
		/* Check the sensor is OK */
		if (Data->OutletSensorStatus != SENSOR_OK) return PROTECTION_SENSOR_FAIL;
		if (Data->InletSensorStatus != SENSOR_OK) return PROTECTION_SENSOR_FAIL;
		
		/* Calculate the number of function calls that are needed to provide the delay */
		callsNumber = Settings->inoutDiffTempDelay * 60000 / protPeriodMs;
		
		/* If delay has elapsed start difftemp protection */
		if ((*callsCnt) >= callsNumber)
		{
			State = PROTECTION_DiffTemp(Data->inletCurrTemp, Data->outletCurrTemp, Settings->inoutDiffTempLowerLimit);
			if (State != PROTECTION_RELEASED) return PROTECTION_IN_OUT_MIN_DIFFTEMP;
		}
		else (*callsCnt)++;
	}
	
	return PROTECTION_TEMPERATURE_OK;
}



PROTECTION_ExternalProtResult PROTECTION_ExternalProtection(int16_t contactSetting, osSemaphoreId *ExternInterruptSemHandle)
{
	portBASE_TYPE xSemStatus = pdPASS;
	PROTECTION_ExternalProtContactType ContactType = PROTECTION_NORMALLY_CLOSED_CONTACT;
	INPUT_State InputState = INPUT_RESET;

	/* Get contact type */
	if (contactSetting == 1) ContactType = PROTECTION_NORMALLY_OPEN_CONTACT;

	/* Get contact state */
	InputState = INPUT_GetProtectionState();

	switch (ContactType)
	{
	case PROTECTION_NORMALLY_OPEN_CONTACT:

		/* Configure external interrupt with rising edge */
		INPUT_ConfigureExternalInterrupt(INPUT_WITH_RISING_EDGE);

		/* Check the protection input state */
		if (InputState == INPUT_SET) return PROTECTION_EXTERNAL_ACTIVE;

		break;

	default:

		/* Configure external interrupt with falling edge */
		INPUT_ConfigureExternalInterrupt(INPUT_WITH_FALLING_EDGE);

		/* Check the protection input state */
		if (InputState == INPUT_RESET) return PROTECTION_EXTERNAL_ACTIVE;
	}

	/* Try to take semaphore */
	xSemStatus = xSemaphoreTake(ExternInterruptSemHandle, 0);

	/* If success, this means that the external protection active */
	if (xSemStatus == pdPASS) return PROTECTION_EXTERNAL_ACTIVE;

	return PROTECTION_EXTERNAL_NOT_ACTIVE;
}



PROTECTION_State PROTECTION_Heating(MESSAGE_ID *MessageID, SETTING_Values *SettingValues, SENSOR_Values *SensorCurrValues, SENSOR_Values *SensorPrevValues, uint16_t const protPeriodMs, uint16_t *callsCnt)
{
	PROTECTION_SensorsData Data;
	PROTECTION_Settings Settings;
	PROTECTION_TempProtResult TempProtResult;

	/* Fill in sensors data */
	/* Sensor statuses */
	Data.OutletSensorStatus =	SensorCurrValues->HeatingOutletTemp.Status;
	Data.InletSensorStatus =	SensorCurrValues->HeatingInletTemp.Status;
	/* Current values */
	Data.outletCurrTemp =	SensorCurrValues->HeatingOutletTemp.Value;
	Data.inletCurrTemp =	SensorCurrValues->HeatingInletTemp.Value;
	/* Previous values */
	Data.outletPrevTemp = SensorPrevValues->HeatingOutletTemp.Value;
	
	/* Fill in settings */
	/* Temperature control on/off settings*/
	Settings.outletTempCtrl =	SETTING_GetValue(SETTING_ARRAY_17, 1, SettingValues);
	Settings.diffTempCtrl =		SETTING_GetValue(SETTING_ARRAY_17, 2, SettingValues);
	/* Temperature upper limit */
	Settings.outletTempUpperLimit = SETTING_GetValue(SETTING_ARRAY_17, 3, SettingValues);
	/* Temperature rise upper limit */
	Settings.outletTempRiseUpperLimit = SETTING_GetValue(SETTING_ARRAY_17, 4, SettingValues);
	/* Difftemperature lower limit */
	Settings.inoutDiffTempLowerLimit =	SETTING_GetValue(SETTING_ARRAY_17, 5, SettingValues);
	/* Difftemperature protection delay in minutes */
	Settings.inoutDiffTempDelay =	SETTING_GetValue(SETTING_ARRAY_17, 6, SettingValues);
	
	/* Temperature protection process */
	TempProtResult = PROTECTION_TempProtection(&Data, &Settings, protPeriodMs, callsCnt);
	
	/* Check the result of the process */
	if (TempProtResult != PROTECTION_TEMPERATURE_OK)
	{
		switch (TempProtResult)
		{
			case PROTECTION_OUTLET_OVERTEMP:				*MessageID = MESSAGE_01; break;
			case PROTECTION_OUTLET_FAST_TEMP_RISE:			*MessageID = MESSAGE_02; break;
			case PROTECTION_IN_OUT_MIN_DIFFTEMP:			*MessageID = MESSAGE_03; break;
			case PROTECTION_SENSOR_FAIL:					*MessageID = MESSAGE_04; break;
			default:;
		}
		return PROTECTION_TRIPPED;
	}
	
	return PROTECTION_RELEASED;
}



PROTECTION_State PROTECTION_Ventilation(MESSAGE_ID *MessageID, SETTING_Values *SettingValues, SENSOR_Values *SensorCurrValues, SENSOR_Values *SensorPrevValues, uint16_t const protPeriodMs, uint16_t *callsCnt, osSemaphoreId *ExternInterruptSemHandle)
{
	PROTECTION_SensorsData Data;
	PROTECTION_Settings Settings;
	PROTECTION_ExternalProtResult ExProtResult = PROTECTION_EXTERNAL_ACTIVE;
	PROTECTION_TempProtResult TempProtResult = PROTECTION_OUTLET_OVERTEMP;
	int16_t contactSetting;

	/* Fill in sensors data */
	/* Sensor statuses */
	Data.OutletSensorStatus =	SensorCurrValues->VentOutletTemp.Status;
	Data.InletSensorStatus =	SensorCurrValues->VentInletTemp.Status;
	/* Current values */
	Data.outletCurrTemp =	SensorCurrValues->VentOutletTemp.Value;
	Data.inletCurrTemp =	SensorCurrValues->VentInletTemp.Value;
	/* Previous values */
	Data.outletPrevTemp = SensorPrevValues->VentOutletTemp.Value;
	
	/* Fill in settings */
	/* Contact type setting */
	contactSetting = SETTING_GetValue(SETTING_ARRAY_04, 7, SettingValues);
	/* Temperature control on/off settings*/
	Settings.outletTempCtrl =	SETTING_GetValue(SETTING_ARRAY_04, 1, SettingValues);
	Settings.diffTempCtrl =		SETTING_GetValue(SETTING_ARRAY_04, 2, SettingValues);
	/* Temperature upper limit */
	Settings.outletTempUpperLimit = SETTING_GetValue(SETTING_ARRAY_04, 3, SettingValues);
	/* Temperature rise upper limit */
	Settings.outletTempRiseUpperLimit = SETTING_GetValue(SETTING_ARRAY_04, 4, SettingValues);
	/* Difftemperature lower limit */
	Settings.inoutDiffTempLowerLimit =	SETTING_GetValue(SETTING_ARRAY_04, 5, SettingValues);
	/* Difftemperature protection delay in minutes */
	Settings.inoutDiffTempDelay =	SETTING_GetValue(SETTING_ARRAY_04, 6, SettingValues);
	
	/* External protection process */
	ExProtResult = PROTECTION_ExternalProtection(contactSetting, ExternInterruptSemHandle);

	/* Check the result of the process */
	if (ExProtResult != PROTECTION_EXTERNAL_NOT_ACTIVE)
	{
		*MessageID = MESSAGE_14;
		return PROTECTION_TRIPPED;
	}

	/* Temperature protection process */
	TempProtResult = PROTECTION_TempProtection(&Data, &Settings, protPeriodMs, callsCnt);
	
	/* Check the result of the process */
	if (TempProtResult != PROTECTION_TEMPERATURE_OK)
	{
		switch (TempProtResult)
		{
			case PROTECTION_OUTLET_OVERTEMP:				*MessageID = MESSAGE_10; break;
			case PROTECTION_OUTLET_FAST_TEMP_RISE:			*MessageID = MESSAGE_11; break;
			case PROTECTION_IN_OUT_MIN_DIFFTEMP:			*MessageID = MESSAGE_12; break;
			case PROTECTION_SENSOR_FAIL:					*MessageID = MESSAGE_13; break;
			default:;
		}
		return PROTECTION_TRIPPED;
	}
	
	return PROTECTION_RELEASED;
}
