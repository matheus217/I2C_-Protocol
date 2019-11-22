#define F_CPU 16000000UL
#include <avr/io.h>
#include "MasterOperationI2C.h"
#include <util/delay.h>
#include <math.h>
int main(void){
	DDRD = 0xFC;
    uint8_t Address = 0b00010001;
    uint8_t data;
	Master_begin();
    while(1){
        Master_Start();
        Master_Send(Address); 
        data = Master_Receive();
        Master_Stop(); 
		PORTD = (data & 0b11111100);
	   }
    }
	


