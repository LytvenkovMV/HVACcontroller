
#include "cmsis_os.h"
#include "command.h"
#include "setting.h"
#include "sensor.h"
#include "output.h"
#include "led.h"
#include "message.h"



#ifndef __intvent_h
#define __intvent_h

/* Ventilation updating status */
typedef enum
{
	INTVENT_SENSOR_UPDATING_FAIL,
	INTVENT_SETTING_UPDATING_FAIL,
	INTVENT_UPDATING_OK
} INTVENT_UpdatingStatus;

/* Fan state */
typedef enum
{
	INTVENT_FAN_OFF,
	INTVENT_FAN_ON
} INTVENT_FanState;

/* Heaters cooling request */
typedef enum
{
	INTVENT_COOLING_REQUIRED,
	INTVENT_COOLING_NOT_REQUIRED
} INTVENT_CoolingRequest;

/* Ventilation cooling state */
typedef enum
{
	INTVENT_COOLING_NOT_COMPLETE,
	INTVENT_COOLING_COMPLETE
} INTVENT_CoolingState;

/* Ventilation process state */
typedef enum
{
	INTVENT_FAIL,
	INTVENT_OK
} INTVENT_ProcessState;

/* Ventilation auto control permission */
typedef enum
{
	INTVENT_AUTOCTRL_DENIED,
	INTVENT_AUTOCTRL_ALLOWED
} INTVENT_AutoCtrlPermission;

/* Ventilation auto control time */
typedef enum
{
	INTVENT_TIME_TO_IDLE,
	INTVENT_TIME_TO_WORK
} INTVENT_AutoCtrlTime;

/* Ventilation mode */
typedef enum
{
	INTVENT_OFF,
	INTVENT_ON,
	INTVENT_ON_WITH_HEAT
} INTVENT_Mode;

/* Ventilation overall state */
typedef struct
{
	INTVENT_ProcessState ProcessState;
	INTVENT_UpdatingStatus UpdatingStatus;
	INTVENT_Mode CurrMode;
	INTVENT_Mode PrevMode;
	INTVENT_Mode TargetMode;
	INTVENT_FanState FanState;
	INTVENT_CoolingRequest CoolingRequest;
	INTVENT_AutoCtrlPermission AutoCtrlPermission;
	INTVENT_AutoCtrlTime AutoCtrlTime;
} INTVENT_State;

/* Initialize ventilation state */
void INTVENT_InitState(INTVENT_State *VentState);

/* Update sensor values and setting values */
INTVENT_UpdatingStatus INTVENT_UpdateData(MESSAGE_ID *MessageID, SENSOR_Values *SensorValues, SETTING_Values *SettingValues, osMessageQId *SensorsQH, osMessageQId *SettingValuesQH, uint16_t *callsCnt);

/* Determine is it time to work or is it time to idle now */
INTVENT_AutoCtrlTime INTVENT_GetAutoCtrlTime(SETTING_Values *SettingValues, RTC_HandleTypeDef *HandleRTC);

/* Update ventilation mode */
void INTVENT_UpdateMode(INTVENT_State *VentState, SETTING_Values *SettingValues, osMessageQId *VentCmdQueueHandle, RTC_HandleTypeDef *HandleRTC);
																					
/* Turn off fan */
void INTVENT_TurnOffFan(void);

/* Turn on heaters */
void INTVENT_TurnOnHeaters(SETTING_Values *SettingValues);

/* Turn off heaters */
void INTVENT_TurnOffHeaters(void);

/* Turn off heaters from IRQ */
void INTVENT_TurnOffHeatersFromIRQ(void);

/* Turn on ventilation */
void INTVENT_TurnOn(SETTING_Values *SettingValues, osMessageQId *LedQueueHandle);

/* Turn off ventilation */
void INTVENT_TurnOff(osMessageQId *LedQueueHandle);

/* Emergency trip ventilation */
void INTVENT_Trip(INTVENT_State *VentState, osMessageQId *LedQueueHandle);

/* Get cooling state */
INTVENT_CoolingState INTVENT_GetCoolingState(SETTING_Values *SettingValues, uint16_t *coolingCnt, uint16_t const VentPeriodMs);

/* Reset ventilation after emergency tripping */
void INTVENT_Reset(INTVENT_State *VentState, osMessageQId *VentResetQueueHandle, osMessageQId *LedQueueHandle);

#endif /* __intvent_h */

/* end of intvent.h */
