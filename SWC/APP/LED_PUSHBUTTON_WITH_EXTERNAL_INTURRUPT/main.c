/*
 * main.c
 *
 *  Created on: Jan 27, 2023
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


LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
int main(void)
{
	DIO_enuInit();
	GIE_enuEnable();
	EXTI_enuInt0Init();



    while (1)
    {

}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
LED_enuLED_ON(Led0);
Delay_ms(500);
LED_enuLED_OFF(Led0);

}

