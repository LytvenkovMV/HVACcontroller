
#include "display.h"
#include "display_config.h"



void DISPLAY_TurnOnBackLight(void)
{
	HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, GPIO_PIN_SET);
}



void DISPLAY_TurnOffBackLight(void)
{
	HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, GPIO_PIN_RESET);
}



void DISPLAY_Init(void)
{
	/* Initialize LCD */
	HD44780_Init();

	/* Turn on the display back light */
	DISPLAY_TurnOnBackLight();
}



void DISPLAY_PrintLines(char line1[21], char line2[21], char line3[21], char line4[21])
{
	HD44780_PrintLine(HD44780_LINE_1, line1);
	HD44780_PrintLine(HD44780_LINE_2, line2);
	HD44780_PrintLine(HD44780_LINE_3, line3);
	HD44780_PrintLine(HD44780_LINE_4, line4);
}



void DISPLAY_GetDateCharValue(RTC_DateTypeDef *Date, char result[9])
{
	char temp[3] = "";

	strcpy(result, "");

	if ((Date->Date) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Date->Date), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
	strcat(result, ".");

	if ((Date->Month) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Date->Month), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
	strcat(result, ".");

	if ((Date->Year) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Date->Year), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
}



void DISPLAY_GetTimeCharValue(RTC_TimeTypeDef *Time, char result[9])
{
	char temp[3] = "";

	strcpy(result, "");

	if ((Time->Hours) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Time->Hours), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
	strcat(result, ":");

	if ((Time->Minutes) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Time->Minutes), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
	strcat(result, ":");

	if ((Time->Seconds) < 10) strcat (result, "0");
	PRINT_UnsignedInteger((Time->Seconds), PRINT_LEFT_ALIGNMENT, temp);
	strcat(result, temp);
}



void DISPLAY_GetWeekdayCharValue(RTC_DateTypeDef *Date, DISPLAY_WeekdayFormat Format, char result[10])
{
	strcpy(result, "???");

	switch (Format)
	{
		case DISPLAY_WEEKDAY_SHORT:
		{
			switch (Date->WeekDay)
			{
				case RTC_WEEKDAY_MONDAY:    strcpy(result, DISPLAY_CONF_MONDAY_SHORT);		break;
				case RTC_WEEKDAY_TUESDAY:   strcpy(result, DISPLAY_CONF_TUESDAY_SHORT);		break;
				case RTC_WEEKDAY_WEDNESDAY: strcpy(result, DISPLAY_CONF_WEDNESDAY_SHORT);	break;
				case RTC_WEEKDAY_THURSDAY:  strcpy(result, DISPLAY_CONF_THURSDAY_SHORT);	break;
				case RTC_WEEKDAY_FRIDAY:    strcpy(result, DISPLAY_CONF_FRIDAY_SHORT);		break;
				case RTC_WEEKDAY_SATURDAY:  strcpy(result, DISPLAY_CONF_SATURDAY_SHORT);	break;
				case RTC_WEEKDAY_SUNDAY:    strcpy(result, DISPLAY_CONF_SUNDAY_SHORT);		break;
				default:;
			}
		}
		break;
		
		case DISPLAY_WEEKDAY_FULL:
		{
			switch (Date->WeekDay)
			{
				case RTC_WEEKDAY_MONDAY:    strcpy(result, DISPLAY_CONF_MONDAY_FULL);		break;
				case RTC_WEEKDAY_TUESDAY:   strcpy(result, DISPLAY_CONF_TUESDAY_FULL);		break;
				case RTC_WEEKDAY_WEDNESDAY: strcpy(result, DISPLAY_CONF_WEDNESDAY_FULL);	break;
				case RTC_WEEKDAY_THURSDAY:  strcpy(result, DISPLAY_CONF_THURSDAY_FULL);		break;
				case RTC_WEEKDAY_FRIDAY:    strcpy(result, DISPLAY_CONF_FRIDAY_FULL);		break;
				case RTC_WEEKDAY_SATURDAY:  strcpy(result, DISPLAY_CONF_SATURDAY_FULL);		break;
				case RTC_WEEKDAY_SUNDAY:    strcpy(result, DISPLAY_CONF_SUNDAY_FULL);		break;
				default:;
			}			
		}
		break;

		default:;
	}
}



