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
#include "UART_interface.h"

#include "LED.h"
LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};

void main(void)
{
	u8 Data;
	DIO_enuInit();
	USART_voidInit();
	while(1)
	{
		Data = USART_u8Receive();
		if(Data == '1')
		{
			LED_enuLED_ON(Led0);
			DIO_enuSetPin(DIO_enuPin1);
			USART_voidSendString("LED_ON_YASTA");


		}else if (Data == '2')
		{
			LED_enuLED_OFF(Led0);
			DIO_enuClearPin(DIO_enuPin1);
			USART_voidSendString("LED_OFF_YASTA");
		}
}
}
