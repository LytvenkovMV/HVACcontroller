
#include "string.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal.h"



#ifndef __message_h
#define __message_h

/* Message sender */
typedef enum
{
	MESSAGE_SENDER_HEATING,
	MESSAGE_SENDER_VENTILATION,
	MESSAGE_SENDER_03,
	MESSAGE_SENDER_04,
	MESSAGE_SENDER_05,
} MESSAGE_Sender;

/* Message ID */
typedef enum
{
	MESSAGE_01,
	MESSAGE_02,
	MESSAGE_03,
	MESSAGE_04,
	MESSAGE_05,
	MESSAGE_06,
	MESSAGE_07,
	MESSAGE_08,
	MESSAGE_09,
	MESSAGE_10,
	MESSAGE_11,
	MESSAGE_12,
	MESSAGE_13,
	MESSAGE_14,
	MESSAGE_15,
	MESSAGE_16,
	MESSAGE_17,
	MESSAGE_18,
	MESSAGE_19,
	MESSAGE_20,
	MESSAGE_21,
	MESSAGE_22,
	MESSAGE_23,
	MESSAGE_24,
	MESSAGE_25,
	MESSAGE_26,
	MESSAGE_27,
	MESSAGE_28,
	MESSAGE_29,
	MESSAGE_30
} MESSAGE_ID;

/* Message structure */
typedef struct
{
	MESSAGE_ID ID;
	RTC_DateTypeDef Date;
	RTC_TimeTypeDef Time;
} MESSAGE_Struct;

/* Send message to the queue */
void MESSAGE_Send(MESSAGE_ID ID, osMessageQId *MessageQueueHandle, RTC_HandleTypeDef *HandleRTC, uint16_t const waitingTimeMs);

/* Get sender by message ID */
MESSAGE_Sender MESSAGE_GetSenderID(MESSAGE_ID ID);

/* Get line1 */
void MESSAGE_GetLine1(MESSAGE_ID ID, char line[24]);

/* Get line2 */
void MESSAGE_GetLine2(MESSAGE_ID ID, char line[24]);

/* Get line3 */
void MESSAGE_GetLine3(MESSAGE_ID ID, char line[24]);

#endif /* __message_h */

/* end of message.h */
