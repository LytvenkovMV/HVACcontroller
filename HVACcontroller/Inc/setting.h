
#include "stdint.h"
#include "string.h"
#include "stm32f1xx_hal.h"
#include "print.h"



#ifndef __setting_h
#define __setting_h

/* Verification code that is used to determine whether the settings have been saved or not */
#define SETTING_CODE				((uint32_t) 0xABCD0123)

/* Page address in Flash where the settings will be stored (address of the last page) */
#define SETTING_PAGE_ADDRESS		(0x0801FC00)

/* Array addresses */
#define SETTING_ARRAY01_ADDRESS		(SETTING_PAGE_ADDRESS)
#define SETTING_ARRAY02_ADDRESS		(SETTING_PAGE_ADDRESS + 50)
#define SETTING_ARRAY03_ADDRESS		(SETTING_PAGE_ADDRESS + 100)
#define SETTING_ARRAY04_ADDRESS		(SETTING_PAGE_ADDRESS + 150)
#define SETTING_ARRAY05_ADDRESS		(SETTING_PAGE_ADDRESS + 200)
#define SETTING_ARRAY06_ADDRESS		(SETTING_PAGE_ADDRESS + 250)
#define SETTING_ARRAY07_ADDRESS		(SETTING_PAGE_ADDRESS + 300)
#define SETTING_ARRAY08_ADDRESS		(SETTING_PAGE_ADDRESS + 350)
#define SETTING_ARRAY09_ADDRESS		(SETTING_PAGE_ADDRESS + 400)
#define SETTING_ARRAY10_ADDRESS		(SETTING_PAGE_ADDRESS + 450)
#define SETTING_ARRAY11_ADDRESS		(SETTING_PAGE_ADDRESS + 500)
#define SETTING_ARRAY12_ADDRESS		(SETTING_PAGE_ADDRESS + 550)
#define SETTING_ARRAY13_ADDRESS		(SETTING_PAGE_ADDRESS + 600)
#define SETTING_ARRAY14_ADDRESS		(SETTING_PAGE_ADDRESS + 650)
#define SETTING_ARRAY15_ADDRESS		(SETTING_PAGE_ADDRESS + 700)
#define SETTING_ARRAY16_ADDRESS		(SETTING_PAGE_ADDRESS + 750)
#define SETTING_ARRAY17_ADDRESS		(SETTING_PAGE_ADDRESS + 800)
#define SETTING_ARRAY18_ADDRESS		(SETTING_PAGE_ADDRESS + 850)
#define SETTING_ARRAY19_ADDRESS		(SETTING_PAGE_ADDRESS + 900)
#define SETTING_ARRAY20_ADDRESS		(SETTING_PAGE_ADDRESS + 950)

/* Verification code address */
#define SETTING_CODE_ADDRESS		(SETTING_PAGE_ADDRESS + 1000)

/* Setting change mode */
typedef enum
{
	SETTING_INCREASE,
	SETTING_DECREASE,
	SETTING_WRITE_DIRECTLY
} SETTING_ChangeDirection;

