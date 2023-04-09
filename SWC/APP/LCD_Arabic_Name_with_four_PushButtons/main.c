/*
 * main.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Saher Ghanem
 */

#include "Std_types.h"
#include "DIO.h"
#include "LCD.h"
#include "PUSHBUTTON.h"
#include "Delay_Interface.h"

	u8 Hamoksha_1[8]={0b00001110,
			          0b00011111,
			          0b00010101,
			          0b00011111,
			          0b00010001,
			          0b00001110,
			          0b00000100,
			          0b00000100};


	u8 My_Arabic_Name1[8] = {
	 0b00000,
	 0b00000,
	 0b10101,
	 0b10101,
	 0b11111,
	 0b00000,
	 0b00000,
	 0b00000
	};

	u8 My_Arabic_Name2[8] = {
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000,
	  0b11111,
	  0b00000,
	  0b00000,
	  0b00000
	};


	u8 My_Arabic_Name3[8] = {
	  0b11111,
	  0b00001,
	  0b01111,
	  0b01011,
	  0b11111,
	  0b00000,
	  0b00000,
	  0b00000
	};

	u8 My_Arabic_Name4[8] = {
	  0b00000,
	  0b00000,
	  0b00000,
	  0b00000,
	  0b00001,
	  0b00010,
	  0b10100,
	  0b11000
	};


	u8 _7mada_1[8] = {
	  0b00100,
	  0b01010,
	  0b01110,
	  0b00100,
	  0b11111,
	  0b00100,
	  0b01110,
	  0b01010
	};

	u8 _7mada_2[8] = {
	  0b00100,
	  0b01010,
	  0b01110,
	  0b00101,
	  0b01110,
	  0b10100,
	  0b01110,
	  0b01010
			};

	u8 _7mada_3[8] = {
	  0b00100,
	  0b01010,
	  0b01110,
	  0b10100,
	  0b01110,
	  0b00101,
	  0b01110,
	  0b01010
	};


	u8 _7mada_4[8] = {
	  0b00100,
	  0b01010,
	  0b01110,
	  0b10100,
	  0b11111,
	  0b00101,
	  0b01110,
	  0b01010
	};

	u8 Ball[8] = {
	  0b00000,
	  0b00000,
	  0b00100,
	  0b01110,
	  0b11111,
	  0b01110,
	  0b00100,
	  0b00000
	};

	u8 Right_Goal[8] = {
	  0b00001,
	  0b00001,
	  0b00001,
	  0b00001,
	  0b00001,
	  0b00001,
	  0b00001,
	  0b00001
	};

	u8 Lift_Goal[8] = {
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000,
	  0b10000
	};


void main(void){
DIO_enuInit();
LCD_vidInit();

//LCD_enuSendData('S');
//LCD_enuSendData('A');
//LCD_enuSendData('H');
//LCD_enuSendData('E');
//LCD_enuSendData('R');
//LCD_enuGOToXY(1,10);
//LCD_enuWriteString("ALAA");
//LCD_enuWriteSpecialCharacter(Hamoksha_1,0,1,0);
//LCD_enuWriteSpecialCharacter(_7mada_1,1,1,8);
//LCD_enuWriteSpecialCharacter(_7mada_2,2,1,7);
//LCD_enuWriteSpecialCharacter(_7mada_3,3,1,6);
//LCD_enuWriteSpecialCharacter(_7mada_4,4,1,5);
//LCD_enuWriteSpecialCharacter(Ball,5,1,4);
//LCD_enuWriteSpecialCharacter(Right_Goal,6,1,3);
//LCD_enuWriteSpecialCharacter(Lift_Goal,7,1,2);


//LCD_voidWriteNumber(857);

	u8 x=0;
	u8 y=0;
	u8 BUTTON_1=DIO_enuPin16;
	u8 BUTTON_2=DIO_enuPin17;
	u8 BUTTON_3=DIO_enuPin18;
	u8 BUTTON_4=DIO_enuPin19;

	u8 BUTTON1_STATE;
	u8 BUTTON2_STATE;
	u8 BUTTON3_STATE;
	u8 BUTTON4_STATE;

	LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
	LCD_enuWriteSpecialCharacter(My_Arabic_Name1,0,x,y+3);
	LCD_enuWriteSpecialCharacter(My_Arabic_Name2,1,x,y+2);
	LCD_enuWriteSpecialCharacter(My_Arabic_Name3,2,x,y+1);
	LCD_enuWriteSpecialCharacter(My_Arabic_Name4,3,x,y);
	Delay_ms(700);


while(1){

	// RIGHT
	Delay_ms(20);
	 PUSHBUTTON_enuIS_PRESSED(BUTTON_1,&BUTTON1_STATE);
	  if(BUTTON1_STATE == 0){
	        if(y<12){
				y+=2;
				LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name1,0,x,y+3);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name2,1,x,y+2);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name3,2,x,y+1);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name4,3,x,y);
				Delay_ms(100);
					}
					else
					{
						//Do Nothing
					}
		}
		else
		{
			//Do Nothing
		}

	  // LEFT
	 Delay_ms(20);
	 PUSHBUTTON_enuIS_PRESSED(BUTTON_2,&BUTTON2_STATE);
		if(BUTTON2_STATE == 0)
		{
			 if((y+2)>2)
			 {
				y=y-2;
				LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name1,0,x,y+3);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name2,1,x,y+2);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name3,2,x,y+1);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name4,3,x,y);
				Delay_ms(100);

			 }
			 else
			 {
					//Do Nothing
			 }
		}
		else
		{
			//Do Nothing
		}



		// UP
		Delay_ms(20);
		 PUSHBUTTON_enuIS_PRESSED(BUTTON_3,&BUTTON3_STATE);
		if(BUTTON3_STATE == 0)
		{
			if(x>0)
			{
				x--;
				LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name1,0,x,y+3);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name2,1,x,y+2);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name3,2,x,y+1);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name4,3,x,y);
				Delay_ms(100);

			}

			else
			{
				//Do Nothing

			}

		}
		else
		{
			//Do Nothing
		}

		// DOWN

		Delay_ms(20);
		PUSHBUTTON_enuIS_PRESSED(BUTTON_4,&BUTTON4_STATE);


		if(BUTTON4_STATE == 0)
		{
			if(x<1)
			{
				x++;
				LCD_enuSendCommand(CLEAR_DISPLAY_COMMAND);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name1,0,x,y+3);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name2,1,x,y+2);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name3,2,x,y+1);
				LCD_enuWriteSpecialCharacter(My_Arabic_Name4,3,x,y);
				Delay_ms(100);

			}

			else
			{
				//Do Nothing
			}
		}
		else
		{
			//Do Nothing
		}

}
}
