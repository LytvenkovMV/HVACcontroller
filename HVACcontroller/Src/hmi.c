
#include "hmi.h"



void HMI_OpenInitial(HMI_Status *Status)
{
	Status->Updating = HMI_UPDATED;
	Status->Mode = HMI_WATCH;
	Status->ScreenType = HMI_INITIAL_SCREEN;
	Status->MenuItemID = MENU_ITEM_01;
	Status->CursorPosition = HMI_CURSOR_IN_LINE1;
	Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
	Status->ScrollPosition = HMI_SCROLL_X0;
}



void HMI_OpenMessage(HMI_Status *Status, MESSAGE_Struct *Message)
{
	Status->Updating = HMI_UPDATED;
	Status->Mode = HMI_WATCH;
	Status->ScreenType = HMI_MESSAGE_SCREEN;
	Status->MessageID = Message->ID;
	Status->MessageDate = Message->Date;
	Status->MessageTime = Message->Time;
}	



void HMI_OpenMenu(HMI_Status *Status)
{
	Status->Updating = HMI_UPDATED;
	Status->Mode = HMI_WATCH;
	Status->ScreenType = HMI_MENU_SCREEN;
	Status->MenuItemID = MENU_ITEM_01;
	Status->CursorPosition = HMI_CURSOR_IN_LINE1;
	Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
	Status->ScrollPosition = HMI_SCROLL_X0;
}	



void HMI_ClearMessage(HMI_Status *Status, MESSAGE_Struct *Message, osMessageQId *HeatingResetQueueHandle, osMessageQId *VentResetQueueHandle)
{
	MESSAGE_Sender Sender;
	
	Sender = MESSAGE_GetSenderID(Message->ID);
	uint16_t temp = 555;
	
	switch (Sender)
	{
		case MESSAGE_SENDER_HEATING:		xQueueSend(HeatingResetQueueHandle, &temp, 100);	break;
		case MESSAGE_SENDER_VENTILATION: 	xQueueSend(VentResetQueueHandle, &temp, 100);		break;
		default:;
	}
	
	HMI_OpenInitial(Status);
}



void HMI_EnterSubItem(HMI_Status *Status, uint8_t selectedLine)
{
	MENU_ItemID SubItemID;

	switch(Status->SubMenuLevel)
	{
	case HMI_SUB_MENU_LEVEL1:

		/* Modify sub menu level */
		Status->SubMenuLevel = HMI_SUB_MENU_LEVEL2;

		/* Save parent item ID, cursor and scroll positions */
		Status->ParentMenuItemIDLev1 = Status->MenuItemID;
		Status->ParentCursorPositionLev1 = Status->CursorPosition;
		Status->ParentScrollPositionLev1 = Status->ScrollPosition;
		break;

	case HMI_SUB_MENU_LEVEL2:

		/* Modify sub menu level */
		Status->SubMenuLevel = HMI_SUB_MENU_LEVEL3;

		/* Save parent item ID, cursor and scroll positions */
		Status->ParentMenuItemIDLev2 = Status->MenuItemID;
		Status->ParentCursorPositionLev2 = Status->CursorPosition;
		Status->ParentScrollPositionLev2 = Status->ScrollPosition;
		break;

	case HMI_SUB_MENU_LEVEL3:

		/* Modify sub menu level */
		Status->SubMenuLevel = HMI_SUB_MENU_LEVEL4;

		/* Save parent item ID, cursor and scroll positions */
		Status->ParentMenuItemIDLev3 = Status->MenuItemID;
		Status->ParentCursorPositionLev3 = Status->CursorPosition;
		Status->ParentScrollPositionLev3 = Status->ScrollPosition;
		break;

	default:;
	}

	/* Get sub item ID */
	SubItemID = MENU_GetLink(Status->MenuItemID, selectedLine);

	/* Change menu item ID */
	Status->MenuItemID = SubItemID;

	/* Set cursor and switch to the initial position */
	Status->CursorPosition = HMI_CURSOR_IN_LINE1;
	Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
	Status->ScrollPosition = HMI_SCROLL_X0;
}



