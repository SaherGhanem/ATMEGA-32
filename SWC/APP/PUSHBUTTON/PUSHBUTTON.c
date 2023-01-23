/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	PUSHBUTTON     	*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   PUSHBUTTON Implementation *********************/
/**************************		  DATE: 01/17/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*PUSHBUTTON Implementation */
#include "Std_types.h"
#include "Bit_math.h"
#include "PUSHBUTTON.h"
#include "DIO.h"

PUSHBUTTON_tenuErrorStatus PUSHBUTTON_enuIS_PRESSED(DIO_tenuPins Cpy_u8PinNumber,u8 PUSHBUTTON_STATE){
	if(Cpy_u8PinNumber<0 || Cpy_u8PinNumber>31){
			return PUSHBUTTON_enuNotOK;
	}

	DIO_tenuErrorStatus Loc_return_d =DIO_enuGetPin(Cpy_u8PinNumber,PUSHBUTTON_STATE);
	return PUSHBUTTON_enuOK;
}
