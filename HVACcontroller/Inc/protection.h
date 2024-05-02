
#include "setting.h"
#include "sensor.h"
#include "input.h"
#include "message.h"



#ifndef __protection_h
#define __protection_h

/* Protection state */
typedef enum
{
	PROTECTION_RELEASED,
	PROTECTION_TRIPPED
} PROTECTION_State;

/* External protection contact type */
typedef enum
{
	PROTECTION_NORMALLY_CLOSED_CONTACT,
	PROTECTION_NORMALLY_OPEN_CONTACT
} PROTECTION_ExternalProtContactType;

/* External protection result */
typedef enum
{
	PROTECTION_EXTERNAL_ACTIVE,
	PROTECTION_EXTERNAL_NOT_ACTIVE
} PROTECTION_ExternalProtResult;

/* Temperature protection result */
typedef enum
{
	PROTECTION_TEMPERATURE_OK,
	PROTECTION_SENSOR_FAIL,
	PROTECTION_OUTLET_OVERTEMP,
	PROTECTION_OUTLET_FAST_TEMP_RISE,
	PROTECTION_IN_OUT_MIN_DIFFTEMP
} PROTECTION_TempProtResult;

/* Sensors data */
typedef struct
{
	SENSOR_Status OutletSensorStatus;
	SENSOR_Status InletSensorStatus;
	int16_t outletCurrTemp;
	int16_t outletPrevTemp;
	int16_t inletCurrTemp;
} PROTECTION_SensorsData;

/* Settings */
typedef struct
{
	int16_t outletTempCtrl;
	int16_t diffTempCtrl;
	int16_t outletTempUpperLimit;
	int16_t outletTempRiseUpperLimit;
	int16_t inoutDiffTempLowerLimit;
	int16_t inoutDiffTempDelay;
} PROTECTION_Settings;

/* Heating protection process */
PROTECTION_State PROTECTION_Heating(MESSAGE_ID *MessageID, SETTING_Values *SettingValues, SENSOR_Values *SensorCurrValues, SENSOR_Values *SensorPrevValues, uint16_t const protPeriodMs, uint16_t *callsCnt);

/* Ventilation protection process */
PROTECTION_State PROTECTION_Ventilation(MESSAGE_ID *MessageID, SETTING_Values *SettingValues, SENSOR_Values *SensorCurrValues, SENSOR_Values *SensorPrevValues, uint16_t const protPeriodMs, uint16_t *callsCnt, osSemaphoreId *ExternInterruptSemHandle);

#endif /* __protection_h */

/* end of protection.h */