void HMI_ReturnToParentItem(HMI_Status *Status)
{
	/* If we are in the main menu open the initial screen */
	if ((Status->MenuItemID) == MENU_ITEM_01)
	{
		HMI_OpenInitial(Status);
	}
	
	/* Else return to parent item */
	else
	{
		switch(Status->SubMenuLevel)
		{
		case HMI_SUB_MENU_LEVEL2:

			/* Modify sub menu level */
			Status->SubMenuLevel = HMI_SUB_MENU_LEVEL1;

			/* Restore parent item data */
			Status->MenuItemID = Status->ParentMenuItemIDLev1;
			Status->CursorPosition = Status->ParentCursorPositionLev1;
			Status->ScrollPosition = Status->ParentScrollPositionLev1;
			break;

		case HMI_SUB_MENU_LEVEL3:

			/* Modify sub menu level */
			Status->SubMenuLevel = HMI_SUB_MENU_LEVEL2;

			/* Restore parent item data */
			Status->MenuItemID = Status->ParentMenuItemIDLev2;
			Status->CursorPosition = Status->ParentCursorPositionLev2;
			Status->ScrollPosition = Status->ParentScrollPositionLev2;
			break;

		case HMI_SUB_MENU_LEVEL4:

			/* Modify sub menu level */
			Status->SubMenuLevel = HMI_SUB_MENU_LEVEL3;

			/* Restore parent item data */
			Status->MenuItemID = Status->ParentMenuItemIDLev3;
			Status->CursorPosition = Status->ParentCursorPositionLev3;
			Status->ScrollPosition = Status->ParentScrollPositionLev3;
			break;

		default:;
		}

		/* Set switch to the initial position */
		Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
	}
}



void HMI_BrowseMenu(ENCODER_Command *Command, HMI_Status *Status)
{
	MENU_ItemType CurrItemType;
	uint8_t lastLine;
	uint8_t selectedLine;
	
	CurrItemType = MENU_GetItemType(Status->MenuItemID);
	lastLine = MENU_GetLastLine(Status->MenuItemID);
	selectedLine = Status->CursorPosition + Status->ScrollPosition;
	
	
	switch (*Command)
	{
		case ENCODER_CMD_CW:
		{
			if (selectedLine < lastLine)
			{
				if ((Status->CursorPosition) == HMI_CURSOR_IN_LINE4)
				{
					if ((Status->ScrollPosition) < HMI_SCROLL_X21) (Status->ScrollPosition)++;
				}
				else (Status->CursorPosition)++;
			}
		}
		break;
		
		case ENCODER_CMD_CCW:
		{
			if (selectedLine > 1)
			{
				if ((Status->CursorPosition) == HMI_CURSOR_IN_LINE1)
				{
					if ((Status->ScrollPosition) > HMI_SCROLL_X0) (Status->ScrollPosition)--;
				}
				else (Status->CursorPosition)--;
			}
		}			
		break;
		
		case ENCODER_CMD_PUSH:
		{
			if (selectedLine == lastLine) HMI_ReturnToParentItem(Status);
			else
			{
				switch (CurrItemType)
				{
					case MENU_SUB_ITEM:			HMI_EnterSubItem(Status, selectedLine);	break;
					case MENU_SETTINGS_ITEM:	Status->Mode = HMI_CHANGE;				break;
					case MENU_DATE_TIME_ITEM:	Status->Mode = HMI_CHANGE;				break;
					case MENU_CONTROL_ITEM:		Status->Mode = HMI_CHANGE;				break;
					case MENU_INFO_ITEM:		Status->Mode = HMI_CHANGE;				break;
					default:;
				}
			}
		}
		break;
	}
}



