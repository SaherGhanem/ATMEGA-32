/*


 * main.c

 *
 *  Created on: Jan 18, 2023
 *      Author: Saher Ghanem
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "Delay_Interface.h"
#include "DIO.h"
#include "LED.h"
#include "PUSHBUTTON.h"

int main(void){

	DIO_enuInit();
	LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
	LED_tstrLEDCfg_t Led1 = {ACTIVE_HIGH,DIO_enuPin1};
	LED_tstrLEDCfg_t Led2 = {ACTIVE_HIGH,DIO_enuPin2};
	LED_tstrLEDCfg_t Led3 = {ACTIVE_HIGH,DIO_enuPin3};
	LED_tstrLEDCfg_t Led4 = {ACTIVE_HIGH,DIO_enuPin4};
	LED_tstrLEDCfg_t Led5 = {ACTIVE_HIGH,DIO_enuPin5};
	LED_tstrLEDCfg_t Led6 = {ACTIVE_HIGH,DIO_enuPin6};
	LED_tstrLEDCfg_t Led7 = {ACTIVE_HIGH,DIO_enuPin7};
	u8 BUTTON_1=DIO_enuPin8;
	u8* BUTTON_STATE;
	LED_tenuErrorStatus loc_Led_return;
	while(1){


		PUSHBUTTON_tenuErrorStatus loc_pushbutton_return = PUSHBUTTON_enuIS_PRESSED(BUTTON_1,BUTTON_STATE);
		if(BUTTON_STATE==1){
			loc_Led_return = LED_enuLED_ON(Led0);
		}else{
			loc_Led_return = LED_enuLED_OFF(Led0);
		}

	}
}








