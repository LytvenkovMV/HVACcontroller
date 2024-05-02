
#include "exvent.h"



void EXVENT_InitState(EXVENT_State *VentState)
{
	VentState->CurrMode = EXVENT_OFF;
	VentState->PrevMode = EXVENT_OFF;
	VentState->TargetMode = EXVENT_OFF;
}



EXVENT_Mode EXVENT_GetManualTargetMode(EXVENT_State *State, osMessageQId *CmdQueueHandle)
{
	portBASE_TYPE xStatus;
	COMMAND_ExVentCommand Command;
	EXVENT_Mode TargetMode;

	/* Initialize target mode */
	TargetMode = State->CurrMode;

	/* Check for a new command from the buttons */
	xStatus = xQueueReceive(CmdQueueHandle, &Command, 0);

	/* If a new command is present change target mode */
	if (xStatus == pdPASS)
	{
		switch (Command)
		{
		case COMMAND_EX_VENT_TURN_OFF: TargetMode = EXVENT_OFF; break;

		case COMMAND_EX_VENT_TURN_ON: TargetMode = EXVENT_ON; break;

		default:;
		}
	}

	return TargetMode;
}



EXVENT_Mode EXVENT_GetAutoTargetMode(EXVENT_State *ExVentState, INTVENT_State IntVentState, SETTING_Values *SettingValues)
{
	EXVENT_Mode TargetMode;
	int16_t ventAutoCtrlSetting;

	/* Initialize target mode */
	TargetMode = ExVentState->CurrMode;

	/* If settings are up to date */
	if (IntVentState.UpdatingStatus != INTVENT_SETTING_UPDATING_FAIL)
	{
		/* Get auto control setting */
		ventAutoCtrlSetting = SETTING_GetValue(SETTING_ARRAY_03, 3, SettingValues);

		/* If auto control is allowed and on, change target mode */
		if (ventAutoCtrlSetting == 1)
		{
			if (IntVentState.AutoCtrlPermission == INTVENT_AUTOCTRL_ALLOWED)
			{
				switch (IntVentState.AutoCtrlTime)
				{
				case INTVENT_TIME_TO_IDLE: TargetMode = EXVENT_OFF; break;

				case INTVENT_TIME_TO_WORK: TargetMode = EXVENT_ON; break;

				default:;
				}
			}
		}
	}

	return TargetMode;
}



void EXVENT_UpdateMode(EXVENT_State *ExVentState, INTVENT_State IntVentState, SETTING_Values *SettingValues, osMessageQId *ExVentCmdQH)
{
	/* Private variables */
	EXVENT_Mode ManualTargetMode = EXVENT_OFF, AutoTargetMode = EXVENT_OFF;

	/* Calculate manual target mode */
	ManualTargetMode = EXVENT_GetManualTargetMode(ExVentState, ExVentCmdQH);

	/* If manual target mode isn't equal to current mode, update current mode */
	if (ManualTargetMode != ExVentState->CurrMode)
	{
		ExVentState->CurrMode = ManualTargetMode;
	}
	/* Else update the current mode by the auto control */
	else
	{
		/* Calculate auto target mode */
		AutoTargetMode = EXVENT_GetAutoTargetMode(ExVentState, IntVentState, SettingValues);

		/* If target mode changed, update current mode */
		if (AutoTargetMode != ExVentState->TargetMode)
		{
			ExVentState->CurrMode = AutoTargetMode;
		}

		/* Save target mode to use it in the next cycle */
		ExVentState->TargetMode = AutoTargetMode;
	}
}



void EXVENT_TurnOn(osMessageQId *LedQueueHandle)
{
	OUTPUT_ChangeState(OUTPUT_EXHAUST_VENT, OUTPUT_ON);
	LED_SendQuery(LED3, LED_ON, LedQueueHandle, 200);
}



void EXVENT_TurnOff(osMessageQId *LedQueueHandle)
{
	OUTPUT_ChangeState(OUTPUT_EXHAUST_VENT, OUTPUT_OFF);
	LED_SendQuery(LED3, LED_OFF, LedQueueHandle, 200);
}
