
#include "HD44780.h"
#include "hmi.h"
#include "menu.h"
#include "setting.h"
#include "heating.h"
#include "output.h"
#include "input.h"
#include "string.h"
#include "print.h"
#include "message.h"
#include "info_config.h"

#ifndef __display_h
#define __display_h

/* Format of the weekday char represent */
typedef enum
{
	DISPLAY_WEEKDAY_SHORT,
	DISPLAY_WEEKDAY_FULL
} DISPLAY_WeekdayFormat;

/* Custom character */
typedef enum
{
	DISPLAY_CUSTOM_CHAR_01,
	DISPLAY_CUSTOM_CHAR_02,
	DISPLAY_CUSTOM_CHAR_03,
	DISPLAY_CUSTOM_CHAR_04,
	DISPLAY_CUSTOM_CHAR_05,
	DISPLAY_CUSTOM_CHAR_06,
	DISPLAY_CUSTOM_CHAR_07,
	DISPLAY_CUSTOM_CHAR_08,
	DISPLAY_CUSTOM_CHAR_09,
	DISPLAY_CUSTOM_CHAR_10
} DISPLAY_CustomChar;

/* Display character generator RAM address */
typedef enum
{
	DISPLAY_CGRAM_ADDR_1 = 0,
	DISPLAY_CGRAM_ADDR_2 = 1,
	DISPLAY_CGRAM_ADDR_3 = 2,
	DISPLAY_CGRAM_ADDR_4 = 3,
	DISPLAY_CGRAM_ADDR_5 = 4,
	DISPLAY_CGRAM_ADDR_6 = 5,
	DISPLAY_CGRAM_ADDR_7 = 6,
	DISPLAY_CGRAM_ADDR_8 = 7
} DISPLAY_CGRAMaddress;

/* Turn on the display back light */
void DISPLAY_TurnOnBackLight(void);

/* Turn off the display back light */
void DISPLAY_TurnOffBackLight(void);

/* Initialize LCD */
void DISPLAY_Init(void);

/* Show the initial screen on LCD */
void DISPLAY_ShowInitialScreen(HMI_Status *Status, osMessageQId *HeatingStateQH, osMessageQId *SensorsQH, RTC_HandleTypeDef *HandleRTC);

/* Show the menu screen on LCD */
void DISPLAY_ShowMenuScreen(HMI_Status *Status, osMessageQId *SettingValuesQH, osMessageQId *InputStatesQH, osMessageQId *SensorsQH, RTC_HandleTypeDef *HandleRTC);

/* Show the message screen on LCD */
void DISPLAY_ShowMessageScreen(HMI_Status *Status);

/* Show the colon symbol (:) on LCD */
void DISPLAY_ShowColonSymbol(void);

/* Hide the colon symbol (:) on LCD */
void DISPLAY_HideColonSymbol(void);

/* Create custom character
 *
 * @param   		CGRAM address	The address of the character in the character generator RAM. Must be from 0 to 7
 *
 * @param   		CustomChar		Custom character number
 *
 * @note			CGRAM addresses from 0 to 7 are mapped to CGRAM addresses from 8 to 15. In order to exclude 0 from source code,
 * 					we must use addresses from 8 to 15
 *
 * @examples		There are two options to add a custom character to the char array. Array text[] consists a custom character located at the address 6 of the display CGRAM.
 * 					1. char text[5] = {'A', 'B', 14, 'C', '\0'};
 *					   In this case, we must add 8 to CGRAM address and paste result to the array
 *					   6 + 8 = 14
 * 					2. char text[5] = "AB\16C";
 * 					   In this case, we must add 8 to CGRAM address, convert result to the octal code and paste it to the array
 * 					   6 + 8 = 14
 * 					   convert 14 to octal code = 16
 */
void DISPLAY_CreateCustomChar(DISPLAY_CGRAMaddress CGRAMaddress, DISPLAY_CustomChar CustomChar);

#endif /* __display_h */

/* end of display.h */