void HMI_ChangeSetting(ENCODER_Command *Command, HMI_Status *Status, SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle)
{
	SETTING_Query Query;

	switch (*Command)
	{
		case ENCODER_CMD_PUSH:
		{
			/* Finish changing and return to watch mode */
			Status->Mode = HMI_WATCH;
		}
		break;

		case ENCODER_CMD_CW:
		{
			/* Prepare query to increase setting */
			Query.ArrayID = MENU_GetSettingArrayID(Status->MenuItemID);
			Query.number = Status->CursorPosition + Status->ScrollPosition;
			Query.Direction = SETTING_INCREASE;

			/* Change setting and send updated setting values to the queue */
			SETTING_ChangeValue(Query, SettingValues);
			xQueueOverwrite(SettingValuesQueueHandle, SettingValues);
		}
		break;

		case ENCODER_CMD_CCW:
		{
			/* Prepare query to decrease setting */
			Query.ArrayID = MENU_GetSettingArrayID(Status->MenuItemID);
			Query.number = Status->CursorPosition + Status->ScrollPosition;
			Query.Direction = SETTING_DECREASE;

			/* Change setting and send updated setting values to the queue */
			SETTING_ChangeValue(Query, SettingValues);
			xQueueOverwrite(SettingValuesQueueHandle, SettingValues);
		}
		break;
	}
}



void HMI_TurnOffVentAutoCtrl(SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle)
{
	SETTING_Query Query;

	/* Turn off air heater auto control */
	/* Prepare query to increase setting */
	Query.ArrayID = SETTING_ARRAY_03;
	Query.number = 2;
	Query.Direction = SETTING_WRITE_DIRECTLY;
	Query.directValue = 0;

	/* Change setting and send updated setting values to the queue */
	SETTING_ChangeValue(Query, SettingValues);
	xQueueOverwrite(SettingValuesQueueHandle, SettingValues);

	/* Turn off intake ventilation auto control */
	/* Prepare query to increase setting */
	Query.number = 1;

	/* Change setting and send updated setting values to the queue */
	SETTING_ChangeValue(Query, SettingValues);
	xQueueOverwrite(SettingValuesQueueHandle, SettingValues);

	/* Turn off exhaust ventilation auto control */
	/* Prepare query to increase setting */
	Query.number = 3;

	/* Change setting and send updated setting values to the queue */
	SETTING_ChangeValue(Query, SettingValues);
	xQueueOverwrite(SettingValuesQueueHandle, SettingValues);
}



uint8_t HMI_CalcLastDate(RTC_DateTypeDef Date)
{
	uint8_t lastDate = 0;

	/* Calculate last date */
	switch (Date.Month)
	{
	case 1:   lastDate = 31; break;
	case 2:
		{
			/* Determine a leap year */
			if (((Date.Year) % 4) == 0) lastDate = 29;
			else lastDate = 28;
		}
		break;
	case 3:  lastDate = 31; break;
	case 4:  lastDate = 30; break;
	case 5:  lastDate = 31; break;
	case 6:  lastDate = 30; break;
	case 7:  lastDate = 31; break;
	case 8:  lastDate = 31; break;
	case 9:  lastDate = 30; break;
	case 10: lastDate = 31; break;
	case 11: lastDate = 30; break;
	case 12: lastDate = 31; break;
	default:;
	}

	return lastDate;
}



void HMI_ChangeDate(ENCODER_Command *Command, HMI_Status *Status, RTC_HandleTypeDef *HandleRTC)
{
	RTC_DateTypeDef Date;
	uint8_t lastDate = 0;
	
	switch (*Command)
	{
		case ENCODER_CMD_PUSH:
		{
			/* If switch in end position return to watch mode */
			if ((Status->SwitchPosition) >= HMI_SWITCH_IN_COLUMN3)
			{
				Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
				Status->Mode = HMI_WATCH;
			}
			/* Else increase switch position */
			else (Status->SwitchPosition)++;
		}
		break;
	
		case ENCODER_CMD_CW:
		{
			/* Get current date */
			HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);

			/* Increase date, month, year or weekday */
			switch (Status->SwitchPosition)
			{
				case HMI_SWITCH_IN_COLUMN1:
				{
					if (Date.Year >= 99) Date.Year = 0;
					else Date.Year++;

					/* If there is no such date in this year, correct the date */
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date > lastDate) Date.Date = lastDate;
				}
				break;

				case HMI_SWITCH_IN_COLUMN2:
				{
					if (Date.Month >= 12) Date.Month = 1;
					else Date.Month++;

					/* If there is no such date in this month, correct the date */
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date > lastDate) Date.Date = lastDate;
				}
				break;
				
				case HMI_SWITCH_IN_COLUMN3:
				{
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date >= lastDate) Date.Date = 1;
					else Date.Date++;
				}
				break;
				
				default:;
			}

			/* Set new date */
			HAL_RTC_SetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
		}
		break;
		
		case ENCODER_CMD_CCW:
		{
			/* Get current date */
			HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);

			/* Decrease date, month, year or weekday */
			switch (Status->SwitchPosition)
			{
				case HMI_SWITCH_IN_COLUMN1:
				{
					if (Date.Year <= 0) Date.Year = 99;
					else Date.Year--;

					/* If there is no such date in this year, correct the date */
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date > lastDate) Date.Date = lastDate;
				}
				break;

				case HMI_SWITCH_IN_COLUMN2:
				{
					if (Date.Month <= 1) Date.Month = 12;
					else Date.Month--;

					/* If there is no such date in this month, correct the date */
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date > lastDate) Date.Date = lastDate;
				}
				break;
				
				case HMI_SWITCH_IN_COLUMN3:
				{
					lastDate = HMI_CalcLastDate(Date);
					if (Date.Date <= 1) Date.Date = lastDate;
					else Date.Date--;
				}
				break;
				
				default:;
			}

			/* Set new date */
			HAL_RTC_SetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
		}
		break;
	}	
}



