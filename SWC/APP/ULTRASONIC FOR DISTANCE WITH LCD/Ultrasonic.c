/*
 * Ultrasonic.c
 *
 *  Created on: Mar 11, 2023
 *      Author: Saher Ghanem
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIMER.h"
#include "UltraSonic.h"
#include "Delay_Interface.h"

static void ULTRASONIC_init(void);
static void ULTRASONIC_Trigger(void);
static void ULTRASONIC_Processing(void);
static u16 TIMER_Reading = 0;
int Num_Of_OverFlows;

void ULTRASONIC_Trigger(void)
{
		DIO_enuSetPin(ULTRASONIC_TRIGGER_PIN);
		Delay_ms(15);
		DIO_enuClearPin(ULTRASONIC_TRIGGER_PIN);

}
 void ULTRASONIC_init(void)
{
		/*Timer 1 Initialization */
		/* Set Prescaler with 1*/
	 	TIMER1_voidInit();
		/*Set ICU Trigger At Rising Edge*/
	 	ICU_voidInit();
		/*Set NotifyFunc to TIMER1_ICU*/
	 	ICU_enuRegisterCallback(ULTRASONIC_Processing);

}
 void ULTRASONIC_Processing(void)
{
	static u8 counter = 0;
	static u16 Num_Of_OVF =0;
	//	TIMER_Reading = 0;
	counter ++;
	/*Detect Rising Edge*/
	if(counter == 1)
	{

		/*Clear Timer To Start Counting*/
		Timer1_voidSetTimerValue(0);
		ICU_voidSetTriggerEdge(ICU_FALLING_EDGE);
	}
	else if(counter == 2)
	{
		TIMER_Reading = ICU_voidReadInputCapture() + (Num_Of_OverFlows * Num_Of_OVF);
		ICU_voidSetTriggerEdge(ICU_RISING_EDGE);
			counter = 0;



	}
}
u16 ULTRASONIC_GetDistance(void)
{
	ULTRASONIC_init();
	ULTRASONIC_Trigger();
	while(TIMER_Reading == 0);
	return TIMER_Reading/466.47;
}
