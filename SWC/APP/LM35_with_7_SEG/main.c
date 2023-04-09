/*
 * main.c

 *
 *  Created on: Feb 8, 2023
 *      Author: Saher Ghanem
 */

#include "Std_types.h"
#include "DIO.h"
#include "ADC.h"
#include "LM35.h"
#include "7_Segment.h"
#include "Delay_Interface.h"

void main(void){
	DIO_enuInit();
	ADC_voidInit();
	u16 Local_u8ADCReading;
	u8 Local_u8Temperature;
	while(1){


		ADC_u8StartConversionSynch(2,&Local_u8ADCReading);
		LM35_enuGetTemperature (Local_u8ADCReading ,  &Local_u8Temperature);
		_7_SEG_voidDIS(Local_u8Temperature);

}}