void HMI_ChangeTime(ENCODER_Command *Command, HMI_Status *Status, RTC_HandleTypeDef *HandleRTC)
{
	RTC_TimeTypeDef Time;
				
	switch (*Command)
	{
		case ENCODER_CMD_PUSH:
		{
			/* If switch in end position return to watch mode */
			if ((Status->SwitchPosition) >= HMI_SWITCH_IN_COLUMN3)
			{
				Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
				Status->Mode = HMI_WATCH;
			}
			/* Else increase switch position */
			else (Status->SwitchPosition)++;
		}
		break;

		case ENCODER_CMD_CW:
		{
			/* Get current time */
			HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);

			/* Increase hour, minute or second */
			switch (Status->SwitchPosition)
			{
				case HMI_SWITCH_IN_COLUMN1:
				{
					if (Time.Hours >= 23) Time.Hours = 0;
					else Time.Hours++;
				}
				break;

				case HMI_SWITCH_IN_COLUMN2:
				{
					if (Time.Minutes >= 59) Time.Minutes = 0;
					else Time.Minutes++;
				}
				break;

				case HMI_SWITCH_IN_COLUMN3:
				{
					if (Time.Seconds >= 59) Time.Seconds = 0;
					else Time.Seconds++;
				}
				break;

				default:;
			}

			/* Set new time */
			HAL_RTC_SetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
		}
		break;

		case ENCODER_CMD_CCW:
		{
			/* Get current time */
			HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);

			/* Decrease hour, minute or second */
			switch (Status->SwitchPosition)
			{
				case HMI_SWITCH_IN_COLUMN1:
				{
					if (Time.Hours <= 0) Time.Hours = 23;
					else Time.Hours--;
				}
				break;

				case HMI_SWITCH_IN_COLUMN2:
				{
					if (Time.Minutes <= 0) Time.Minutes = 59;
					else Time.Minutes--;
				}
				break;

				case HMI_SWITCH_IN_COLUMN3:
				{
					if (Time.Seconds <= 0) Time.Seconds = 59;
					else Time.Seconds--;
				}
				break;

				default:;
			}

			/* Set new time */
			HAL_RTC_SetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
		}
		break;
	}
}



void HMI_ChangeDateTime(ENCODER_Command *Command, HMI_Status *Status, RTC_HandleTypeDef *HandleRTC)
{
	switch (Status->CursorPosition)
	{
		case HMI_CURSOR_IN_LINE1: HMI_ChangeDate(Command, Status, HandleRTC); break;
		case HMI_CURSOR_IN_LINE2: HMI_ChangeTime(Command, Status, HandleRTC); break;
		default:;
	}
}



