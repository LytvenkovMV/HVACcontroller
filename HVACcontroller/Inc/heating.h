
#include "cmsis_os.h"
#include "command.h"
#include "setting.h"
#include "sensor.h"
#include "output.h"
#include "led.h"
#include "message.h"



#ifndef __heating_h
#define __heating_h

/* Heating updating status */
typedef enum
{
	HEATING_UPDATING_FAIL,
	HEATING_UPDATING_OK
} HEATING_UpdatingStatus;

/* Heating cooling state */
typedef enum
{
	HEATING_COOLING_NOT_COMPLETE,
	HEATING_COOLING_COMPLETE
} HEATING_CoolingState;

/* Heating process state */
typedef enum
{
	HEATING_FAIL,
	HEATING_OK
} HEATING_ProcessState;

/* Heating plan */
typedef enum
{
	HEATING_MANUAL,
	HEATING_AUTOMATIC
} HEATING_Plan;

/* Heating mode */
typedef enum
{
	HEATING_OFF,
	HEATING_COOLING,
	HEATING_COMFORT,
	HEATING_ECO,
	HEATING_FRZ
} HEATING_Mode;

/* Heating overall state */
typedef struct
{
	HEATING_ProcessState ProcessState;
	HEATING_Mode CurrMode;
	HEATING_Mode PrevMode;
	HEATING_Plan Plan;
} HEATING_State;

/* Init heating state */
void HEATING_InitState(HEATING_State *HeatingState);

/* Update sensor values and setting values */
HEATING_UpdatingStatus HEATING_UpdateData(MESSAGE_ID *MessageID, SENSOR_Values *SensorValues, SETTING_Values *SettingValues, osMessageQId *SensorsQH, osMessageQId *SettingValuesQH, uint16_t *callsCnt);

/* Update heating mode */
void HEATING_UpdateMode(HEATING_State *HeatingState, SETTING_Values *SettingValues, osMessageQId *HeatingCmdQueueHandle, RTC_HandleTypeDef *HandleRTC);
																					
/* Turn on heaters */
void HEATING_TurnOnHeaters(SETTING_Values *SettingValues);

/* Turn off heaters */
void HEATING_TurnOffHeaters(void);

/* Turn on heating */
void HEATING_TurnOn(SETTING_Values *SettingValues, osMessageQId *LedQueueHandle);

/* Turn off heating */
void HEATING_TurnOff(osMessageQId *LedQueueHandle);

/* Emergency trip heating */
void HEATING_Trip(HEATING_State *HeatingState, osMessageQId *LedQueueHandle);

/* Cool down heating */
HEATING_CoolingState HEATING_CoolDown(SETTING_Values *SettingValues, uint16_t *coolingCnt, uint16_t const HeatingPeriodMs);

/* Reset heating after emergency tripping */
void HEATING_Reset(HEATING_State *HeatingState, osMessageQId *HeatingResetQueueHandle, osMessageQId *LedQueueHandle);

#endif /* __heating_h */

/* end of heating.h */
