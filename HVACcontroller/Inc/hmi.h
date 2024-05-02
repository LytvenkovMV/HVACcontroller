
#include "cmsis_os.h"
#include "encoder.h"
#include "menu.h"
#include "setting.h"
#include "message.h"
#include "heating.h"



#ifndef __hmi_h
#define __hmi_h

/* Waiting time for change setting in milliseconds */
#define HMI_SETTING_CHANGE_TIME_MS		50

/* HMI status of updating */
typedef enum
{
	HMI_NOT_UPDATED,
	HMI_UPDATED
} HMI_Updating;

/* HMI mode: watch or change settings */
typedef enum
{
	HMI_WATCH,
	HMI_CHANGE
} HMI_Mode;

/* HMI dialog direction */
typedef enum
{
	HMI_RIGHT,
	HMI_LEFT
} HMI_DialogDirection;

/* HMI screen type */
typedef enum
{
	HMI_INITIAL_SCREEN,
	HMI_MENU_SCREEN,
	HMI_MESSAGE_SCREEN
} HMI_ScreenType;

/* HMI cursor position */
typedef enum
{
	HMI_CURSOR_IN_LINE1 = 1,
	HMI_CURSOR_IN_LINE2 = 2,
	HMI_CURSOR_IN_LINE3 = 3,
	HMI_CURSOR_IN_LINE4 = 4
} HMI_CursorPosition;

/* HMI switch position */
typedef enum
{
	HMI_SWITCH_IN_COLUMN1 = 1,
	HMI_SWITCH_IN_COLUMN2 = 2,
	HMI_SWITCH_IN_COLUMN3 = 3,
	HMI_SWITCH_IN_COLUMN4 = 4,
} HMI_SwitchPosition;

/* HMI scroll direction */
typedef enum
{
	HMI_SCROLL_UP,
	HMI_SCROLL_DOWN
} HMI_ScrollDirection;

/* HMI item scroll position */
typedef enum
{
	HMI_SCROLL_X0,
	HMI_SCROLL_X1,
	HMI_SCROLL_X2,
	HMI_SCROLL_X3,
	HMI_SCROLL_X4,
	HMI_SCROLL_X5,
	HMI_SCROLL_X6,
	HMI_SCROLL_X7,
	HMI_SCROLL_X8,
	HMI_SCROLL_X9,
	HMI_SCROLL_X10,
	HMI_SCROLL_X11,
	HMI_SCROLL_X12,
	HMI_SCROLL_X13,
	HMI_SCROLL_X14,
	HMI_SCROLL_X15,
	HMI_SCROLL_X16,
	HMI_SCROLL_X17,
	HMI_SCROLL_X18,
	HMI_SCROLL_X19,
	HMI_SCROLL_X20,
	HMI_SCROLL_X21
} HMI_ScrollPosition;

/* HMI sub menu level */
typedef enum
{
	HMI_SUB_MENU_LEVEL1,
	HMI_SUB_MENU_LEVEL2,
	HMI_SUB_MENU_LEVEL3,
	HMI_SUB_MENU_LEVEL4
} HMI_SubMenuLevel;


/* HMI status */
typedef struct
{
	HMI_Updating Updating;
	HMI_Mode Mode;
	HMI_ScreenType ScreenType;
	HMI_SubMenuLevel SubMenuLevel;
	HMI_ScrollPosition ScrollPosition;
	HMI_ScrollPosition ParentScrollPositionLev1;
	HMI_ScrollPosition ParentScrollPositionLev2;
	HMI_ScrollPosition ParentScrollPositionLev3;
	HMI_CursorPosition CursorPosition;
	HMI_CursorPosition ParentCursorPositionLev1;
	HMI_CursorPosition ParentCursorPositionLev2;
	HMI_CursorPosition ParentCursorPositionLev3;
	HMI_SwitchPosition SwitchPosition;
	MENU_ItemID MenuItemID;
	MENU_ItemID ParentMenuItemIDLev1;
	MENU_ItemID ParentMenuItemIDLev2;
	MENU_ItemID ParentMenuItemIDLev3;
	MESSAGE_ID MessageID;
	RTC_DateTypeDef MessageDate;
	RTC_TimeTypeDef MessageTime;
} HMI_Status;

/* Open initial screen */
void HMI_OpenInitial(HMI_Status *Status);

/* Open message screen */
void HMI_OpenMessage(HMI_Status *Status, MESSAGE_Struct *Message);

/* Clear message and reset the sending process */
void HMI_ClearMessage(HMI_Status *Status, MESSAGE_Struct *Message, osMessageQId *HeatingResetQueueHandle, osMessageQId *VentResetQueueHandle);

/* Open menu screen */
void HMI_OpenMenu(HMI_Status *Status);

/* Handle menu */
void HMI_HandleMenu(ENCODER_Command *Command, HMI_Status *Status, SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle, RTC_HandleTypeDef *HandleRTC);

/* Turn off ventilation auto control */
void HMI_TurnOffVentAutoCtrl(SETTING_Values *SettingValues, osMessageQId *SettingValuesQueueHandle);

/* Save current date in the backup registers */
void HMI_SaveDate(RTC_HandleTypeDef *HandleRTC);

/* Restore saved date from the backup registers */
void HMI_RestoreDate(RTC_HandleTypeDef *HandleRTC);

#endif /* __hmi_h */

/* end of hmi.h */
