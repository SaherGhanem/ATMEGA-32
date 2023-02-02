/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	    SWC: EXternal Interrupt *********************/
/**************************		   Version:1.00 	    *********************/
/**************************     EXTI Interface File     *********************/
/**************************		  DATE: 01/24/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*EXTI Interface File */

#ifndef EXTI_H
#define EXTI_H
#include "Std_types.h"

typedef enum
{
	EXTI_enuOK = 0,
	EXTI_enuNotOK,
	EXTI_enuNullPtr

}EXTI_tenuErrorStatus;   //return type of DIO Functions to report errors

EXTI_tenuErrorStatus EXTI_enuInt0Init(void);

EXTI_tenuErrorStatus EXTI_enuInt1Init(void);

EXTI_tenuErrorStatus EXTI_enuInt2Init(void);




#endif /*EXTI_H*/
