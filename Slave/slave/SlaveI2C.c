#define F_CPU 16000000UL
#include <avr/io.h>
#include "SlaveOperationI2C.h"
#include <math.h>

int main(void){
	float seno,portadora;
    uint8_t Address = 0x10;
    uint8_t Data;
    Slave_Begin(Address);
    while(1){
		for(float i = 0; i<=6.28; i = i + 0.1){
			seno = 100*(sin(i)*cos(47*i)) + 127;
			Data = seno;
			TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
			Slave_Listen();
			Slave_Send(Data);
		}
    }
}

/* for(float i = 0; i<=6.28; i = i + 0.1){
seno = 100*sin(i) + 127;
Data = seno;
TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
Slave_Listen();
Slave_Send(Data);*/