void DISPLAY_GetMonthCharValue(RTC_DateTypeDef *Date, char result[10])
{
	strcpy(result, "   ???   ");

	switch (Date->Month)
	{
		case 1:  strcpy(result, DISPLAY_CONF_JANUARY);		break;
		case 2:  strcpy(result, DISPLAY_CONF_FEBRUARY);		break;
		case 3:  strcpy(result, DISPLAY_CONF_MARCH);		break;
		case 4:  strcpy(result, DISPLAY_CONF_APRIL);		break;
		case 5:  strcpy(result, DISPLAY_CONF_MAY);			break;
		case 6:  strcpy(result, DISPLAY_CONF_JUNE);			break;
		case 7:  strcpy(result, DISPLAY_CONF_JULY);			break;
		case 8:  strcpy(result, DISPLAY_CONF_AUGUST);		break;
		case 9:  strcpy(result, DISPLAY_CONF_SEPTEMBER);	break;
		case 10: strcpy(result, DISPLAY_CONF_OCTOBER);		break;
		case 11: strcpy(result, DISPLAY_CONF_NOVEMBER);		break;
		case 12: strcpy(result, DISPLAY_CONF_DECERMBER);	break;
		default:;
	}
}



void DISPLAY_GetLines(HMI_Status *Status, char line1[21], char line2[21], char line3[21], char line4[21])
{
	char temp[20] = "";

	strcpy(line1, " ");
	strcpy(line2, " ");
	strcpy(line3, " ");
	strcpy(line4, " ");
	
	/* Copy cursor sign to the corresponding line*/
	switch (Status->CursorPosition)
	{
		case HMI_CURSOR_IN_LINE1: strcpy(line1, ">"); break;
		case HMI_CURSOR_IN_LINE2: strcpy(line2, ">"); break;
		case HMI_CURSOR_IN_LINE3: strcpy(line3, ">"); break;
		case HMI_CURSOR_IN_LINE4: strcpy(line4, ">"); break;
	}
	
	/* Get line 1 */
	strcpy(temp, "");
	MENU_GetLine(Status->MenuItemID, (Status->ScrollPosition + 1), temp);
	strcat(line1, temp);

	/* Get line 2 */
	strcpy(temp, "");
	MENU_GetLine(Status->MenuItemID, (Status->ScrollPosition + 2), temp);
	strcat(line2, temp);

	/* Get line 3 */
	strcpy(temp, "");
	MENU_GetLine(Status->MenuItemID, (Status->ScrollPosition + 3), temp);
	strcat(line3, temp);
	
	/* Get line 4 */
	strcpy(temp, "");
	MENU_GetLine(Status->MenuItemID, (Status->ScrollPosition + 4), temp);
	strcat(line4, temp);
}



void DISPLAY_GetInputs(HMI_Status *Status, osMessageQId *InputStatesQueueHandle, char param1[5], char param2[5], char param3[5], char param4[5])
{
	portBASE_TYPE xInputStatesQueueStatus = pdFAIL;
	INPUT_States InputStates;
	INPUT_State InputState1, InputState2, InputState3, InputState4;
	
	xInputStatesQueueStatus = xQueuePeek(InputStatesQueueHandle, &InputStates, 0);

	if (xInputStatesQueueStatus == pdPASS)
	{
		InputState1 = INPUT_GetStateByNumber(&InputStates, (Status->ScrollPosition + 1));
		InputState2 = INPUT_GetStateByNumber(&InputStates, (Status->ScrollPosition + 2));
		InputState3 = INPUT_GetStateByNumber(&InputStates, (Status->ScrollPosition + 3));
		InputState4 = INPUT_GetStateByNumber(&InputStates, (Status->ScrollPosition + 4));

		if (InputState1 == INPUT_SET) strcpy(param1, DISPLAY_CONF_INPUT_SET); else strcpy(param1, DISPLAY_CONF_INPUT_RESET);
		if (InputState2 == INPUT_SET) strcpy(param2, DISPLAY_CONF_INPUT_SET); else strcpy(param2, DISPLAY_CONF_INPUT_RESET);
		if (InputState3 == INPUT_SET) strcpy(param3, DISPLAY_CONF_INPUT_SET); else strcpy(param3, DISPLAY_CONF_INPUT_RESET);
		if (InputState4 == INPUT_SET) strcpy(param4, DISPLAY_CONF_INPUT_SET); else strcpy(param4, DISPLAY_CONF_INPUT_RESET);
	}
	else
	{
		strcpy(param1, "  ?");
		strcpy(param2, "  ?");
		strcpy(param3, "  ?");
		strcpy(param4, "  ?");
	}
}



