
#include "HD44780.h"



void HD44780_WriteRegister(HD44780_Register Register, uint8_t data)
{
	/* Select register */
	switch (Register)
	{
		case HD44780_IR: HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);	break;
		case HD44780_DR: HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);		break;
	}

	/* Wait 10 microseconds */
	USDELAY_10us();

	/* Write data to the bus */
	BUS_WriteInteger(data);

	/* Wait 10 microseconds */
	USDELAY_10us();

	/* Enable LCD module */
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
  
	/* Wait 10 microseconds */
	USDELAY_10us();
	
	/* Disable LCD module */
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);

	/* Wait 50 microseconds */
	USDELAY_50us();
}



void HD44780_ClearDisplay(void)
{
	HD44780_WriteRegister(HD44780_IR, HD44780_CLEAR);

	osDelay(2);
}



void HD44780_DisplayOn(HD44780_Status *Status)
{
	if (Status->DisplayMode == HD44780_OFF)
	{
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL | HD44780_DISPLAY_ON_CMD;
		if (Status->CursorMode == HD44780_ON) temp = temp | HD44780_CURSOR_ON_CMD;
		if (Status->BlinkMode == HD44780_ON)  temp = temp | HD44780_BLINK_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->DisplayMode = HD44780_ON;
	}
}



void HD44780_DisplayOff(HD44780_Status *Status)
{
	if (Status->DisplayMode == HD44780_ON)
	{	
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL;
		if (Status->CursorMode == HD44780_ON) temp = temp | HD44780_CURSOR_ON_CMD;
		if (Status->BlinkMode == HD44780_ON)  temp = temp | HD44780_BLINK_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->DisplayMode = HD44780_OFF;
	}
}



void HD44780_CursorOn(HD44780_Status *Status)
{
	if (Status->CursorMode == HD44780_OFF)
	{
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL | HD44780_CURSOR_ON_CMD;
		if (Status->DisplayMode == HD44780_ON) temp = temp | HD44780_DISPLAY_ON_CMD;
		if (Status->BlinkMode == HD44780_ON)   temp = temp | HD44780_BLINK_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->CursorMode = HD44780_ON;
	}
}



void HD44780_CursorOff(HD44780_Status *Status)
{
	if (Status->CursorMode == HD44780_ON)
	{	
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL;
		if (Status->DisplayMode == HD44780_ON) temp = temp | HD44780_DISPLAY_ON_CMD;
		if (Status->BlinkMode == HD44780_ON)   temp = temp | HD44780_BLINK_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->CursorMode = HD44780_OFF;
	}
}



void HD44780_BlinkOn(HD44780_Status *Status)
{
	if (Status->BlinkMode == HD44780_OFF)
	{
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL | HD44780_BLINK_ON_CMD;
		if (Status->DisplayMode == HD44780_ON) temp = temp | HD44780_DISPLAY_ON_CMD;
		if (Status->CursorMode == HD44780_ON)  temp = temp | HD44780_CURSOR_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->BlinkMode = HD44780_ON;
	}
}



void HD44780_BlinkOff(HD44780_Status *Status)
{
	if (Status->BlinkMode == HD44780_ON)
	{
		uint8_t temp;
		
		temp = HD44780_DISPLAY_CONTROL;
		if (Status->DisplayMode == HD44780_ON) temp = temp | HD44780_DISPLAY_ON_CMD;
		if (Status->CursorMode == HD44780_ON)  temp = temp | HD44780_CURSOR_ON_CMD;
		HD44780_WriteRegister(HD44780_IR, temp);
		Status->BlinkMode = HD44780_OFF;
	}
}



void HD44780_Init(void)
{
	/* Delay after power rises */
	osDelay(50);

	/* Select write mode */
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);

	/* Put the LCD into 8 bit mode */
	HD44780_WriteRegister(HD44780_IR, (HD44780_FUNCTION_SET | HD44780_8BIT_DATA | HD44780_2LINE_MODE | HD44780_5X8_FONT));
	osDelay(5);

	/* Second try */
	HD44780_WriteRegister(HD44780_IR, (HD44780_FUNCTION_SET | HD44780_8BIT_DATA | HD44780_2LINE_MODE | HD44780_5X8_FONT));
	USDELAY_50us();
	USDELAY_50us();
	USDELAY_50us();
	USDELAY_50us();

	/* Third go */
	HD44780_WriteRegister(HD44780_IR, (HD44780_FUNCTION_SET | HD44780_8BIT_DATA | HD44780_2LINE_MODE | HD44780_5X8_FONT));

	/* Finally, set number of lines, font size, etc. */
	HD44780_WriteRegister(HD44780_IR, (HD44780_FUNCTION_SET | HD44780_8BIT_DATA | HD44780_2LINE_MODE | HD44780_5X8_FONT));

	/* Display control: display on, cursor off and blink off */
	HD44780_WriteRegister(HD44780_IR, (HD44780_DISPLAY_CONTROL | HD44780_DISPLAY_ON_CMD));

	/* Entry mode set: increment address by one */
	HD44780_WriteRegister(HD44780_IR, HD44780_ENTRY_MODE_SET | HD44780_INCREMENT_MODE);

	/* Clear display */
	HD44780_ClearDisplay();
}



void HD44780_SetCursorPos(HD44780_Lines Line, uint8_t column)
{
	column--;
	
	/* Set display data RAM address */
	switch (Line)
	{
	  case HD44780_LINE_1: HD44780_WriteRegister(HD44780_IR, (column | HD44780_DDRAM_ADDRESS_SET | HD44780_LINE1_ADDRESS)); break;
	  case HD44780_LINE_2: HD44780_WriteRegister(HD44780_IR, (column | HD44780_DDRAM_ADDRESS_SET | HD44780_LINE2_ADDRESS)); break;
	  case HD44780_LINE_3: HD44780_WriteRegister(HD44780_IR, (column | HD44780_DDRAM_ADDRESS_SET | HD44780_LINE3_ADDRESS)); break;
	  case HD44780_LINE_4: HD44780_WriteRegister(HD44780_IR, (column | HD44780_DDRAM_ADDRESS_SET | HD44780_LINE4_ADDRESS)); break;
	}
}



void HD44780_PrintCharacter(HD44780_Lines Line, uint8_t position, char character)
{
	/* Set display data RAM address */
	HD44780_SetCursorPos(Line, position);

	/* Write symbol to RAM */
	HD44780_WriteRegister(HD44780_DR, character);
}



void HD44780_PrintLine(HD44780_Lines Line, char *text)
{
	uint8_t i = 0;

	/* Set RAM address */
	HD44780_SetCursorPos(Line, 1);
	
	/* Write text to RAM */
	do
	{
		HD44780_WriteRegister(HD44780_DR, text[i]);
		i++;
	}
	while ((text[i] != '\0') && (i < HD44780_LINE_LENGTH));
}



void HD44780_CreateChar(uint8_t CGRAMaddress, uint8_t charmap[8])
{
	/* RAM address must be from 0 to 7 */
	if (CGRAMaddress > 7) CGRAMaddress = 7;

	/* Set character generator RAM address */
	HD44780_WriteRegister(HD44780_IR, (HD44780_CGRAM_ADDRESS_SET | (CGRAMaddress << 3)));

	/* Write char map */
	for (uint8_t i = 0; i < 8; i++)
	{
		HD44780_WriteRegister(HD44780_DR, charmap[i]);
	}
}