void HMI_DoAction(ENCODER_Command *Command, HMI_Status *Status, SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle)
{
	uint8_t selectedLine;

	switch (*Command)
	{
		case ENCODER_CMD_PUSH:
		{
			/* If switch in YES position, do appropriate action */
			if ((Status->SwitchPosition) == HMI_SWITCH_IN_COLUMN2)
			{
				/* Calculate selected line in menu item */
				selectedLine = Status->CursorPosition + Status->ScrollPosition;

				/* Select appropriate action */
				switch (selectedLine)
				{
					case 1:
						/* Save settings */
						SETTING_Save(SettingValues);
						break;

					case 2:
						/* Load default setting values and send them to the queue */
						SETTING_LoadDefaults(SettingValues);
						xQueueOverwrite(SettingValuesQueueHandle, SettingValues);
						break;

					default:;
				}
			}

			/* Reset switch position */
			Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;

			/* Return to watch mode */
			Status->Mode = HMI_WATCH;
		}
		break;

		case ENCODER_CMD_CW:
		{
			/* Move switch to YES position */
			if ((Status->SwitchPosition) < HMI_SWITCH_IN_COLUMN2) Status->SwitchPosition = HMI_SWITCH_IN_COLUMN2;
		}
		break;

		case ENCODER_CMD_CCW:
		{
			/* Move switch to NO position */
			if ((Status->SwitchPosition) > HMI_SWITCH_IN_COLUMN1) Status->SwitchPosition = HMI_SWITCH_IN_COLUMN1;
		}
		break;
	}
}



void HMI_HandleMenu(ENCODER_Command *Command, HMI_Status *Status, SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle, RTC_HandleTypeDef *HandleRTC)
{
	MENU_ItemType ItemType;
	
	Status->Updating = HMI_UPDATED;

	switch (Status->Mode)
	{
		case HMI_WATCH: HMI_BrowseMenu(Command, Status); break;
		case HMI_CHANGE:
		{
			ItemType = MENU_GetItemType(Status->MenuItemID);
		
			switch (ItemType)
			{
				case MENU_SETTINGS_ITEM:	HMI_ChangeSetting(Command, Status, SettingValues, SettingValuesQueueHandle);	break;
				case MENU_DATE_TIME_ITEM:	HMI_ChangeDateTime(Command, Status, HandleRTC);									break;
				case MENU_CONTROL_ITEM:		HMI_DoAction(Command, Status, SettingValues, SettingValuesQueueHandle);			break;
				case MENU_INFO_ITEM:		if (*Command == ENCODER_CMD_PUSH) Status->Mode = HMI_WATCH;						break;
				default:;
			}
		}
		break;

		default:;
	}	
}



void HMI_SaveDate(RTC_HandleTypeDef *HandleRTC)
{
	RTC_DateTypeDef Date;

	/* Get current date */
	HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);

	/* Write current date to the backup registers */
	HAL_RTCEx_BKUPWrite(HandleRTC, RTC_BKP_DR1, (uint32_t)Date.Date);
	HAL_RTCEx_BKUPWrite(HandleRTC, RTC_BKP_DR2, (uint32_t)Date.Month);
	HAL_RTCEx_BKUPWrite(HandleRTC, RTC_BKP_DR3, (uint32_t)Date.Year);

	/* Write verification code to the backup register */
	HAL_RTCEx_BKUPWrite(HandleRTC, RTC_BKP_DR4, (uint32_t)12321);
}



void HMI_RestoreDate(RTC_HandleTypeDef *HandleRTC)
{
	RTC_DateTypeDef Date;
	uint32_t code = 0;

	/* Enable access to the backup registers */
	HAL_PWR_EnableBkUpAccess();

	/* Read verification code */
	code = HAL_RTCEx_BKUPRead(HandleRTC, RTC_BKP_DR4);

	/* If the code is OK read saved date, else use default date */
	if (code == 12321)
	{
		Date.Date = (uint8_t)HAL_RTCEx_BKUPRead(HandleRTC, RTC_BKP_DR1);
		Date.Month = (uint8_t)HAL_RTCEx_BKUPRead(HandleRTC, RTC_BKP_DR2);
		Date.Year = (uint8_t)HAL_RTCEx_BKUPRead(HandleRTC, RTC_BKP_DR3);
	}
	else
	{
		Date.Date = 1;
		Date.Month = RTC_MONTH_JANUARY;
		Date.Year = 20;
	}

	/* Set date */
	HAL_RTC_SetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
}