void DISPLAY_GetOutputs(HMI_Status *Status, char param1[5], char param2[5], char param3[5], char param4[5])
{
	OUTPUT_State OutputState1, OutputState2, OutputState3, OutputState4;

	OutputState1 = OUTPUT_GetStateByNumber(Status->ScrollPosition + 1);
	OutputState2 = OUTPUT_GetStateByNumber(Status->ScrollPosition + 2);
	OutputState3 = OUTPUT_GetStateByNumber(Status->ScrollPosition + 3);
	OutputState4 = OUTPUT_GetStateByNumber(Status->ScrollPosition + 4);
	
	if (OutputState1 == OUTPUT_ON) strcpy(param1, DISPLAY_CONF_OUTPUT_ON); else strcpy(param1, DISPLAY_CONF_OUTPUT_OFF);
	if (OutputState2 == OUTPUT_ON) strcpy(param2, DISPLAY_CONF_OUTPUT_ON); else strcpy(param2, DISPLAY_CONF_OUTPUT_OFF);
	if (OutputState3 == OUTPUT_ON) strcpy(param3, DISPLAY_CONF_OUTPUT_ON); else strcpy(param3, DISPLAY_CONF_OUTPUT_OFF);
	if (OutputState4 == OUTPUT_ON) strcpy(param4, DISPLAY_CONF_OUTPUT_ON); else strcpy(param4, DISPLAY_CONF_OUTPUT_OFF);
}



void DISPLAY_GetSensors(HMI_Status *Status, osMessageQId *SensorsQueueHandle, char param1[11], char param2[11], char param3[11], char param4[11])
{
	portBASE_TYPE xSensorsQueueStatus = pdFAIL;
	SENSOR_Values SensorValues;
	
	xSensorsQueueStatus = xQueuePeek(SensorsQueueHandle, &SensorValues, 0);
	
	if (xSensorsQueueStatus == pdPASS)
	{
		SENSOR_GetCharValue((Status->ScrollPosition + 1), &SensorValues, param1);
		SENSOR_GetCharValue((Status->ScrollPosition + 2), &SensorValues, param2);
		SENSOR_GetCharValue((Status->ScrollPosition + 3), &SensorValues, param3);
		SENSOR_GetCharValue((Status->ScrollPosition + 4), &SensorValues, param4);
	}
	else
	{
		strcpy(param1, "    ?");
		strcpy(param2, "    ?");
		strcpy(param3, "    ?");
		strcpy(param4, "    ?");
	}
}



void DISPLAY_Merge(char line1[21], char line2[21], char line3[21], char line4[21], char param1[11], char param2[11], char param3[11], char param4[11])
{
	strcat(line1, param1);
	strcat(line2, param2);
	strcat(line3, param3);
	strcat(line4, param4);
}



void DISPLAY_GetSettingLines(HMI_Status *Status, osMessageQId *SettingValuesQueueHandle, char line1[21], char line2[21], char line3[21], char line4[21])
{
	SETTING_Values Values;
	SETTING_ArrayID ArrayID;
	uint8_t selectedLine;
	char temp[21] = "";

	ArrayID = MENU_GetSettingArrayID(Status->MenuItemID);
	selectedLine = Status->CursorPosition + Status->ScrollPosition;

	xQueuePeek(SettingValuesQueueHandle, &Values, 0);

	MENU_GetLine(Status->MenuItemID, selectedLine, line1);
	strcat(line1, " ");

	strcpy(line2, "");
	SETTING_GetCharValue(ArrayID, selectedLine, &Values, temp);
	strcpy(line2, temp);

	strcpy(line3, DISPLAY_CONF_ROTATE_TO_CHANGE);

	strcpy(line4, DISPLAY_CONF_PUSH_TO_CONFIRM);
}



void DISPLAY_GetControlLines(HMI_Status *Status, char line1[21], char line2[21], char line3[21], char line4[21])
{
	uint8_t selectedLine;

	selectedLine = Status->CursorPosition + Status->ScrollPosition;

	MENU_GetLine(Status->MenuItemID, selectedLine, line1);

	strcpy(line2, DISPLAY_CONF_QUESTION);

	strcpy(line3, DISPLAY_CONF_NO_YES);

	switch (Status->SwitchPosition)
	{
		case HMI_SWITCH_IN_COLUMN1: strcpy(line4, DISPLAY_CONF_CURSOR_IN_NO_POSITION);  break;
		case HMI_SWITCH_IN_COLUMN2: strcpy(line4, DISPLAY_CONF_CURSOR_IN_YES_POSITION); break;
		default: strcpy(line4, "");
	}
}



