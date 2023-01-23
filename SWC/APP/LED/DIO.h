/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************		   SWC:	   DIO     		*********************/
/**************************		   Version:1.00 	    *********************/
/**************************       DIO Interface File    *********************/
/**************************		  DATE: 01/12/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*DIO Interface File */

#ifndef DIO_H
#define DIO_H
#include "Std_types.h"


typedef enum
{
	DIO_enuOK = 0,
	DIO_enuNotOK,
	DIO_enuNullPtr

}DIO_tenuErrorStatus;   //return type of DIO Functions to report errors


typedef enum
{
	DIO_enuPin0 = 0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7,
	DIO_enuPin8,
	DIO_enuPin9,
	DIO_enuPin10,
	DIO_enuPin11,
	DIO_enuPin12,
	DIO_enuPin13,
	DIO_enuPin14,
	DIO_enuPin15,
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19,
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22,
	DIO_enuPin23,
	DIO_enuPin24,
	DIO_enuPin25,
	DIO_enuPin26,
	DIO_enuPin27,
	DIO_enuPin28,
	DIO_enuPin29,
	DIO_enuPin30,
	DIO_enuPin31,
	DIO_enuNumberOfPins
}DIO_tenuPins;   //




typedef enum
{
	DIO_enuLow = 0,
	DIO_enuHigh

}DIO_tenuPinValue;   //


/************************************************************************************/
/* DIO Init Function 
   Input: void
   Output: DIO_tenuErrorStatus to report errors*/
/************************************************************************************/
DIO_tenuErrorStatus DIO_enuInit(void);



/************************************************************************************/
/*  DIO Set Pin_Pin Function 
	Input: Pin Number (Range From 0 - 31)
    Output: DIO_tenuErrorStatus to report errors*/
/************************************************************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber);



/************************************************************************************/
/*	DIO Clear_Pin Function 
	Input: Pin Number (Range From 0 - 31)
	Output: DIO_tenuErrorStatus to report errors*/
/************************************************************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_u8PinNumber);



/************************************************************************************/
/*	DIO Get_Pin Function 
	Input: Pin Number (Range From 0 - 31)
	Output: DIO_tenuErrorStatus to report errors*/
/************************************************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_u8PinNumber,u8* Add_pu8PinValue);



#endif /*DIO_H*/
