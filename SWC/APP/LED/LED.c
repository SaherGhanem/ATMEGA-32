
#include "LED.h"
//#include "LED_Cfg.h"
//#include "LED_Prv.h"

LED_tenuErrorStatus LED_enuLED_ON(LED_tstrLEDCfg_t Cpy_u8LED_NUMBER){
	if(Cpy_u8LED_NUMBER.LED_PIN_NUM<0 || Cpy_u8LED_NUMBER.LED_PIN_NUM>32){
		return LED_enuNotOK;
	}
	if(Cpy_u8LED_NUMBER.LED_Polarity == ACTIVE_HIGH){
		DIO_enuSetPin(Cpy_u8LED_NUMBER.LED_PIN_NUM);
	}else{

		DIO_enuClearPin(Cpy_u8LED_NUMBER.LED_PIN_NUM);
	}

	return LED_enuOK;
}

LED_tenuErrorStatus LED_enuLED_OFF(LED_tstrLEDCfg_t Cpy_u8LED_NUMBER){
	if(Cpy_u8LED_NUMBER.LED_PIN_NUM<0 || Cpy_u8LED_NUMBER.LED_PIN_NUM>32){
		return LED_enuNotOK;
	}
	if(Cpy_u8LED_NUMBER.LED_Polarity == ACTIVE_HIGH){
		DIO_enuClearPin(Cpy_u8LED_NUMBER.LED_PIN_NUM);
	}else{

		DIO_enuSetPin(Cpy_u8LED_NUMBER.LED_PIN_NUM);
	}

	return LED_enuOK;
}