void DISPLAY_GetDateLines(HMI_Status *Status, RTC_HandleTypeDef *HandleRTC, char line1[21], char line2[21], char line3[21], char line4[21])
{
	RTC_DateTypeDef Date;
	char temp[9] = "";
	
	HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
	
	/* Fill in line1 */
	/* Fill in year */
	strcpy(line1, "20");
	if ((Date.Year) < 10) strcat (line1, "0");
	PRINT_UnsignedInteger((Date.Year), PRINT_LEFT_ALIGNMENT, temp);
	strcat(line1, temp);
	strcat(line1, " ");

	/* Fill in month */
	strcpy(temp, "");
	DISPLAY_GetMonthCharValue(&Date, temp);
	strcat(line1, temp);
	strcat(line1, " ");
	
	/* Fill in date */
	if ((Date.Date) < 10) strcat (line1, "0");
	PRINT_UnsignedInteger((Date.Date), PRINT_LEFT_ALIGNMENT, temp);
	strcat(line1, temp);
	strcat(line1, "   ");
	
	/* Fill in line2 */
	switch (Status->SwitchPosition)
	{
		case HMI_SWITCH_IN_COLUMN1: strcpy(line2, "   ^                "); break;
		case HMI_SWITCH_IN_COLUMN2: strcpy(line2, "         ^          "); break;
		case HMI_SWITCH_IN_COLUMN3: strcpy(line2, "                ^   "); break;
		default:;
	}

	/* Fill in line3 and line4 */
	strcpy(line3, DISPLAY_CONF_ROTATE_TO_CHANGE);
	strcpy(line4, DISPLAY_CONF_PUSH_TO_CONFIRM);
}



void DISPLAY_GetTimeLines(HMI_Status *Status, RTC_HandleTypeDef *HandleRTC, char line1[21], char line2[21], char line3[21], char line4[21])
{
	RTC_TimeTypeDef Time;
	char temp[9] = "";
	
	HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
	
	/* Fill in line1 */
	strcpy(line1, "      ");
	DISPLAY_GetTimeCharValue(&Time, temp);
	strcat(line1, temp);
	strcat(line1, "      ");
	
	/* Fill in line2 */
	switch (Status->SwitchPosition)
	{
		case HMI_SWITCH_IN_COLUMN1: strcpy(line2, "       ^            "); break;
		case HMI_SWITCH_IN_COLUMN2: strcpy(line2, "          ^         "); break;
		case HMI_SWITCH_IN_COLUMN3: strcpy(line2, "             ^      "); break;
		case HMI_SWITCH_IN_COLUMN4: strcpy(line2, "                    "); break;
	}

	/* Fill in line3 and line4 */
	strcpy(line3, DISPLAY_CONF_ROTATE_TO_CHANGE);
	strcpy(line4, DISPLAY_CONF_PUSH_TO_CONFIRM);
}



void DISPLAY_GetDateTimeLines(HMI_Status *Status, RTC_HandleTypeDef *HandleRTC, char line1[21], char line2[21], char line3[21], char line4[21])
{
	switch (Status->CursorPosition)
	{
		case HMI_CURSOR_IN_LINE1: DISPLAY_GetDateLines(Status, HandleRTC, line1, line2, line3, line4); break;
		case HMI_CURSOR_IN_LINE2: DISPLAY_GetTimeLines(Status, HandleRTC, line1, line2, line3, line4); break;
		default:;
	}
}



