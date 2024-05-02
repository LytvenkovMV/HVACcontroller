
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "usdelay.h"
#include "bus.h"



#ifndef __HD44780_h
#define __HD44780_h

#define HD44780_CLEAR					(0x01)
#define HD44780_FUNCTION_SET			(0x20)
#define HD44780_4BIT_DATA				(0x00)
#define HD44780_8BIT_DATA				(0x10)
#define HD44780_1LINE_MODE				(0x00)
#define HD44780_2LINE_MODE				(0x08)
#define HD44780_5X8_FONT				(0x00)
#define HD44780_5X10_FONT				(0x04)
#define HD44780_DISPLAY_CONTROL			(0x08)
#define HD44780_DISPLAY_ON_CMD			(0x04)
#define HD44780_CURSOR_ON_CMD			(0x02)
#define HD44780_BLINK_ON_CMD			(0x01)
#define HD44780_ENTRY_MODE_SET			(0x04)
#define HD44780_INCREMENT_MODE			(0x02)
#define HD44780_DECREMENT_MODE			(0x00)
#define HD44780_SHIFT_MODE				(0x01)
#define HD44780_CGRAM_ADDRESS_SET		(0x40)
#define HD44780_DDRAM_ADDRESS_SET		(0x80)
#define HD44780_LINE1_ADDRESS			(0x00)
#define HD44780_LINE2_ADDRESS			(0x40)
#define HD44780_LINE3_ADDRESS			(0x14)
#define HD44780_LINE4_ADDRESS			(0x54)

/* LCD line length */
#define HD44780_LINE_LENGTH				(20)

/* HD44780 register */
typedef enum
{
	HD44780_IR,
	HD44780_DR
} HD44780_Register;

/* LCD lines */
typedef enum
{
	HD44780_LINE_1,
	HD44780_LINE_2,
	HD44780_LINE_3,
	HD44780_LINE_4
} HD44780_Lines;

/* LCD mode */
typedef enum
{
	HD44780_OFF,
	HD44780_ON
} HD44780_Mode;

/* LCD status */
typedef struct
{
	HD44780_Mode DisplayMode;
	HD44780_Mode CursorMode;
	HD44780_Mode BlinkMode;
} HD44780_Status;
	
/* Initializes HD44780 LCD module */
void HD44780_Init(void);

/* Clear LCD */
void HD44780_ClearDisplay(void);

/* Turn on the display */
void HD44780_DisplayOn(HD44780_Status *Status);

/* Turn off the display */
void HD44780_DisplayOff(HD44780_Status *Status);

/* Turn on the underline cursor */
void HD44780_CursorOn(HD44780_Status *Status);

/* Turn off the underline cursor */
void HD44780_CursorOff(HD44780_Status *Status);

/* Turn on the blinking cursor */
void HD44780_BlinkOn(HD44780_Status *Status);

/* Turn off the blinking cursor */
void HD44780_BlinkOff(HD44780_Status *Status);

/* Set the cursor position (specify RAM address) */
void HD44780_SetCursorPos(HD44780_Lines Line, uint8_t column);

/* Print one character on LCD */
void HD44780_PrintCharacter(HD44780_Lines Line, uint8_t position, char character);

/* Print string on LCD */
void HD44780_PrintLine(HD44780_Lines Line, char *text);

/* Create custom character
 *
 * @param   CGRAM address  The address of the character in the character generator RAM
 *                         Must be from 0 to 7
 * @param   charMap        The map of the custom character
 */
void HD44780_CreateChar(uint8_t CGRAMaddress, uint8_t charMap[8]);

#endif /* __HD44780_h */

/* end of HD44780.h */
