/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	   LDR      	*********************/
/**************************		   Version:1.00 	    *********************/
/**************************       LDR Interface File    *********************/
/**************************		  DATE: 02/08/2023      *********************/
/****************************************************************************/
/****************************************************************************/

#ifndef LDR_H 
#define LDR_H 
 
#include "Std_types.h"

 
 typedef enum
 {
	 LDR_enuOK = 0,
	 LDR_enuNotOk,
	 LDR_enuNullPointer
 }LDR_tenuErrorStatus;
  
 
#define MAX_VOLTAGE 5000UL

#define RESOLUTION 256UL

#define VOLTAGE_FACTOR 10

 
/************************************************************************************/
/*	LDR GetIntenicty Function 
	Input:  Digital reading, pointer to variable to return the Intenicty
	Output: LDR_tenuErrorStatus to report errors*/
/************************************************************************************/
 LDR_tenuErrorStatus LDR_enuGetTemperature (u16 Cpy_u16DigitalReading , u8* Cpy_Pu8Intenicty);
 
 
 
 
#endif /*LDR_H*/ 