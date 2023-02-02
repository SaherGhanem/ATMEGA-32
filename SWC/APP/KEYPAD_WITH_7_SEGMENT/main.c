/*
 * main.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Saher Ghanem
 */
#include "Std_types.h"
#include "DIO.h"
#include "Delay_Interface.h"
#include "KEYPAD.h"
#include "7_Segment.h"

void main(void){
u8 Local_u8Key;
DIO_enuInit();
while(1)
{
	do{
		Local_u8Key=KPD_u8GetPressedKey();
	}while(Local_u8Key==KPD_NO_PRESSED_KEY);

	_7_SEG_enuSEG_(DIO_PORTB,Local_u8Key);
}



}
