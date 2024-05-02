
#include "intvent.h"



void INTVENT_InitState(INTVENT_State *VentState)
{
	VentState->ProcessState = INTVENT_OK;
	VentState->UpdatingStatus = INTVENT_SENSOR_UPDATING_FAIL;
	VentState->CurrMode = INTVENT_OFF;
	VentState->PrevMode = INTVENT_OFF;
	VentState->TargetMode = INTVENT_OFF;
	VentState->FanState = INTVENT_FAN_OFF;
	VentState->CoolingRequest = INTVENT_COOLING_NOT_REQUIRED;
	VentState->AutoCtrlPermission = INTVENT_AUTOCTRL_ALLOWED;
	VentState->AutoCtrlTime = INTVENT_TIME_TO_IDLE;
}



INTVENT_UpdatingStatus INTVENT_UpdateData(MESSAGE_ID *MessageID, SENSOR_Values *SensorValues, SETTING_Values *SettingValues, osMessageQId *SensorsQH, osMessageQId *SettingValuesQH, uint16_t *callsCnt)
{
	portBASE_TYPE xSensorStatus = pdFAIL, xSettingStatus = pdFAIL;
	
	/* Update sensor values */
	xSensorStatus = xQueuePeek(SensorsQH, SensorValues, 0);

	if (xSensorStatus != pdPASS)
	{
		*MessageID = MESSAGE_23;
		return INTVENT_SENSOR_UPDATING_FAIL;
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
			*MessageID = MESSAGE_24;
			return INTVENT_SETTING_UPDATING_FAIL;
		}
	}
	else (*callsCnt)--;
	
	return INTVENT_UPDATING_OK;
}



INTVENT_Mode INTVENT_GetManualTargetMode(INTVENT_State *VentState, osMessageQId *CmdQueueHandle)
{
	portBASE_TYPE xStatus;
	COMMAND_IntVentCommand Command;
	INTVENT_Mode CurrMode, TargetMode;

	/* Initialize current and target modes */
	CurrMode = VentState->CurrMode;
	TargetMode = CurrMode;

	/* Check for a new command from the buttons */
	xStatus = xQueueReceive(CmdQueueHandle, &Command, 0);

	/* If a new command is present change target mode */
	if (xStatus == pdPASS)
	{
		switch (Command)
		{
			case COMMAND_INT_VENT_TURN_OFF:
			{
				/* If current mode is ON_WITH_HEAT, set cooling request */
				if (CurrMode == INTVENT_ON_WITH_HEAT) VentState->CoolingRequest = INTVENT_COOLING_REQUIRED;

				TargetMode = INTVENT_OFF;
			}
			break;

			case COMMAND_INT_VENT_TURN_ON_WO_HEAT: TargetMode = INTVENT_ON; break;

			case COMMAND_INT_VENT_TURN_ON_W_HEAT: TargetMode = INTVENT_ON_WITH_HEAT; break;

			default:;
		}
	}

	return TargetMode;
}