void DISPLAY_GetInfoLines(HMI_Status *Status, char line1[21], char line2[21], char line3[21], char line4[21])
{
	uint8_t selectedLine;

	selectedLine = Status->CursorPosition + Status->ScrollPosition;

	if      (selectedLine == 1)
	{
		strcpy(line1, INFO_CONF_INF01_LINE1);
		strcpy(line2, INFO_CONF_INF01_LINE2);
		strcpy(line3, INFO_CONF_INF01_LINE3);
		strcpy(line4, INFO_CONF_INF01_LINE4);
	}
	else if (selectedLine == 2)
	{
		strcpy(line1, INFO_CONF_INF02_LINE1);
		strcpy(line2, INFO_CONF_INF02_LINE2);
		strcpy(line3, INFO_CONF_INF02_LINE3);
		strcpy(line4, INFO_CONF_INF02_LINE4);
	}
	else if (selectedLine == 3)
	{
		strcpy(line1, INFO_CONF_INF03_LINE1);
		strcpy(line2, INFO_CONF_INF03_LINE2);
		strcpy(line3, INFO_CONF_INF03_LINE3);
		strcpy(line4, INFO_CONF_INF03_LINE4);
	}
	else if (selectedLine == 4)
	{
		strcpy(line1, INFO_CONF_INF04_LINE1);
		strcpy(line2, INFO_CONF_INF04_LINE2);
		strcpy(line3, INFO_CONF_INF04_LINE3);
		strcpy(line4, INFO_CONF_INF04_LINE4);
	}
	else if (selectedLine == 5)
	{
		strcpy(line1, INFO_CONF_INF05_LINE1);
		strcpy(line2, INFO_CONF_INF05_LINE2);
		strcpy(line3, INFO_CONF_INF05_LINE3);
		strcpy(line4, INFO_CONF_INF05_LINE4);
	}
	else if (selectedLine == 6)
	{
		strcpy(line1, INFO_CONF_INF06_LINE1);
		strcpy(line2, INFO_CONF_INF06_LINE2);
		strcpy(line3, INFO_CONF_INF06_LINE3);
		strcpy(line4, INFO_CONF_INF06_LINE4);
	}
	else if (selectedLine == 7)
	{
		strcpy(line1, INFO_CONF_INF07_LINE1);
		strcpy(line2, INFO_CONF_INF07_LINE2);
		strcpy(line3, INFO_CONF_INF07_LINE3);
		strcpy(line4, INFO_CONF_INF07_LINE4);
	}
	else if (selectedLine == 8)
	{
		strcpy(line1, INFO_CONF_INF08_LINE1);
		strcpy(line2, INFO_CONF_INF08_LINE2);
		strcpy(line3, INFO_CONF_INF08_LINE3);
		strcpy(line4, INFO_CONF_INF08_LINE4);
	}
	else if (selectedLine == 9)
	{
		strcpy(line1, INFO_CONF_INF09_LINE1);
		strcpy(line2, INFO_CONF_INF09_LINE2);
		strcpy(line3, INFO_CONF_INF09_LINE3);
		strcpy(line4, INFO_CONF_INF09_LINE4);
	}
	else if (selectedLine == 10)
	{
		strcpy(line1, INFO_CONF_INF10_LINE1);
		strcpy(line2, INFO_CONF_INF10_LINE2);
		strcpy(line3, INFO_CONF_INF10_LINE3);
		strcpy(line4, INFO_CONF_INF10_LINE4);
	}
	else if (selectedLine == 11)
	{
		strcpy(line1, INFO_CONF_INF11_LINE1);
		strcpy(line2, INFO_CONF_INF11_LINE2);
		strcpy(line3, INFO_CONF_INF11_LINE3);
		strcpy(line4, INFO_CONF_INF11_LINE4);
	}
	else if (selectedLine == 12)
	{
		strcpy(line1, INFO_CONF_INF12_LINE1);
		strcpy(line2, INFO_CONF_INF12_LINE2);
		strcpy(line3, INFO_CONF_INF12_LINE3);
		strcpy(line4, INFO_CONF_INF12_LINE4);
	}
	else if (selectedLine == 13)
	{
		strcpy(line1, INFO_CONF_INF13_LINE1);
		strcpy(line2, INFO_CONF_INF13_LINE2);
		strcpy(line3, INFO_CONF_INF13_LINE3);
		strcpy(line4, INFO_CONF_INF13_LINE4);
	}
	else if (selectedLine == 14)
	{
		strcpy(line1, INFO_CONF_INF14_LINE1);
		strcpy(line2, INFO_CONF_INF14_LINE2);
		strcpy(line3, INFO_CONF_INF14_LINE3);
		strcpy(line4, INFO_CONF_INF14_LINE4);
	}
	else if (selectedLine == 15)
	{
		strcpy(line1, INFO_CONF_INF15_LINE1);
		strcpy(line2, INFO_CONF_INF15_LINE2);
		strcpy(line3, INFO_CONF_INF15_LINE3);
		strcpy(line4, INFO_CONF_INF15_LINE4);
	}
	else if (selectedLine == 16)
	{
		strcpy(line1, INFO_CONF_INF16_LINE1);
		strcpy(line2, INFO_CONF_INF16_LINE2);
		strcpy(line3, INFO_CONF_INF16_LINE3);
		strcpy(line4, INFO_CONF_INF16_LINE4);
	}
	else if (selectedLine == 17)
	{
		strcpy(line1, INFO_CONF_INF17_LINE1);
		strcpy(line2, INFO_CONF_INF17_LINE2);
		strcpy(line3, INFO_CONF_INF17_LINE3);
		strcpy(line4, INFO_CONF_INF17_LINE4);
	}
	else if (selectedLine == 18)
	{
		strcpy(line1, INFO_CONF_INF18_LINE1);
		strcpy(line2, INFO_CONF_INF18_LINE2);
		strcpy(line3, INFO_CONF_INF18_LINE3);
		strcpy(line4, INFO_CONF_INF18_LINE4);
	}
	else if (selectedLine == 19)
	{
		strcpy(line1, INFO_CONF_INF19_LINE1);
		strcpy(line2, INFO_CONF_INF19_LINE2);
		strcpy(line3, INFO_CONF_INF19_LINE3);
		strcpy(line4, INFO_CONF_INF19_LINE4);
	}
	else if (selectedLine == 20)
	{
		strcpy(line1, INFO_CONF_INF20_LINE1);
		strcpy(line2, INFO_CONF_INF20_LINE2);
		strcpy(line3, INFO_CONF_INF20_LINE3);
		strcpy(line4, INFO_CONF_INF20_LINE4);
	}
	else if (selectedLine == 21)
	{
		strcpy(line1, INFO_CONF_INF21_LINE1);
		strcpy(line2, INFO_CONF_INF21_LINE2);
		strcpy(line3, INFO_CONF_INF21_LINE3);
		strcpy(line4, INFO_CONF_INF21_LINE4);
	}
	else if (selectedLine == 22)
	{
		strcpy(line1, INFO_CONF_INF22_LINE1);
		strcpy(line2, INFO_CONF_INF22_LINE2);
		strcpy(line3, INFO_CONF_INF22_LINE3);
		strcpy(line4, INFO_CONF_INF22_LINE4);
	}
	else if (selectedLine == 23)
	{
		strcpy(line1, INFO_CONF_INF23_LINE1);
		strcpy(line2, INFO_CONF_INF23_LINE2);
		strcpy(line3, INFO_CONF_INF23_LINE3);
		strcpy(line4, INFO_CONF_INF23_LINE4);
	}
	else if (selectedLine == 24)
	{
		strcpy(line1, INFO_CONF_INF24_LINE1);
		strcpy(line2, INFO_CONF_INF24_LINE2);
		strcpy(line3, INFO_CONF_INF24_LINE3);
		strcpy(line4, INFO_CONF_INF24_LINE4);
	}
	else
	{
		strcpy(line1, "");
		strcpy(line2, "");
		strcpy(line3, "");
		strcpy(line4, "");
	}
}


