/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	PUSHBUTTON     	*********************/
/**************************		   Version:1.00 	    *********************/
/**************************  PUSHBUTTON Interface File  *********************/
/**************************		  DATE: 01/17/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*PUSHBUTTON Interface File */

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include "Std_types.h"
#include "DIO.h"


typedef enum
{
	PUSHBUTTON_enuOK = 0,
	PUSHBUTTON_enuNotOK,
	PUSHBUTTON_enuNullPtr
}PUSHBUTTON_tenuErrorStatus;   //return type of PUSHBUTTON Functions to report errors


PUSHBUTTON_tenuErrorStatus PUSHBUTTON_enuIS_PRESSED(DIO_tenuPins Cpy_u8PinNumber,u8 PUSHBUTTON_STATE);

#endif /*PUSHBUTTON_H*/
