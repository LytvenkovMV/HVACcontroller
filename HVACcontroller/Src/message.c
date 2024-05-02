
#include "message.h"
#include "message_config.h"



void MESSAGE_Send(MESSAGE_ID ID, osMessageQId *MessageQueueHandle, RTC_HandleTypeDef *HandleRTC, uint16_t const waitingTimeMs)
{
	RTC_DateTypeDef Date;
	RTC_TimeTypeDef Time;
	MESSAGE_Struct Message;
	
	HAL_RTC_GetTime(HandleRTC, &Time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(HandleRTC, &Date, RTC_FORMAT_BIN);
	
	Message.Time = Time;
	Message.Date = Date;
	Message.ID = ID;
	
	xQueueSend(MessageQueueHandle, &Message, waitingTimeMs);
}



MESSAGE_Sender MESSAGE_GetSenderID(MESSAGE_ID ID)
{
	if      (ID == MESSAGE_01) return MESSAGE_CONF_MESS01_SENDER;
	else if (ID == MESSAGE_02) return MESSAGE_CONF_MESS02_SENDER;
	else if (ID == MESSAGE_03) return MESSAGE_CONF_MESS03_SENDER;
	else if (ID == MESSAGE_04) return MESSAGE_CONF_MESS04_SENDER;
	else if (ID == MESSAGE_05) return MESSAGE_CONF_MESS05_SENDER;
	else if (ID == MESSAGE_06) return MESSAGE_CONF_MESS06_SENDER;
	else if (ID == MESSAGE_07) return MESSAGE_CONF_MESS07_SENDER;
	else if (ID == MESSAGE_08) return MESSAGE_CONF_MESS08_SENDER;
	else if (ID == MESSAGE_09) return MESSAGE_CONF_MESS09_SENDER;
	else if (ID == MESSAGE_10) return MESSAGE_CONF_MESS10_SENDER;
	else if (ID == MESSAGE_11) return MESSAGE_CONF_MESS11_SENDER;
	else if (ID == MESSAGE_12) return MESSAGE_CONF_MESS12_SENDER;
	else if (ID == MESSAGE_13) return MESSAGE_CONF_MESS13_SENDER;
	else if (ID == MESSAGE_14) return MESSAGE_CONF_MESS14_SENDER;
	else if (ID == MESSAGE_15) return MESSAGE_CONF_MESS15_SENDER;
	else if (ID == MESSAGE_16) return MESSAGE_CONF_MESS16_SENDER;
	else if (ID == MESSAGE_17) return MESSAGE_CONF_MESS17_SENDER;
	else if (ID == MESSAGE_18) return MESSAGE_CONF_MESS18_SENDER;
	else if (ID == MESSAGE_19) return MESSAGE_CONF_MESS19_SENDER;
	else if (ID == MESSAGE_20) return MESSAGE_CONF_MESS20_SENDER;
	else if (ID == MESSAGE_21) return MESSAGE_CONF_MESS21_SENDER;
	else if (ID == MESSAGE_22) return MESSAGE_CONF_MESS22_SENDER;
	else if (ID == MESSAGE_23) return MESSAGE_CONF_MESS23_SENDER;
	else if (ID == MESSAGE_24) return MESSAGE_CONF_MESS24_SENDER;
	else if (ID == MESSAGE_25) return MESSAGE_CONF_MESS25_SENDER;
	else if (ID == MESSAGE_26) return MESSAGE_CONF_MESS26_SENDER;
	else if (ID == MESSAGE_27) return MESSAGE_CONF_MESS27_SENDER;
	else if (ID == MESSAGE_28) return MESSAGE_CONF_MESS28_SENDER;
	else if (ID == MESSAGE_29) return MESSAGE_CONF_MESS29_SENDER;
	else if (ID == MESSAGE_30) return MESSAGE_CONF_MESS30_SENDER;
	
	return MESSAGE_CONF_MESS01_SENDER;
}



void MESSAGE_GetLine1(MESSAGE_ID ID, char line[24])
{
	if      (ID == MESSAGE_01) strcpy(line, MESSAGE_CONF_MESS01_LINE1);
	else if (ID == MESSAGE_02) strcpy(line, MESSAGE_CONF_MESS02_LINE1);
	else if (ID == MESSAGE_03) strcpy(line, MESSAGE_CONF_MESS03_LINE1);
	else if (ID == MESSAGE_04) strcpy(line, MESSAGE_CONF_MESS04_LINE1);
	else if (ID == MESSAGE_05) strcpy(line, MESSAGE_CONF_MESS05_LINE1);
	else if (ID == MESSAGE_06) strcpy(line, MESSAGE_CONF_MESS06_LINE1);
	else if (ID == MESSAGE_07) strcpy(line, MESSAGE_CONF_MESS07_LINE1);
	else if (ID == MESSAGE_08) strcpy(line, MESSAGE_CONF_MESS08_LINE1);
	else if (ID == MESSAGE_09) strcpy(line, MESSAGE_CONF_MESS09_LINE1);
	else if (ID == MESSAGE_10) strcpy(line, MESSAGE_CONF_MESS10_LINE1);
	else if (ID == MESSAGE_11) strcpy(line, MESSAGE_CONF_MESS11_LINE1);
	else if (ID == MESSAGE_12) strcpy(line, MESSAGE_CONF_MESS12_LINE1);
	else if (ID == MESSAGE_13) strcpy(line, MESSAGE_CONF_MESS13_LINE1);
	else if (ID == MESSAGE_14) strcpy(line, MESSAGE_CONF_MESS14_LINE1);
	else if (ID == MESSAGE_15) strcpy(line, MESSAGE_CONF_MESS15_LINE1);
	else if (ID == MESSAGE_16) strcpy(line, MESSAGE_CONF_MESS16_LINE1);
	else if (ID == MESSAGE_17) strcpy(line, MESSAGE_CONF_MESS17_LINE1);
	else if (ID == MESSAGE_18) strcpy(line, MESSAGE_CONF_MESS18_LINE1);
	else if (ID == MESSAGE_19) strcpy(line, MESSAGE_CONF_MESS19_LINE1);
	else if (ID == MESSAGE_20) strcpy(line, MESSAGE_CONF_MESS20_LINE1);
	else if (ID == MESSAGE_21) strcpy(line, MESSAGE_CONF_MESS21_LINE1);
	else if (ID == MESSAGE_22) strcpy(line, MESSAGE_CONF_MESS22_LINE1);
	else if (ID == MESSAGE_23) strcpy(line, MESSAGE_CONF_MESS23_LINE1);
	else if (ID == MESSAGE_24) strcpy(line, MESSAGE_CONF_MESS24_LINE1);
	else if (ID == MESSAGE_25) strcpy(line, MESSAGE_CONF_MESS25_LINE1);
	else if (ID == MESSAGE_26) strcpy(line, MESSAGE_CONF_MESS26_LINE1);
	else if (ID == MESSAGE_27) strcpy(line, MESSAGE_CONF_MESS27_LINE1);
	else if (ID == MESSAGE_28) strcpy(line, MESSAGE_CONF_MESS28_LINE1);
	else if (ID == MESSAGE_29) strcpy(line, MESSAGE_CONF_MESS29_LINE1);
	else if (ID == MESSAGE_30) strcpy(line, MESSAGE_CONF_MESS30_LINE1);
	else strcpy(line, "");
}



void MESSAGE_GetLine2(MESSAGE_ID ID, char line[24])
{
	if      (ID == MESSAGE_01) strcpy(line, MESSAGE_CONF_MESS01_LINE2);
	else if (ID == MESSAGE_02) strcpy(line, MESSAGE_CONF_MESS02_LINE2);
	else if (ID == MESSAGE_03) strcpy(line, MESSAGE_CONF_MESS03_LINE2);
	else if (ID == MESSAGE_04) strcpy(line, MESSAGE_CONF_MESS04_LINE2);
	else if (ID == MESSAGE_05) strcpy(line, MESSAGE_CONF_MESS05_LINE2);
	else if (ID == MESSAGE_06) strcpy(line, MESSAGE_CONF_MESS06_LINE2);
	else if (ID == MESSAGE_07) strcpy(line, MESSAGE_CONF_MESS07_LINE2);
	else if (ID == MESSAGE_08) strcpy(line, MESSAGE_CONF_MESS08_LINE2);
	else if (ID == MESSAGE_09) strcpy(line, MESSAGE_CONF_MESS09_LINE2);
	else if (ID == MESSAGE_10) strcpy(line, MESSAGE_CONF_MESS10_LINE2);
	else if (ID == MESSAGE_11) strcpy(line, MESSAGE_CONF_MESS11_LINE2);
	else if (ID == MESSAGE_12) strcpy(line, MESSAGE_CONF_MESS12_LINE2);
	else if (ID == MESSAGE_13) strcpy(line, MESSAGE_CONF_MESS13_LINE2);
	else if (ID == MESSAGE_14) strcpy(line, MESSAGE_CONF_MESS14_LINE2);
	else if (ID == MESSAGE_15) strcpy(line, MESSAGE_CONF_MESS15_LINE2);
	else if (ID == MESSAGE_16) strcpy(line, MESSAGE_CONF_MESS16_LINE2);
	else if (ID == MESSAGE_17) strcpy(line, MESSAGE_CONF_MESS17_LINE2);
	else if (ID == MESSAGE_18) strcpy(line, MESSAGE_CONF_MESS18_LINE2);
	else if (ID == MESSAGE_19) strcpy(line, MESSAGE_CONF_MESS19_LINE2);
	else if (ID == MESSAGE_20) strcpy(line, MESSAGE_CONF_MESS20_LINE2);
	else if (ID == MESSAGE_21) strcpy(line, MESSAGE_CONF_MESS21_LINE2);
	else if (ID == MESSAGE_22) strcpy(line, MESSAGE_CONF_MESS22_LINE2);
	else if (ID == MESSAGE_23) strcpy(line, MESSAGE_CONF_MESS23_LINE2);
	else if (ID == MESSAGE_24) strcpy(line, MESSAGE_CONF_MESS24_LINE2);
	else if (ID == MESSAGE_25) strcpy(line, MESSAGE_CONF_MESS25_LINE2);
	else if (ID == MESSAGE_27) strcpy(line, MESSAGE_CONF_MESS27_LINE2);
	else if (ID == MESSAGE_28) strcpy(line, MESSAGE_CONF_MESS28_LINE2);
	else if (ID == MESSAGE_29) strcpy(line, MESSAGE_CONF_MESS29_LINE2);
	else if (ID == MESSAGE_30) strcpy(line, MESSAGE_CONF_MESS30_LINE2);
	else strcpy(line, "");
}



void MESSAGE_GetLine3(MESSAGE_ID ID, char line[24])
{
	if      (ID == MESSAGE_01) strcpy(line, MESSAGE_CONF_MESS01_LINE3);
	else if (ID == MESSAGE_02) strcpy(line, MESSAGE_CONF_MESS02_LINE3);
	else if (ID == MESSAGE_03) strcpy(line, MESSAGE_CONF_MESS03_LINE3);
	else if (ID == MESSAGE_04) strcpy(line, MESSAGE_CONF_MESS04_LINE3);
	else if (ID == MESSAGE_05) strcpy(line, MESSAGE_CONF_MESS05_LINE3);
	else if (ID == MESSAGE_06) strcpy(line, MESSAGE_CONF_MESS06_LINE3);
	else if (ID == MESSAGE_07) strcpy(line, MESSAGE_CONF_MESS07_LINE3);
	else if (ID == MESSAGE_08) strcpy(line, MESSAGE_CONF_MESS08_LINE3);
	else if (ID == MESSAGE_09) strcpy(line, MESSAGE_CONF_MESS09_LINE3);
	else if (ID == MESSAGE_10) strcpy(line, MESSAGE_CONF_MESS10_LINE3);
	else if (ID == MESSAGE_11) strcpy(line, MESSAGE_CONF_MESS11_LINE3);
	else if (ID == MESSAGE_12) strcpy(line, MESSAGE_CONF_MESS12_LINE3);
	else if (ID == MESSAGE_13) strcpy(line, MESSAGE_CONF_MESS13_LINE3);
	else if (ID == MESSAGE_14) strcpy(line, MESSAGE_CONF_MESS14_LINE3);
	else if (ID == MESSAGE_15) strcpy(line, MESSAGE_CONF_MESS15_LINE3);
	else if (ID == MESSAGE_16) strcpy(line, MESSAGE_CONF_MESS16_LINE3);
	else if (ID == MESSAGE_17) strcpy(line, MESSAGE_CONF_MESS17_LINE3);
	else if (ID == MESSAGE_18) strcpy(line, MESSAGE_CONF_MESS18_LINE3);
	else if (ID == MESSAGE_19) strcpy(line, MESSAGE_CONF_MESS19_LINE3);
	else if (ID == MESSAGE_20) strcpy(line, MESSAGE_CONF_MESS20_LINE3);
	else if (ID == MESSAGE_21) strcpy(line, MESSAGE_CONF_MESS21_LINE3);
	else if (ID == MESSAGE_22) strcpy(line, MESSAGE_CONF_MESS22_LINE3);
	else if (ID == MESSAGE_23) strcpy(line, MESSAGE_CONF_MESS23_LINE3);
	else if (ID == MESSAGE_24) strcpy(line, MESSAGE_CONF_MESS24_LINE3);
	else if (ID == MESSAGE_25) strcpy(line, MESSAGE_CONF_MESS25_LINE3);
	else if (ID == MESSAGE_26) strcpy(line, MESSAGE_CONF_MESS26_LINE3);
	else if (ID == MESSAGE_27) strcpy(line, MESSAGE_CONF_MESS27_LINE3);
	else if (ID == MESSAGE_28) strcpy(line, MESSAGE_CONF_MESS28_LINE3);
	else if (ID == MESSAGE_29) strcpy(line, MESSAGE_CONF_MESS29_LINE3);
	else if (ID == MESSAGE_30) strcpy(line, MESSAGE_CONF_MESS30_LINE3);
	else strcpy(line, "");
}
