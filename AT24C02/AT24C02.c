#include "AT24C02.h"
#define AT24C02_ADDRESS 0xA0
void AT24C02_WriteByte(unsigned char word_address,Data){
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveACK();
	I2C_SendByte(word_address);
	I2C_ReceiveACK();
	I2C_SendByte(Data);
	I2C_ReceiveACK();
	I2C_Stop();
}