#include "DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "LCD_Prv.h"
#include "Delay_Interface.h"



void  LCD_vidInit(){
	/*Wait for more than 30ms*/
		Delay_ms(40);

	/*Function Set Command: 2 Lines, 5*8 Font Size*/
		LCD_enuSendCommand(0b00111000);

	/*Wait for more than 30ms*/
		//Delay_ms(40);

	/*Display on off control: Display enable, Disable Cursor, No Blink Cursor*/
		LCD_enuSendCommand(0b00001100);

	/*Clear Display*/
		LCD_enuSendCommand(0b00000001);

}

LCD_tenuErrorStatus LCD_enuSendData (u8 Copy_u8Data)
{
	/*Clear RS pin to command --> 0*/
	DIO_enuSetPin(DIO_enuPin5);

	/*Clear R/W pin to write --> 0*/
		DIO_enuClearPin(DIO_enuPin6);

	/*Set Command to data Pins*/
		DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);

	/*Send Enable Pulse*/
		DIO_enuSetPin(DIO_enuPin7);
		Delay_ms(2);
	/*Send Disable Pulse After 2 mile second*/
		DIO_enuClearPin(DIO_enuPin7);

	return LCD_enuOK;
}


LCD_tenuErrorStatus LCD_enuSendCommand (u8 Copy_u8Command)
{
	/*Set RS pin to command --> 1*/
	DIO_enuClearPin(DIO_enuPin5);

	/*Clear R/W pin to write --> 0*/
		DIO_enuClearPin(DIO_enuPin6);

	/*Set Command to data Pins*/
		DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Command);

	/*Send Enable Pulse*/
		DIO_enuSetPin(DIO_enuPin7);
		Delay_ms(2);
	/*Send Disable Pulse After 2 mile second*/
		DIO_enuClearPin(DIO_enuPin7);

	return LCD_enuOK;

}

LCD_tenuErrorStatus LCD_enuWriteString(const char* Copy_pcString){
	u8 Local_u8Counter=0;

	while(Copy_pcString[Local_u8Counter]!= '\0'){
		LCD_enuSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

	return LCD_enuOK;
}


LCD_tenuErrorStatus LCD_enuGOToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		/*Location is at first line*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*location is at second line */
		Local_u8Address=(Copy_u8YPos+0x40);
	}
	/*set bit number 7 for set DDRAM Address command then send the command */
	LCD_enuSendCommand(Local_u8Address+128);

	return LCD_enuOK;
}



LCD_tenuErrorStatus LCD_enuWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0, Local_u8Iterator;

	/*Calculate the CGRAM Address Whose Each Block is 8 Bytes*/
	Local_u8CGRAMAddress = (Copy_u8BlockNum*8);

	/*Send CGRAM Address Command to LCD, With setting bit 6, clearing bit 7 */
	LCD_enuSendCommand(Local_u8CGRAMAddress+64);

	/*Write the pattern in CGRAM*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_enuSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/*Go Back the DDRAM to Display the Pattern*/
	LCD_enuGOToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the pattern written in the CGRAM*/
	LCD_enuSendData(Copy_u8BlockNum);

	return LCD_enuOK;
}



LCD_tenuErrorStatus LCD_voidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_u32Reserved=1;

	while(Copy_u32Number!=0)
	{
		Local_u32Reserved=Local_u32Reserved*10 + Copy_u32Number%10;
		Copy_u32Number/=10;
	}
	do
	{
		LCD_enuSendData((Local_u32Reserved%10)+'0');
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);


	return LCD_enuOK;
}
