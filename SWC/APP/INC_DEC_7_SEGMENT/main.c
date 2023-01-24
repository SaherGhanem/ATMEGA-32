/*
 * main.c

 *
 *  Created on: Jan 24, 2023
 *      Author: Saher Ghanem
 */


#include "Std_types.h"
#include "Bit_math.h"

#include "Delay_Interface.h"
#include "DIO.h"
#include "LED.h"
#include "PUSHBUTTON.h"
#include "7_Segment.h"
#define  initalVal {1,0}
#define  PRESSED 0
#define  LED_MAX 8
    u8 count=0;
    u8 count1=0;
int main(void)
{
DIO_enuInit();
u8 PushButtonINC;
u8 PushButtonDEC;


	DIO_tenuPins BUTTON_1= DIO_enuPin16;
	DIO_tenuPins BUTTON_2= DIO_enuPin17;


    while (1)
    {
     PUSHBUTTON_enuIS_PRESSED(BUTTON_1,&PushButtonINC);
     PUSHBUTTON_enuIS_PRESSED(BUTTON_2,&PushButtonDEC);


     if(PushButtonINC==PRESSED)
     	{
    	 _7_SEG_enuSEG_(DIO_PORTB,count);
    	 count++;
    	 if (count==11){
    		 count=0;
    		 _7_SEG_enuSEG_(DIO_PORTB,count);
    		 _7_SEG_enuSEG_(DIO_PORTA,count1);
    		 count1++;
    	 }
    	 Delay_ms(100);
     	}

     if(PushButtonDEC==PRESSED){
         count--;
     	_7_SEG_enuSEG_(DIO_PORTB,count);
    	 if (count==0){
    		 count1--;
    		 _7_SEG_enuSEG_(DIO_PORTA,count1);

    	 }
    	 Delay_ms(100);
     	}


}
}
