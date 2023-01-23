/*
 *
 * main.c

 *
 *  Created on: Jan 20, 2023
 *      Author: Saher Ghanem
 */
#include "Delay_Interface.h"
#include "DIO.h"
#include "7_Segment.h"

#include "Std_types.h"
#include "Bit_math.h"

int main(){




while(1){
//	_7_SEG_enuSEG_(DIO_PORTA,0);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,1);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,2);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,3);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,4);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,5);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,6);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,7);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,8);
//	Delay_ms(1000);
//	_7_SEG_enuSEG_(DIO_PORTA,9);
//	Delay_ms(1000);

	for(int i=0;i<10;i++){
		_7_SEG_enuSEG_(DIO_PORTA,i);
		for(int j=0;j<10;j++){

			_7_SEG_enuSEG_(DIO_PORTC,j);
			Delay_ms(250);

		}
		}

}
}