void DISPLAY_ShowMenuScreen(HMI_Status *Status, osMessageQId *SettingValuesQH, osMessageQId *InputStatesQH, osMessageQId *SensorsQH, RTC_HandleTypeDef *HandleRTC)
{
	MENU_ItemType ItemType;
	char line1[21] = "";
	char line2[21] = "";
	char line3[21] = "";
	char line4[21] = "";
	char param1[11] = "";
	char param2[11] = "";
	char param3[11] = "";
	char param4[11] = "";
	
	ItemType = MENU_GetItemType(Status->MenuItemID);
	
	switch (Status->Mode)
	{
		case HMI_WATCH:
		{
			switch (ItemType)
			{
				case MENU_INPUTS_ITEM:
				{
					DISPLAY_GetLines(Status, line1, line2, line3, line4);
					DISPLAY_GetInputs(Status, InputStatesQH, param1, param2, param3, param4);
					DISPLAY_Merge(line1, line2, line3, line4, param1, param2, param3, param4);
				}
				break;
				
				case MENU_OUTPUTS_ITEM:
				{
					DISPLAY_GetLines(Status, line1, line2, line3, line4);
					DISPLAY_GetOutputs(Status, param1, param2, param3, param4);
					DISPLAY_Merge(line1, line2, line3, line4, param1, param2, param3, param4);
				}
				break;
				
				case MENU_SENSORS_ITEM:
				{
					DISPLAY_GetLines(Status, line1, line2, line3, line4);
					DISPLAY_GetSensors(Status, SensorsQH, param1, param2, param3, param4);
					DISPLAY_Merge(line1, line2, line3, line4, param1, param2, param3, param4);
				}
				break;
				
				default:
				{
					DISPLAY_GetLines(Status, line1, line2, line3, line4);
				}
			}
		}
		break;
		
		case HMI_CHANGE:
		{
			switch (ItemType)
			{
				case MENU_SETTINGS_ITEM:	DISPLAY_GetSettingLines(Status, SettingValuesQH, line1, line2, line3, line4);	break;
				case MENU_CONTROL_ITEM:		DISPLAY_GetControlLines(Status, line1, line2, line3, line4);					break;
				case MENU_DATE_TIME_ITEM:	DISPLAY_GetDateTimeLines(Status, HandleRTC, line1, line2, line3, line4);		break;
				case MENU_INFO_ITEM:		DISPLAY_GetInfoLines(Status, line1, line2, line3, line4);						break;
				default:;
			}	
		}
		break;
	}
	
	DISPLAY_PrintLines(line1, line2, line3, line4);
}



