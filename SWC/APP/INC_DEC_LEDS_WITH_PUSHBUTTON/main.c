#include "Std_types.h"
#include "Bit_math.h"

#include "Delay_Interface.h"
#include "DIO.h"
#include "LED.h"
#include "PUSHBUTTON.h"

#define  initalVal {1,0}
#define  PRESSED 0
#define  LED_MAX 8

int main(void)
{
DIO_enuInit();
u8 PushButtonINC;
u8 PushButtonDEC;




	LED_tstrLEDCfg_t var={ACTIVE_HIGH,DIO_enuPin0};
	LED_tstrLEDCfg_t counter={ACTIVE_HIGH,DIO_enuPin0};
	LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
	LED_tstrLEDCfg_t Led1 = {ACTIVE_HIGH,DIO_enuPin1};
	LED_tstrLEDCfg_t Led2 = {ACTIVE_HIGH,DIO_enuPin2};
	LED_tstrLEDCfg_t Led3 = {ACTIVE_HIGH,DIO_enuPin3};
	LED_tstrLEDCfg_t Led4 = {ACTIVE_HIGH,DIO_enuPin4};
	LED_tstrLEDCfg_t Led5 = {ACTIVE_HIGH,DIO_enuPin5};
	LED_tstrLEDCfg_t Led6 = {ACTIVE_HIGH,DIO_enuPin6};
	LED_tstrLEDCfg_t Led7 = {ACTIVE_HIGH,DIO_enuPin7};
	DIO_tenuPins BUTTON_1= DIO_enuPin16;
	DIO_tenuPins BUTTON_2= DIO_enuPin17;


    while (1)
    {
     PUSHBUTTON_enuIS_PRESSED(BUTTON_1,&PushButtonINC);
     PUSHBUTTON_enuIS_PRESSED(BUTTON_2,&PushButtonDEC);

		if(PushButtonINC==PRESSED && var.LED_PIN_NUM<= 8)
		{
			counter.LED_PIN_NUM++;
			(var.LED_PIN_NUM)++;
			LED_enuLED_ON(var);
			Delay_ms(500);
		}
		if(PushButtonDEC==PRESSED && var.LED_PIN_NUM>= 0)
		{
			counter.LED_PIN_NUM--;
			--(var.LED_PIN_NUM);
			LED_enuLED_OFF(var);
			Delay_ms(500);
		}
}
}



//#include "Std_types.h"
//#include "Bit_math.h"
//
//#include "Delay_Interface.h"
//
//#include "DIO.h"
//#include "LED.h"
//#include "PUSHBUTTON.h"
//
//int main(void)
//{
//	DIO_enuInit();
//u8 PushButtonINC;
//u8 PushButtonDEC;
//
//
//
//
//	LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
//	LED_tstrLEDCfg_t Led1 = {ACTIVE_HIGH,DIO_enuPin1};
//	LED_tstrLEDCfg_t Led2 = {ACTIVE_HIGH,DIO_enuPin2};
//	LED_tstrLEDCfg_t Led3 = {ACTIVE_HIGH,DIO_enuPin3};
//	LED_tstrLEDCfg_t Led4 = {ACTIVE_HIGH,DIO_enuPin4};
//	LED_tstrLEDCfg_t Led5 = {ACTIVE_HIGH,DIO_enuPin5};
//	LED_tstrLEDCfg_t Led6 = {ACTIVE_HIGH,DIO_enuPin6};
//	LED_tstrLEDCfg_t Led7 = {ACTIVE_HIGH,DIO_enuPin7};
//	DIO_tenuPins BUTTON_1= DIO_enuPin16;
//	DIO_tenuPins BUTTON_2= DIO_enuPin17;
//
//    /*while (1)*/
//    {
//     PUSHBUTTON_enuIS_PRESSED(BUTTON_1,&PushButtonINC);
//     PUSHBUTTON_enuIS_PRESSED(BUTTON_2,&PushButtonDEC);
//
//		if(PushButtonINC==0)
//		{
//			LED_enuLED_ON(Led0);
//			Delay_ms(20);
//		}else if(PushButtonINC==1){
//			LED_enuLED_OFF(Led0);
//			Delay_ms(20);
//
//		}
//}
//}
