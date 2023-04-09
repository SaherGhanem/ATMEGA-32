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
{
	DIO_enuInit();
	SPI_voidInitMaster();
	while(1)
	{
		SPI_u8Transcevie(1);
		Delay_ms(10);
		SPI_u8Transcevie(2);
		Delay_ms(10);

}
}
