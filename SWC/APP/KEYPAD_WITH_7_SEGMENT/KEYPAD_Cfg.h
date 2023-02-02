/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	  KEYPAD        *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   KEYPAD Configuration File *********************/
/**************************		DATE: 01/27/2023       	*********************/
/****************************************************************************/
/****************************************************************************/


/*KEYPAD Configuration File */


#ifndef KEYPAD_Config_H
#define KEYPAD_Config_H

#include "Std_types.h"

#include "DIO.h"

#define KPD_NO_PRESSED_KEY    0xff

#define KPD_ARR_VAL  {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}


#define KPD_COLUMN0_PIN   DIO_enuPin0
#define KPD_COLUMN1_PIN   DIO_enuPin1
#define KPD_COLUMN2_PIN   DIO_enuPin2
#define KPD_COLUMN3_PIN   DIO_enuPin3

#define KPD_ROW0_PIN      DIO_enuPin4
#define KPD_ROW1_PIN      DIO_enuPin5
#define KPD_ROW2_PIN      DIO_enuPin6
#define KPD_ROW3_PIN      DIO_enuPin7



#define COLUMNS_NUM 4
#define ROWS_NUM    4

#endif //KEYPAD_Config_H
