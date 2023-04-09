/*
 * main.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Saher Ghanem
 */


/*
 * main.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Saher Ghanem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "GIE.h"
#include "SPI.h"
#include "Delay_Interface.h"

#include "LED.h"
LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};

void main(void)
{   u8 Local_u8RecivedData;
	DIO_enuInit();
	SPI_voidInitSlave();
	while(1)
	{
		Local_u8RecivedData = SPI_u8Transcevie(1);
		Delay_ms(10);
		if(Local_u8RecivedData == 1)
		{
			LED_enuLED_ON(Led0);
			DIO_enuSetPin(DIO_enuPin1);


		}
		else if(Local_u8RecivedData == 2)
		{
			LED_enuLED_OFF(Led0);
			DIO_enuClearPin(DIO_enuPin1);
		}
	}
}