INTVENT_AutoCtrlTime INTVENT_GetAutoCtrlTime(SETTING_Values *SettingValues, RTC_HandleTypeDef *HandleRTC)
{
	RTC_TimeTypeDef Time;
	INTVENT_AutoCtrlTime AutoCtrlTime = INTVENT_TIME_TO_IDLE;
	int16_t turningOnHour1 = 0, turningOnHour2 = 0, turningOnHour3 = 0;
	int16_t workPeriod1 = 0, workPeriod2 = 0, workPeriod3 = 0;
	uint8_t workPeriodHours1 = 0, workPeriodHours2 = 0, workPeriodHours3 = 0;
	uint8_t workPeriodMinutes1 = 0, workPeriodMinutes2 = 0, workPeriodMinutes3 = 0;

	/* Get current time */
	HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);

	/* Get settings */
	turningOnHour1 =  SETTING_GetValue(SETTING_ARRAY_03, 4, SettingValues);
	turningOnHour2 = SETTING_GetValue(SETTING_ARRAY_03, 6, SettingValues);
	turningOnHour3 =  SETTING_GetValue(SETTING_ARRAY_03, 8, SettingValues);

	workPeriod1 =  SETTING_GetValue(SETTING_ARRAY_03, 5, SettingValues);
	workPeriod2 = SETTING_GetValue(SETTING_ARRAY_03, 7, SettingValues);
	workPeriod3 =  SETTING_GetValue(SETTING_ARRAY_03, 9, SettingValues);

	/* Calculate number of hours in the work periods */
	workPeriodHours1 = workPeriod1 / 60;
	workPeriodHours2 = workPeriod2 / 60;
	workPeriodHours3 = workPeriod3 / 60;

	/* Calculate number of minutes in the work periods */
	workPeriodMinutes1 = workPeriod1 % 60;
	workPeriodMinutes2 = workPeriod2 % 60;
	workPeriodMinutes3 = workPeriod3 % 60;

	/* Define is it time to work or is it time to idle now */
	/* If the current time is in the first period of work set isTimeToWork variable */
	if (Time.Hours >= turningOnHour1)
	{
		if (workPeriodMinutes1 != 0)
		{
			if (Time.Hours == (turningOnHour1 + workPeriodHours1))
			{
				if (Time.Minutes < workPeriodMinutes1) AutoCtrlTime = INTVENT_TIME_TO_WORK;
			}
			else if (Time.Hours < (turningOnHour1 + workPeriodHours1)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
		else if (workPeriodHours1 != 0)
		{
			if (Time.Hours < (turningOnHour1 + workPeriodHours1)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
	}

	/* If the current time is in the second period of work set isTimeToWork variable */
	if (Time.Hours >= turningOnHour2)
	{
		if (workPeriodMinutes2 != 0)
		{
			if (Time.Hours == (turningOnHour2 + workPeriodHours2))
			{
				if (Time.Minutes < workPeriodMinutes2) AutoCtrlTime = INTVENT_TIME_TO_WORK;
			}
			else if (Time.Hours < (turningOnHour2 + workPeriodHours2)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
		else if (workPeriodHours2 != 0)
		{
			if (Time.Hours < (turningOnHour2 + workPeriodHours2)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
	}

	/* If the current time is in the third period of work set isTimeToWork variable */
	if (Time.Hours >= turningOnHour3)
	{
		if (workPeriodMinutes3 != 0)
		{
			if (Time.Hours == (turningOnHour3 + workPeriodHours3))
			{
				if (Time.Minutes < workPeriodMinutes3) AutoCtrlTime = INTVENT_TIME_TO_WORK;
			}
			else if (Time.Hours < (turningOnHour3 + workPeriodHours3)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
		else if (workPeriodHours3 != 0)
		{
			if (Time.Hours < (turningOnHour3 + workPeriodHours3)) AutoCtrlTime = INTVENT_TIME_TO_WORK;
		}
	}

	return AutoCtrlTime;
}



INTVENT_Mode INTVENT_GetAutoTargetMode(INTVENT_State *VentState, SETTING_Values *SettingValues)
{
	INTVENT_Mode CurrMode, TargetMode;
	int16_t ventAutoCtrlSetting = 0, heatAutoCtrlSetting = 0;

	/* Initialize current and target modes */
	CurrMode = VentState->CurrMode;
	TargetMode = CurrMode;

	/* Get auto control setting */
	ventAutoCtrlSetting = SETTING_GetValue(SETTING_ARRAY_03, 1, SettingValues);

	/* If auto control is on */
	if (ventAutoCtrlSetting == 1)
	{
		/* Get heater auto control setting */
		heatAutoCtrlSetting = SETTING_GetValue(SETTING_ARRAY_03, 2, SettingValues);

		switch (VentState->AutoCtrlTime)
		{
			/* Case time to idle */
			case INTVENT_TIME_TO_IDLE:
			{
				/* If current mode is ON_WITH_HEAT, set cooling request */
				if (CurrMode == INTVENT_ON_WITH_HEAT) VentState->CoolingRequest = INTVENT_COOLING_REQUIRED;

				TargetMode = INTVENT_OFF;
			}
			break;

			/* Case time to work */
			case INTVENT_TIME_TO_WORK:
			{
				/* If air heater auto control is on, turn on ventilation with heat */
				if (heatAutoCtrlSetting == 1) TargetMode = INTVENT_ON_WITH_HEAT;
				/* Else turn on ventilation without heat */
				else TargetMode = INTVENT_ON;
			}
			break;

			default:;
		}
	}

	return TargetMode;
}



void INTVENT_UpdateMode(INTVENT_State *VentState, SETTING_Values *SettingValues, osMessageQId *IntVentCmdQueueHandle, RTC_HandleTypeDef *HandleRTC)
{	
	INTVENT_Mode ManualTargetMode = INTVENT_OFF, AutoTargetMode = INTVENT_OFF;

	/* Calculate manual target mode */
	ManualTargetMode = INTVENT_GetManualTargetMode(VentState, IntVentCmdQueueHandle);

	/* If manual target mode isn't equal to current mode, update current mode */
	if (ManualTargetMode != VentState->CurrMode)
	{
		VentState->CurrMode = ManualTargetMode;
	}
	/* Else update the current mode by the auto control */
	else
	{
		/* Calculate auto target mode */
		AutoTargetMode = INTVENT_GetAutoTargetMode(VentState, SettingValues);

		/* If target mode changed, update current mode */
		if (AutoTargetMode != VentState->TargetMode)
		{
			VentState->CurrMode = AutoTargetMode;
		}

		/* Save target mode to use it in the next cycle */
		VentState->TargetMode = AutoTargetMode;
	}
}



void INTVENT_TurnOnFan()
{
	OUTPUT_ChangeState(OUTPUT_INTAKE_VENT, OUTPUT_ON);
}



void INTVENT_TurnOffFan(void)
{
	OUTPUT_ChangeState(OUTPUT_INTAKE_VENT, OUTPUT_OFF);
}



void INTVENT_TurnOnHeaters(SETTING_Values *SettingValues)
{	
	int16_t usedHeaterSetting;
	
	/* Check used heater setting */
	usedHeaterSetting = SETTING_GetValue(SETTING_ARRAY_01, 1, SettingValues);
	switch (usedHeaterSetting)
	{
		case 0: OUTPUT_ChangeState(OUTPUT_AIR_HEATER_1, OUTPUT_ON); break;
		case 1: OUTPUT_ChangeState(OUTPUT_AIR_HEATER_2, OUTPUT_ON); break;
		default:
		{
			OUTPUT_ChangeState(OUTPUT_AIR_HEATER_1, OUTPUT_ON);
			osDelay(30);
			OUTPUT_ChangeState(OUTPUT_AIR_HEATER_2, OUTPUT_ON);
		}
	}
}



void INTVENT_TurnOffHeaters(void)
{
	OUTPUT_ChangeState(OUTPUT_AIR_HEATER_1, OUTPUT_OFF);
	osDelay(20);
	OUTPUT_ChangeState(OUTPUT_AIR_HEATER_2, OUTPUT_OFF);
}



void INTVENT_TurnOffHeatersFromIRQ(void)
{
	OUTPUT_ChangeState(OUTPUT_AIR_HEATER_1, OUTPUT_OFF);
	OUTPUT_ChangeState(OUTPUT_AIR_HEATER_2, OUTPUT_OFF);
}



void INTVENT_TurnOn(SETTING_Values *SettingValues, osMessageQId *LedQueueHandle)
{
	INTVENT_TurnOnFan();
	LED_SendQuery(LED2, LED_ON, LedQueueHandle, 100);
}



void INTVENT_TurnOff(osMessageQId *LedQueueHandle)
{
	INTVENT_TurnOffHeaters();
	LED_SendQuery(LED2, LED_OFF, LedQueueHandle, 100);
}



void INTVENT_Trip(INTVENT_State *VentState, osMessageQId *LedQueueHandle)
{
	VentState->ProcessState = INTVENT_FAIL;
	INTVENT_TurnOff(LedQueueHandle);
	VentState->CoolingRequest = INTVENT_COOLING_REQUIRED;
	VentState->CurrMode = INTVENT_OFF;
	VentState->AutoCtrlPermission = INTVENT_AUTOCTRL_DENIED;
	LED_SendQuery(LED5, LED_ON, LedQueueHandle, 100);
}



INTVENT_CoolingState INTVENT_GetCoolingState(SETTING_Values *SettingValues, uint16_t *callsCnt, uint16_t const VentPeriodMs)
{
	int16_t coolingTimeSetting;
	uint16_t callsNumber;
	
	/* Get setting */
	coolingTimeSetting = SETTING_GetValue(SETTING_ARRAY_01, 2, SettingValues);
	
	/* Calculate the number of function calls that are needed to provide the delay */
	callsNumber = coolingTimeSetting * 60000 / VentPeriodMs;
	
	if ((*callsCnt) >= callsNumber)
	{
		*callsCnt = 0;
		return INTVENT_COOLING_COMPLETE;
	}
	else (*callsCnt)++;
	
	return INTVENT_COOLING_NOT_COMPLETE;
}



void INTVENT_Reset(INTVENT_State *VentState, osMessageQId *VentResetQueueHandle, osMessageQId *LedQueueHandle)
{
	portBASE_TYPE xStatus;
	uint16_t temp;
	
	xStatus = xQueueReceive(VentResetQueueHandle, &temp, 0);
	if (xStatus == pdPASS)
	{
		VentState->ProcessState = INTVENT_OK;
		VentState->AutoCtrlPermission = INTVENT_AUTOCTRL_ALLOWED;
		LED_SendQuery(LED5, LED_OFF, LedQueueHandle, 100);
	}
}
