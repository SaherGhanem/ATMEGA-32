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


/*LCD Configuration File */


#ifndef LCD_Config_H
#define LCD_Config_H
#include "DIO.h"
#include "Std_types.h"
#include "Bit_math.h"





typedef enum
{

	LCD_enuOK = 0,
	LCD_enuNotOK,
	LCD_enuNullPtr

}LCD_tenuErrorStatus;   //return type of LCD Functions to report errors


#define CLEAR_DISPLAY_COMMAND		0x01
#define FUNCTION_SET_COMMAND 		0x38
#define ENTRY_MODE_SET_COMMAND 		0x06
#define DISPLAY_CONTOL_COMMAND 		0b00001110


#define LCD_DATA_PORT   DIO_PORTC


#define LCD_CTRL_PORT   DIO_PORTA
#define LCD_RS_PIN      DIO_enuPin5
#define LCD_RW_PIN      DIO_enuPin6
#define LCD_E_PIN       DIO_enuPin7


#endif //LCD_Config_H
