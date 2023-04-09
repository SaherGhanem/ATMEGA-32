/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Saher Ghanem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "GIE.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "TIMER.h"
#include "Delay_Interface.h"
#include "util/delay.h"

/*
int main(void)
{
	u16 Distance = 0;
	DIO_enuInit();
	LCD_vidInit();
	GIE_enuEnable();
    while (1)
    {
			LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
			LCD_enuGOToXY(0,0);
			LCD_enuWriteString("Distance= ");
			Distance = ULTRASONIC_GetDistance();
			LCD_enuGOToXY(0,12);
			LCD_voidWriteNumber(Distance);
			Delay_ms(300);
			LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
    }
}

*/
void main(void)
{
	u16 Local_u16Counter;
	DIO_enuInit();
	TIMER1_voidInit();
	Timer1_voidSetICRValue(20000);

	while(1){
		for(Local_u16Counter=750; Local_u16Counter<2500;Local_u16Counter+=15){
			Timer1_voidSetChannelACompMatchValue(Local_u16Counter);
			_delay_ms(10);
		}
		for(Local_u16Counter=2500; Local_u16Counter>750;Local_u16Counter-=15){
			Timer1_voidSetChannelACompMatchValue(Local_u16Counter);
			_delay_ms(10);
		}

	}
}
