/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	   LCD     		*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   LCD Configuration File    *********************/
/**************************		DATE: 02/10/2023       	*********************/
/****************************************************************************/
/****************************************************************************/


/*LCD Interface File */

#ifndef LCD_H
#define LCD_H
#include "DIO.h"
#include "LCD_Cfg.h"



//#define NULL					0

#define LCD_u8NUMBER0			0
#define LCD_u8NUMBER1			1
#define LCD_u8NUMBER2			2
#define LCD_u8NUMBER3			3
#define LCD_u8NUMBER4			4
#define LCD_u8NUMBER5			5
#define LCD_u8NUMBER6			6
#define LCD_u8NUMBER7			7
#define LCD_u8NUMBER8			8
#define LCD_u8NUMBER9			9

void  LCD_vidInit();
LCD_tenuErrorStatus LCD_enuSendData (u8 Copy_u8Data);
LCD_tenuErrorStatus LCD_enuSendCommand (u8 Copy_u8Command);
LCD_tenuErrorStatus LCD_enuGOToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_tenuErrorStatus LCD_enuWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_tenuErrorStatus LCD_enuWriteString(const char* Copy_pcString);
//LCD_tenuErrorStatus LCD_enuWriteNumber (u16 Copy_u16Number);

LCD_tenuErrorStatus LCD_voidWriteNumber(u32 Copy_u32Number);

#endif
