/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	   LED     		*********************/
/**************************		   Version:1.00 	    *********************/
/**************************       LED Interface File    *********************/
/**************************		  DATE: 01/17/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*DIO Interface File */

#ifndef LED_H
#define LED_H
#include "DIO.h"
#include "LED_Cfg.h"

typedef enum
{
	LED_enuOK = 0,
	LED_enuNotOK,
	LED_enuNullPtr

}LED_tenuErrorStatus;   //return type of LED Functions to report errors




LED_tenuErrorStatus LED_enuLED_ON(LED_tstrLEDCfg_t Cpy_u8LED_NUMBER);


LED_tenuErrorStatus LED_enuLED_OFF(LED_tstrLEDCfg_t Cpy_u8LED_NUMBER);


#endif