void DISPLAY_ShowInitialScreen(HMI_Status *Status, osMessageQId *HeatingStateQH, osMessageQId *SensorsQH, RTC_HandleTypeDef *HandleRTC)
{	
	portBASE_TYPE xSensorsQueueStatus = pdFAIL;
	portBASE_TYPE xHeatingStateQueueStatus = pdFAIL;
	RTC_TimeTypeDef Time;
	RTC_DateTypeDef Date;
	HEATING_State HeatingState;
	SENSOR_Values SensorValues;
	char roomTemp[6] =		"  ?  ";
	char roomHumid[6] =		"  ?  ";
	char coolantTemp[6] =	"  ?  ";
	char airTemp[6] =		"  ?  ";
	char heatingMode[8] =	"   ?   ";
	char heatingPlan[5] =	" ?  ";
	char temp1[9] = "";
	char line1[21] = "";
	char line2[21] = "";
	char line3[21] = "";
	char line4[21] = "";
	
	/* Get sensor values */
	xSensorsQueueStatus = xQueuePeek(SensorsQH, &SensorValues, 0);
	if (xSensorsQueueStatus == pdPASS)
	{
		SENSOR_GetCharValue(1, &SensorValues, roomTemp);
		SENSOR_GetCharValue(2, &SensorValues, roomHumid);
		SENSOR_GetCharValue(4, &SensorValues, coolantTemp);
		SENSOR_GetCharValue(6, &SensorValues, airTemp);
	}
	
	/* Get heating state */
	xHeatingStateQueueStatus = xQueuePeek(HeatingStateQH, &HeatingState, 0);
	if (xHeatingStateQueueStatus == pdPASS)
	{
		/* Get heating current mode */
		switch (HeatingState.CurrMode)
		{
			case HEATING_OFF:		strcpy(heatingMode, DISPLAY_CONF_OFF);		break;
			case HEATING_COOLING: 	strcpy(heatingMode, DISPLAY_CONF_COOLING);	break;
			case HEATING_COMFORT:	strcpy(heatingMode, DISPLAY_CONF_COMFORT);	break;
			case HEATING_ECO:		strcpy(heatingMode, DISPLAY_CONF_ECO);		break;
			case HEATING_FRZ:		strcpy(heatingMode, DISPLAY_CONF_FRZ);		break;
			default:;
		}

		/* Get heating current plan */
		switch (HeatingState.Plan)
		{
			case HEATING_MANUAL:	strcpy(heatingPlan, DISPLAY_CONF_MANUAL);	break;
			case HEATING_AUTOMATIC:	strcpy(heatingPlan, DISPLAY_CONF_PROGRAM);	break;
			default:;
		}
	}

	/* Get current date and time */
	HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
	
	/***************************** Fill in line1 ******************************/
	/* Add date */
	DISPLAY_GetDateCharValue(&Date, temp1);
	strcpy(line1, temp1);
	strcat(line1, "  ");

	/* Add weekday */
	strcpy(temp1, "");
	DISPLAY_GetWeekdayCharValue(&Date, DISPLAY_WEEKDAY_SHORT, temp1);
	strcat(line1, temp1);
	strcat(line1, "  ");

	/* Add hours */
	strcpy(temp1, "");
	if ((Time.Hours) < 10) strcat (line1, "0");
	PRINT_UnsignedInteger((Time.Hours), PRINT_LEFT_ALIGNMENT, temp1);
	strcat(line1, temp1);

	/* Add colon */
	strcat(line1, ":");

	/* Add minutes */
	strcpy(temp1, "");
	if ((Time.Minutes) < 10) strcat (line1, "0");
	PRINT_UnsignedInteger((Time.Minutes), PRINT_LEFT_ALIGNMENT, temp1);
	strcat(line1, temp1);
	
	/***************************** Fill in line2 ******************************/
	/* Add room temperature */
	strcpy(line2, "Room:");
	strcat(line2, roomTemp);
	
	/* Add room humidity */
	strcat(line2, " ");
	strcat(line2, roomHumid);
	strcat(line2, "RH");
	strcat(line2, "  ");
	
	/***************************** Fill in line3 ******************************/
	/* Add coolant temperature */
	strcpy(line3, "Clnt:");
	strcat(line3, coolantTemp);
	
	/* Add air temperature */
	strcat(line3, " Air:");
	strcat(line3, airTemp);
	
	/***************************** Fill in line4 ******************************/
	/* Add heating current mode */
	strcpy(line4, "Mode: ");
	strcat(line4, heatingMode);
	
	/* Add heating current plan */
	strcat(line4, " (");
	strcat(line4, heatingPlan);
	strcat(line4, ") ");
	
	/*************************** Show lines on LCD ****************************/
	DISPLAY_PrintLines(line1, line2, line3, line4);
}



