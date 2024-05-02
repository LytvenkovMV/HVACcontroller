
#include "setting.h"
#include "sensor.h"
#include "output.h"
#include "message.h"
#include "heating.h"



#ifndef __regulator_h
#define __regulator_h

/* Regulator state */
typedef enum
{
	REGULATOR_FAIL,
	REGULATOR_OK
} REGULATOR_State;

/* Regulator output command */
typedef enum
{
	REGULATOR_NO_CMD,
	REGULATOR_TURN_OFF_CMD,
	REGULATOR_TURN_ON_CMD
} REGULATOR_OutputCommand;

/* PID regulator data */
typedef struct
{
	int16_t uk;			// u(k)
	int16_t uk_1;		// u(k-1)
	int16_t ek;			// e(k)
	int16_t ek_1;		// e(k-1)
	int16_t ek_2;		// e(k-2)
} REGULATOR_PIDdata;

/* Regulator status */
typedef struct
{
	REGULATOR_State State;
	REGULATOR_PIDdata PIDdata;
	REGULATOR_OutputCommand OutputCommand;
} REGULATOR_Status;

/* Regulator sensors data */
typedef struct
{
	SENSOR_Status RoomTempSensorStatus;
	SENSOR_Status RoomHumidSensorStatus;
	SENSOR_Status OutletTempSensorStatus;
	int16_t roomCurrTemp;
	int16_t roomCurrHumidity;
	int16_t outletCurrTemp;
} REGULATOR_SensorsData;

/* Regulator settings */
typedef struct
{
	int16_t parameterForRegulation;
	int16_t humidityCorrectionCtrl;
	int16_t roomTemp;
	int16_t roomTempHysteresis;
	int16_t outletTemp;
	int16_t outletTempHysteresis;
	int16_t humidityLowerThreshold;
	int16_t humidityUpperThreshold;
	int16_t humidityCorrectionTemp;
	int16_t regulatorType;
	int16_t Kp;
	int16_t Ki;
	int16_t Kd;
} REGULATOR_Settings;

/* Initialize regulator */
void REGULATOR_Init(REGULATOR_Status *Status);

/* Heating regulation process */
void REGULATOR_Heating(REGULATOR_Status *Status, HEATING_Mode Mode, SETTING_Values *SettingValues, SENSOR_Values *SensorValues);

/* Ventilation regulation process */
void REGULATOR_Ventilation(REGULATOR_Status *Status, SETTING_Values *SettingValues, SENSOR_Values *SensorValues);

#endif /* __regulator_h */

/* end of regulator.h */
