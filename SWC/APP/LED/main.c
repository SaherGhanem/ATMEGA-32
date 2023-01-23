/*
 * main.c
 *
 *  Created on: Jan 17, 2023
 *      Author: Saher Ghanem
 */
#include "Delay_Interface.h"
#include "DIO.h"
//#include "LED_Cfg.h"
#include "LED.h"


int main(void){

	LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
	LED_tstrLEDCfg_t Led1 = {ACTIVE_HIGH,DIO_enuPin1};
	LED_tstrLEDCfg_t Led2 = {ACTIVE_HIGH,DIO_enuPin2};
	LED_tstrLEDCfg_t Led3 = {ACTIVE_HIGH,DIO_enuPin3};
	LED_tstrLEDCfg_t Led4 = {ACTIVE_HIGH,DIO_enuPin4};
	LED_tstrLEDCfg_t Led5 = {ACTIVE_HIGH,DIO_enuPin5};
	LED_tstrLEDCfg_t Led6 = {ACTIVE_HIGH,DIO_enuPin6};
	LED_tstrLEDCfg_t Led7 = {ACTIVE_HIGH,DIO_enuPin7};

	while(1){

		LED_enuLED_OFF(Led0);
		Delay_ms(1000);
		LED_enuLED_ON(Led1);
		Delay_ms(1000);
		LED_enuLED_ON(Led2);
		Delay_ms(1000);
		LED_enuLED_ON(Led3);
		Delay_ms(1000);
		LED_enuLED_ON(Led4);
		Delay_ms(1000);
		LED_enuLED_ON(Led5);
		Delay_ms(1000);
		LED_enuLED_ON(Led6);
		Delay_ms(1000);
		LED_enuLED_ON(Led7);
		Delay_ms(1000);
		LED_enuLED_OFF(Led7);
		Delay_ms(1000);
		LED_enuLED_OFF(Led6);
		Delay_ms(1000);
		LED_enuLED_OFF(Led5);
		Delay_ms(1000);
		LED_enuLED_OFF(Led4);
		Delay_ms(1000);
		LED_enuLED_OFF(Led3);
		Delay_ms(1000);
		LED_enuLED_OFF(Led2);
		Delay_ms(1000);
		LED_enuLED_OFF(Led1);
		Delay_ms(1000);
		LED_enuLED_OFF(Led0);
		Delay_ms(1000);
	}

}
