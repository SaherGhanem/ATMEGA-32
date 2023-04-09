/*
 * main.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Saher Ghanem
 */



#include "Std_types.h"
#include "Bit_math.h"
#include "DIO.h"
#include "LED.h"
#include "PUSHBUTTON.h"
#include "GIE.h"


LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};

void LED1(void);
void LED2(void);
void LED3(void);

int main(void)
{
	DIO_enuInit();
	GIE_enuEnable();
	RTOS_voidCreateTask(0,500 ,&LED1);
	RTOS_voidCreateTask(1,1000,&LED2);
	RTOS_voidCreateTask(2,1500,&LED3);

	RTOS_voidStart();

    while (1)
    {

}
}

void LED1(void)
{
	LED_tstrLEDCfg_t LedState = {ACTIVE_HIGH,DIO_enuPin0};
	TGL_BIT(LedState.LED_PIN_NUM,0);
	DIO_enuSetPin(LedState.LED_PIN_NUM);
}
void LED2(void)
{
	LED_tstrLEDCfg_t LedState = {ACTIVE_HIGH,DIO_enuPin1};
	TGL_BIT(LedState.LED_PIN_NUM,0);
	DIO_enuSetPin(LedState.LED_PIN_NUM);
}
void LED3(void)
{
	LED_tstrLEDCfg_t LedState = {ACTIVE_HIGH,DIO_enuPin2};
	TGL_BIT(LedState.LED_PIN_NUM,0);
	DIO_enuSetPin(LedState.LED_PIN_NUM);
}
