
#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "string.h"
#include "print.h"
#include "pt100.h"
#include "AM2320.h"



#ifndef __sensor_h
#define __sensor_h

/* ADC buffer size. The size must be a power of two. Allowed values: 1, 2, 4, 8, 16 */
#define SENSOR_ADC_BUFFER_SIZE		(16)

/* ADC result limits */
#define SENSOR_ADC_LOWER_LIMIT		(1877)
#define SENSOR_ADC_UPPER_LIMIT		(3961)

/* ADC coefficients
 *
 * @brief Iout - current regulator output current in this channel, mA
 *               This current flows through the RTD sensor
 *
 * @brief Klpf - gain of the active low pass filter
 *
 * @brief Kconv - conversion coefficient (the weight of the LSB)
 *        Kconv = VDDA / (2^Nadc) , where
 *        VDDA - analog power supply, mV
 *        Nadc - ADC resolution, bits
 *
 * @brief Kadc - total ADC coefficient
 *        Kadc = 1mA * 1000000 * Kconv / (Klpf * Iout)
 */
#define SENSOR_ADC_COEFF_1			(40859)
#define SENSOR_ADC_COEFF_2			(40911)
#define SENSOR_ADC_COEFF_3			(41282)
#define SENSOR_ADC_COEFF_4			(41426)

/* Sensor type */
typedef enum
{
	SENSOR_INTEGER_DEGREE,
	SENSOR_1_DECIMAL_DEGREE,
	SENSOR_2_DECIMAL_DEGREE,
	SENSOR_INTEGER_PERCENT,
	SENSOR_1_DECIMAL_PERCENT,
	SENSOR_2_DECIMAL_PERCENT
} SENSOR_Type;

/* Sensor status */
typedef enum
{
	SENSOR_FAIL,
	SENSOR_OK
} SENSOR_Status;

/* Sensor structure */
typedef struct
{
	SENSOR_Status Status;
	int16_t Value;
} SENSOR_Struct;

/* Sensor values */
typedef struct
{
	SENSOR_Struct HeatingInletTemp;
	SENSOR_Struct HeatingOutletTemp;
	SENSOR_Struct VentInletTemp;
	SENSOR_Struct VentOutletTemp;
	SENSOR_Struct RoomTemp;
	SENSOR_Struct RoomHumid;
} SENSOR_Values;

/* ADC values */
typedef struct
{
	uint16_t TSENS4;
	uint16_t TSENS3;
	uint16_t TSENS2;
	uint16_t TSENS1;
} SENSOR_ADCvalues;

/* ADC buffer */
typedef struct
{
	uint16_t BUFFERTSENS4[SENSOR_ADC_BUFFER_SIZE];
	uint16_t BUFFERTSENS3[SENSOR_ADC_BUFFER_SIZE];
	uint16_t BUFFERTSENS2[SENSOR_ADC_BUFFER_SIZE];
	uint16_t BUFFERTSENS1[SENSOR_ADC_BUFFER_SIZE];
} SENSOR_ADCbuffer;

/* Calibrate ADC1 and ADC2 */
void SENSOR_CalibrateADC(ADC_HandleTypeDef *hadc1, ADC_HandleTypeDef *hadc2);

/* Start ADC */
void SENSOR_StartADC(SENSOR_ADCvalues *ADCvalues, ADC_HandleTypeDef *hadc1, ADC_HandleTypeDef *hadc2);

/* Update sensor values */
void SENSOR_UpdateValues(SENSOR_Values *Values, AM2320_State *AM2320State, osMessageQId *RXDataQueueHandle, osMessageQId *ADCvaluesQueueHandle);

/* Get char representation of the sensor value */
void SENSOR_GetCharValue(uint8_t number, SENSOR_Values *Values, char result[12]);

#endif /* __sensor_h */

/* end of sensor.h */
