/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	   LM35     	*********************/
/**************************		   Version:1.00 	    *********************/
/**************************       LM35 Interface File    *********************/
/**************************		  DATE: 02/08/2023      *********************/
/****************************************************************************/
/****************************************************************************/

#ifndef LM35_H 
#define LM35_H 
 
#include "Std_types.h"

 
 typedef enum
 {
	 LM35_enuOK = 0,
	 LM35_enuNotOk,
	 LM35_enuNullPointer
 }LM35_tenuErrorStatus;
  
 
#define MAX_VOLTAGE 5000UL

#define RESOLUTION 256UL

#define VOLTAGE_TEMP_FACTOR 10

 
/************************************************************************************/
/*	LM35 GetTemperature Function 
	Input:  digital reading, pointer to variable to return the temperature
	Output: LM35_tenuErrorStatus to report errors*/
/************************************************************************************/
 LM35_tenuErrorStatus LM35_enuGetTemperature (u16 Cpy_u16DigitalReading , u8* Cpy_Pu8Temperature );
 
 
 
 
#endif /*LM35_H*/ 