#include <regx52.h>
#include "I2C.h"

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

void I2C_Start(void){
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}

void I2C_Stop(void){
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}
	
void I2C_SendByte(unsigned char Byte){ //发送数据
	unsigned char i;
	for(i=0;i<8;i++){
		I2C_SDA=Byte & (0x80 >> i);
		I2C_SCL=1;
		I2C_SDA=0;
	
	}
}


unsigned char I2C_ReceiveByte(void){ //接收数据
	unsigned char Byte;
	unsigned char i;
	I2C_SDA=1;
	I2C_SCL=1;
	for(i=0;i<8;i++){
		I2C_SCL=1;
		if(I2C_SDA) Byte |= (0x80 >> i);
		I2C_SCL=0;
	}
		
	
	return Byte;
}

void I2C_SendAck(bit Ackbit){ //发送应答
	I2C_SDA = Ackbit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}


unsigned char I2C_ReceiveACK(void){ //接收应答
	unsigned char Ackbit;
	I2C_SDA=1;
	I2C_SCL=1;
	Ackbit=I2C_SDA;
	I2C_SCL=0;
	return Ackbit;

}
	
	