/*
 * main.c
 *
 *  Created on: Jan 31, 2023
 *      Author: Saher Ghanem
 */


#include "Std_types.h"
#include "Bit_math.h"

#include "Delay_Interface.h"
#include "DIO.h"
#include "LED.h"
#include "PUSHBUTTON.h"
#include "GIE.h"
#include "EXTI.h"
#include "7_Segment.h"

u8 count=0;

int main(void)
{
	DIO_enuInit();
	GIE_enuEnable();
	EXTI_enuInt0Init();
	EXTI_enuInt1Init();




    while (1)
    {

}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{

	 count--;
  _7_SEG_enuSEG_(DIO_PORTB,count);
  Delay_ms(300);
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{


 _7_SEG_enuSEG_(DIO_PORTB,count);
	 count++;
	 Delay_ms(300);
}