void DISPLAY_ShowMessageScreen(HMI_Status *Status)
{
	RTC_TimeTypeDef Time;
	RTC_DateTypeDef Date;
	MESSAGE_ID ID;	
	char temp[9] = "";
	char line1[21] = "";
	char line2[21] = "";
	char line3[21] = "";
	char line4[21] = "";
	
	/* Fill in message lines */
	ID = Status->MessageID;
	MESSAGE_GetLine1(ID, line1);
	MESSAGE_GetLine2(ID, line2);
	MESSAGE_GetLine3(ID, line3);
	
	/* Fill in message date and time */
	Date = Status->MessageDate;
	Time = Status->MessageTime;
	DISPLAY_GetDateCharValue(&Date, temp);
	strcpy(line4, temp);
	strcat(line4, "  ");
	DISPLAY_GetTimeCharValue(&Time, temp);
	strcat(line4, temp);
	strcat(line4, "  ");
	
	/* Show lines on LCD */
	DISPLAY_PrintLines(line1, line2, line3, line4);
}



void DISPLAY_ShowColonSymbol(void)
{
	HD44780_PrintCharacter(HD44780_LINE_1, 18, ':');
}



void DISPLAY_HideColonSymbol(void)
{
	HD44780_PrintCharacter(HD44780_LINE_1, 18, ' ');
}



void DISPLAY_CreateCustomChar(DISPLAY_CGRAMaddress CGRAMaddress, DISPLAY_CustomChar CustomChar)
{
	uint8_t charmap[8];

	switch (CustomChar)
	{
	case DISPLAY_CUSTOM_CHAR_01:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_01_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_01_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_01_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_01_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_01_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_01_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_01_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_01_8;
		break;

	case DISPLAY_CUSTOM_CHAR_02:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_02_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_02_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_02_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_02_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_02_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_02_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_02_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_02_8;
		break;

	case DISPLAY_CUSTOM_CHAR_03:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_03_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_03_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_03_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_03_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_03_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_03_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_03_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_03_8;
		break;

	case DISPLAY_CUSTOM_CHAR_04:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_04_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_04_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_04_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_04_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_04_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_04_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_04_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_04_8;
		break;

	case DISPLAY_CUSTOM_CHAR_05:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_05_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_05_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_05_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_05_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_05_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_05_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_05_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_05_8;
		break;

	case DISPLAY_CUSTOM_CHAR_06:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_06_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_06_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_06_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_06_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_06_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_06_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_06_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_06_8;
		break;

	case DISPLAY_CUSTOM_CHAR_07:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_07_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_07_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_07_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_07_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_07_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_07_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_07_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_07_8;
		break;

	case DISPLAY_CUSTOM_CHAR_08:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_08_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_08_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_08_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_08_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_08_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_08_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_08_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_08_8;
		break;

	case DISPLAY_CUSTOM_CHAR_09:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_09_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_09_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_09_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_09_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_09_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_09_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_09_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_09_8;
		break;

	case DISPLAY_CUSTOM_CHAR_10:
		charmap[0] = DISPLAY_CONF_CUSTOM_CHAR_10_1;
		charmap[1] = DISPLAY_CONF_CUSTOM_CHAR_10_2;
		charmap[2] = DISPLAY_CONF_CUSTOM_CHAR_10_3;
		charmap[3] = DISPLAY_CONF_CUSTOM_CHAR_10_4;
		charmap[4] = DISPLAY_CONF_CUSTOM_CHAR_10_5;
		charmap[5] = DISPLAY_CONF_CUSTOM_CHAR_10_6;
		charmap[6] = DISPLAY_CONF_CUSTOM_CHAR_10_7;
		charmap[7] = DISPLAY_CONF_CUSTOM_CHAR_10_8;
		break;

	default:
		charmap[0] = 0b11111;
		charmap[1] = 0b11111;
		charmap[2] = 0b11111;
		charmap[3] = 0b11111;
		charmap[4] = 0b11111;
		charmap[5] = 0b11111;
		charmap[6] = 0b11111;
		charmap[7] = 0b11111;
	}

	HD44780_CreateChar(CGRAMaddress, charmap);
}