/* Setting types */
/* 
   INTEGER_MINUTE:				Converted to char as the integer value of minutes
   INTEGER_HOUR:				Converted to char as the integer value of hours
   INTEGER_DEGREE:				Converted to char as the integer value of degrees
   1_DECIMAL_DEGREE:			Converted to char as the value of degrees with one digit after decimal point
   2_DECIMAL_DEGREE:			Converted to char as the value of degrees with two digits after decimal point
   INTEGER_PERCENT:				Converted to char as the integer value of percents
   1_DECIMAL_PERCENT:			Converted to char as the value of percents with one digit after decimal point
   2_DECIMAL_PERCENT:			Converted to char as the value of percents with two digits after decimal point
   INTEGER_DEGR_PER_MIN:		Converted to char as the integer value of degrees per a minute
   1_DECIMAL_DEGR_PER_MIN:		Converted to char as the value of degrees per a minute with one digit after decimal point
   2_DECIMAL_DEGR_PER_MIN:		Converted to char as the value of degrees per a minute with two digits after decimal point
   INTEGER_UNITLESS:			Converted to char as the integer unitless value
   1_DECIMAL_UNITLESS:			Converted to char as the unitless value with one digit after decimal point
   2_DECIMAL_UNITLESS:			Converted to char as the unitless value with two digits after decimal point
*/
typedef enum
{
	SETTING_INTEGER_MINUTE,
	SETTING_INTEGER_HOUR,
	SETTING_INTEGER_DEGREE,
	SETTING_1_DECIMAL_DEGREE,
	SETTING_2_DECIMAL_DEGREE,
	SETTING_INTEGER_PERCENT,
	SETTING_1_DECIMAL_PERCENT,
	SETTING_2_DECIMAL_PERCENT,
	SETTING_INTEGER_DEGR_PER_MIN,
	SETTING_1_DECIMAL_DEGR_PER_MIN,
	SETTING_2_DECIMAL_DEGR_PER_MIN,
	SETTING_INTEGER_UNITLESS,
	SETTING_1_DECIMAL_UNITLESS,
	SETTING_2_DECIMAL_UNITLESS,
	SETTING_SELECTOR_TYPE_1,
	SETTING_SELECTOR_TYPE_2,
	SETTING_SELECTOR_TYPE_3,
	SETTING_SELECTOR_TYPE_4,
	SETTING_SELECTOR_TYPE_5,
	SETTING_SELECTOR_TYPE_6,
	SETTING_SELECTOR_TYPE_7,
	SETTING_SELECTOR_TYPE_8
} SETTING_Type;

/* Setting array ID */
typedef enum
{
	SETTING_ARRAY_01,
	SETTING_ARRAY_02,
	SETTING_ARRAY_03,
	SETTING_ARRAY_04,
	SETTING_ARRAY_05,
	SETTING_ARRAY_06,
	SETTING_ARRAY_07,
	SETTING_ARRAY_08,
	SETTING_ARRAY_09,
	SETTING_ARRAY_10,
	SETTING_ARRAY_11,
	SETTING_ARRAY_12,
	SETTING_ARRAY_13,
	SETTING_ARRAY_14,
	SETTING_ARRAY_15,
	SETTING_ARRAY_16,
	SETTING_ARRAY_17,
	SETTING_ARRAY_18,
	SETTING_ARRAY_19,
	SETTING_ARRAY_20
} SETTING_ArrayID;

/* Setting Values struct */
typedef struct
{
	int16_t SETTING_Array01[24];
	int16_t SETTING_Array02[24];
	int16_t SETTING_Array03[24];
	int16_t SETTING_Array04[24];
	int16_t SETTING_Array05[24];
	int16_t SETTING_Array06[24];
	int16_t SETTING_Array07[24];
	int16_t SETTING_Array08[24];
	int16_t SETTING_Array09[24];
	int16_t SETTING_Array10[24];
	int16_t SETTING_Array11[24];
	int16_t SETTING_Array12[24];
	int16_t SETTING_Array13[24];
	int16_t SETTING_Array14[24];
	int16_t SETTING_Array15[24];
	int16_t SETTING_Array16[24];
	int16_t SETTING_Array17[24];
	int16_t SETTING_Array18[24];
	int16_t SETTING_Array19[24];
	int16_t SETTING_Array20[24];
} SETTING_Values;

/* Setting query structure */
typedef struct
{
	SETTING_ArrayID ArrayID;
	uint8_t number;
	SETTING_ChangeDirection Direction;
	int16_t directValue;
} SETTING_Query;

/* Load settings from FLASH */
void SETTING_Load(SETTING_Values *Values);

/* Load default settings */
void SETTING_LoadDefaults(SETTING_Values *Values);

/* Save settings in FLASH */
HAL_StatusTypeDef SETTING_Save(SETTING_Values *Values);

/* Get setting value */
int16_t SETTING_GetValue(SETTING_ArrayID ArrayID, uint8_t number, SETTING_Values *Values);

/* Get char representation of the setting value */
void SETTING_GetCharValue(SETTING_ArrayID ArrayID, uint8_t number, SETTING_Values *Values, char result[21]);

/* Change setting value */
void SETTING_ChangeValue(SETTING_Query Query, SETTING_Values *Values);

#endif /* __setting_h */

/* end of setting.h */
