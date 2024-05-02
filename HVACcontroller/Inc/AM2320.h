
#include "i2cbus.h"



#ifndef __AM2320_h
#define __AM2320_h

/* AM2320 address */
#define AM2320_ADDRESS				(0xB8)

/* AM2320 status */
typedef enum
{
	AM2320_FAIL,
	AM2320_OK
} AM2320_Status;

/* Data received from AM2320 sensor */
typedef struct
{
	uint8_t functionCode;
	uint8_t numberOfBytes;
	uint8_t humidityHighByte;
	uint8_t humidityLowByte;
	uint8_t tempHighByte;
	uint8_t tempLowByte;
	uint8_t crcLowByte;
	uint8_t crcHighByte;
} AM2320_RXData;

/* AM2320 sensor state */
typedef struct
{
	AM2320_Status Status;
	uint16_t timeoutCnt;
	uint16_t errorsCnt;
} AM2320_State;

/* Initialize AM2320 sensor state */
void AM2320_Init(AM2320_State *State);

/* Wake AM2320 sensor */
void AM2320_Wake(uint8_t address);

/* Transmit query to AM2320 sensor */
I2CBUS_Result AM2320_TransmitQuery(uint8_t address);

/* Receive data from AM2320 sensor */
I2CBUS_Result AM2320_ReceiveData(uint8_t address, uint8_t buffer[8]);

/* Calculate CRC16 of the message */
uint16_t AM2320_CalcCRC16(uint8_t const message[6]);

/* Calculate the temperature value from the high and low temperature bytes */
int16_t AM2320_CalcTemp(uint8_t highByte, uint8_t lowByte);

/* Calculate the humidity value from the high and low humidity bytes */
uint16_t AM2320_CalcHumidity(uint8_t highByte, uint8_t lowByte);

#endif /* __AM2320_h */

/* end of AM2320.h */
