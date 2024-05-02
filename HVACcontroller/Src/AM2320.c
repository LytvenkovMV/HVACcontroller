
#include "AM2320.h"



void AM2320_Init(AM2320_State *State)
{
	State->Status = AM2320_FAIL;
	State->timeoutCnt = 0;
	State->errorsCnt = 0;
}



void AM2320_Wake(uint8_t address)
{
	/* Send start condition */
	I2CBUS_SendStart();

	/* Send AM2320 address + write mode */
	I2CBUS_SendByte(address);

	/* Put down SDA */
	I2CBUS_SDA_PUT_DOWN();

	/* Wait 1 millisecond */
	osDelay(1);

	/* Send stop condition */
	I2CBUS_SendStop();
}



I2CBUS_Result AM2320_TransmitQuery(uint8_t address)
{
	I2CBUS_Result Result = I2CBUS_NACK;

	/* Send start condition */
	I2CBUS_SendStart();

	/* Send AM2320 address + write mode. If NACK send stop condition and return */
	Result = I2CBUS_SendByte(address);
	if (Result != I2CBUS_ACK)
	{
		I2CBUS_SendStop();
		return I2CBUS_NACK;
	}

	/* Wait 50 microseconds */
	USDELAY_50us();

	/* Send AM2320 function code. If NACK send stop condition and return */
	Result = I2CBUS_SendByte(0x03);
	if (Result != I2CBUS_ACK)
	{
		I2CBUS_SendStop();
		return I2CBUS_NACK;
	}

	/* Send AM2320 register address. If NACK send stop condition and return */
	Result = I2CBUS_SendByte(0x00);
	if (Result != I2CBUS_ACK)
	{
		I2CBUS_SendStop();
		return I2CBUS_NACK;
	}

	/* Send number of registers. If NACK send stop condition and return */
	Result = I2CBUS_SendByte(0x04);
	if (Result != I2CBUS_ACK)
	{
		I2CBUS_SendStop();
		return I2CBUS_NACK;
	}

	/* Send stop condition */
	I2CBUS_SendStop();

	/* Return ACK */
	return I2CBUS_ACK;
}



I2CBUS_Result AM2320_ReceiveData(uint8_t address, uint8_t buffer[8])
{
	I2CBUS_Result Result = I2CBUS_NACK;

	/* Send start condition */
	I2CBUS_SendStart();

	/* Send AM2320 address + read mode. If NACK send stop condition and return */
	Result = I2CBUS_SendByte(address | 0b00000001);
	if (Result != I2CBUS_ACK)
	{
		I2CBUS_SendStop();
		return I2CBUS_NACK;
	}

	/* Wait 50 microseconds */
	USDELAY_50us();

	/* Receive 7 bytes with ACK and 1 byte with NACK */
	buffer[0] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[1] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[2] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[3] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[4] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[5] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[6] = I2CBUS_ReceiveByte(I2CBUS_ACK);
	buffer[7] = I2CBUS_ReceiveByte(I2CBUS_NACK);

	/* Send stop condition */
	I2CBUS_SendStop();

	/* Return ACK */
	return I2CBUS_ACK;
}



uint16_t AM2320_CalcCRC16(uint8_t const message[6])
{
	uint16_t crc = 0xFFFF, CRC16_POLY = 0xA001;

	for (uint8_t i = 0; i < 6; i++)
	{
		crc = crc ^ message[i];

		for (uint8_t j = 0; j < 8; j++)
		{
		  if (crc & 1)
		  {
			  crc >>= 1;
			  crc = crc ^ CRC16_POLY;
		  }
		  else crc >>= 1;
		}
	}

	return crc;
}



int16_t AM2320_CalcTemp(uint8_t highByte, uint8_t lowByte)
{
	int16_t temperature = 0;

	if (highByte & 0b10000000) temperature = - ((highByte & 0b01111111) << 8) | lowByte;
	else temperature = (highByte << 8) | lowByte;

	return temperature;
}



uint16_t AM2320_CalcHumidity(uint8_t highByte, uint8_t lowByte)
{
	uint16_t humidity = 0;

	humidity = (highByte << 8) | lowByte;
	if ((humidity % 10) >= 5) humidity = (humidity / 10) + 1;
	else humidity = humidity / 10;

	return humidity;
}
