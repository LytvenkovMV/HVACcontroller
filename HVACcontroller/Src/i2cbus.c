
#include "i2cbus.h"



void I2CBUS_SDAToInputMode(void)
{
	/* Reset control bits for the pin */
	SDA_GPIO_Port->I2CBUS_SDA_CRx &= ~ (I2CBUS_SDA_GPIO_CRx_CNFx | I2CBUS_SDA_GPIO_CRx_MODEx);

	/* Configure pin's mode as floating input */
	SDA_GPIO_Port->I2CBUS_SDA_CRx |= (0b01 << I2CBUS_SDA_GPIO_CRx_CNFx_Pos) | (0b00 << I2CBUS_SDA_GPIO_CRx_MODEx_Pos);
}



void I2CBUS_SDAToOutputMode(void)
{
	/* Configure pin's output level */
	HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET);

	/* Reset control bits for the pin */
	SDA_GPIO_Port->I2CBUS_SDA_CRx &= ~ (I2CBUS_SDA_GPIO_CRx_CNFx | I2CBUS_SDA_GPIO_CRx_MODEx);

	/* Configure pin's mode as output with open drain */
	SDA_GPIO_Port->I2CBUS_SDA_CRx |= (0b01 << I2CBUS_SDA_GPIO_CRx_CNFx_Pos) | (0b01 << I2CBUS_SDA_GPIO_CRx_MODEx_Pos);
}



void I2CBUS_SendStart(void)
{
	I2CBUS_SDA_PUT_DOWN();
	I2CBUS_DELAY();
	I2CBUS_SCL_PUT_DOWN();
	I2CBUS_DELAY();
}



void I2CBUS_SendStop(void)
{
	I2CBUS_DELAY();
	I2CBUS_SCL_PUT_UP();
	I2CBUS_DELAY();
	I2CBUS_SDA_PUT_UP();
}



uint8_t I2CBUS_ReadBit(void)
{
	GPIO_PinState PinState = GPIO_PIN_RESET;

	PinState = HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin);

	if (PinState == GPIO_PIN_SET) return 1;

	return 0;
}



I2CBUS_Result I2CBUS_SendByte(uint8_t byte)
{
	I2CBUS_Result Result = I2CBUS_NACK;

	for (uint8_t i = 0; i < 8; i ++)
	{
		if (byte & 0b10000000) I2CBUS_SDA_PUT_UP();
		else I2CBUS_SDA_PUT_DOWN();

		I2CBUS_DELAY();
		I2CBUS_SCL_PUT_UP();
		I2CBUS_DELAY();
		I2CBUS_SCL_PUT_DOWN();

		byte = byte << 1;
	}

	/* Put up SDA */
	I2CBUS_SDA_PUT_UP();

	/* SDA to input mode */
	I2CBUS_SDAToInputMode();

	I2CBUS_DELAY();

	/* Put up SCL */
	I2CBUS_SCL_PUT_UP();

	/* Read ACK bit */
	if (I2CBUS_ReadBit() == 0) Result = I2CBUS_ACK;

	I2CBUS_DELAY();

	/* SDA to output mode */
	I2CBUS_SDAToOutputMode();

	/* Put down SCL */
	I2CBUS_SCL_PUT_DOWN();

	/* Put up SDA */
	I2CBUS_SDA_PUT_UP();
	I2CBUS_DELAY();

	/* Put down SDA */
	I2CBUS_SDA_PUT_DOWN();
	I2CBUS_DELAY();

	return Result;
}



uint8_t I2CBUS_ReceiveByte(I2CBUS_Result ReceiverAnswer)
{
	uint8_t result = 0, bit = 0, shift = 7;

	/* SDA to input mode */
	I2CBUS_SDAToInputMode();

	for (uint8_t i = 0; i < 8; i ++)
	{
		I2CBUS_DELAY();
		I2CBUS_SCL_PUT_UP();

		/* Read bit */
		bit = I2CBUS_ReadBit();

		/* Add bit to the result */
		result = result | (bit << shift);
		shift --;

		I2CBUS_DELAY();
		I2CBUS_SCL_PUT_DOWN();
	}

	/* SDA to output mode */
	I2CBUS_SDAToOutputMode();

	switch (ReceiverAnswer)
	{
	case I2CBUS_ACK:
		/* Send ACK */
		I2CBUS_SDA_PUT_DOWN();
		break;
	default:
		/* Send NACK */
		I2CBUS_SDA_PUT_UP();
	}

	I2CBUS_DELAY();

	/* Put up SCL */
	I2CBUS_SCL_PUT_UP();
	I2CBUS_DELAY();

	/* Put down SCL */
	I2CBUS_SCL_PUT_DOWN();

	/* Put up SDA */
	I2CBUS_SDA_PUT_UP();
	I2CBUS_DELAY();

	/* Put down SDA */
	I2CBUS_SDA_PUT_DOWN();
	I2CBUS_DELAY();

	/* Return result */
	return result;
}
