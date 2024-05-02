
#include "cmsis_os.h"
#include "command.h"
#include "setting.h"
#include "output.h"
#include "led.h"
#include "intvent.h"



#ifndef __exvent_h
#define __exvent_h

/* Ventilation mode */
typedef enum
{
	EXVENT_OFF,
	EXVENT_ON
} EXVENT_Mode;

/* Ventilation overall state */
typedef struct
{
	EXVENT_Mode CurrMode;
	EXVENT_Mode PrevMode;
	EXVENT_Mode TargetMode;
} EXVENT_State;

/* Initialize ventilation state */
void EXVENT_InitState(EXVENT_State *VentState);

/* Update ventilation mode */
void EXVENT_UpdateMode(EXVENT_State *ExVentState, INTVENT_State IntVentState, SETTING_Values *SettingValues, osMessageQId *ExVentCmdQH);

/* Turn on ventilation */
void EXVENT_TurnOn(osMessageQId *LedQueueHandle);

/* Turn off ventilation */
void EXVENT_TurnOff(osMessageQId *LedQueueHandle);

#endif /* __exvent_h */

/* end of exvent.h */
