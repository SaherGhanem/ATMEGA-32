/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	    SWC: External Interrupt *********************/
/**************************		   Version:2.00 	    *********************/
/**************************   EXTI Configuration File   *********************/
/**************************		DATE: 02/09/2023       	*********************/
/****************************************************************************/
/****************************************************************************/


/*EXTI Configuration File */

#ifndef EXTI_Config_H
#define EXTI_Config_H
#include "Std_types.h"
#include "Bit_math.h"



/**********************************************************************************/

/*Options for INT0 & INT1:
 * 		  1-RISING_EDGE
 * 		  2-FALLING_EDGE
 * 		  3-LOGICAL_CHANGE
 * 		  4-LOW_LEVEL
 */
typedef enum
{
	RISING_EDGE     =1,
	FALLING_EDGE	  ,
	LOGICAL_CHANGE    ,
    LOW_LEVEL
}EXTI_tenuINT_MODE;


#define RISING_EDGE       1
#define FALLING_EDGE	  2
#define LOGICAL_CHANGE    3
#define LOW_LEVEL		  4

#define INT0_MODE RISING_EDGE

#define INT1_MODE LOGICAL_CHANGE

#define INT2_MODE RISING_EDGE
/**********************************************************************************/

/*Options for INT0 & INT1:
 * 		  1-ENABLED
 * 		  2-DISABLED
 */
typedef enum
{
	ENABLED     =1,
	DISABLED
}EXTI_tenuINITIAL_STATE_ENABLE_MODE;


#define ENABLED     1
#define DISABLED	2

#define INT0_INITIAL_STATE  ENABLED
#define INT1_INITIAL_STATE  DISABLED
#define INT2_INITIAL_STATE  DISABLED
/**********************************************************************************/

typedef enum
{
	EXTI_enuOK = 1,
	EXTI_enuNotOK,
	EXTI_enuNullPtr

}EXTI_tenuErrorStatus;   //return type of EXTI Functions to report errors

/**********************************************************************************/
typedef enum
{
	EXTI_tenuINT0 = 1,
	EXTI_tenuINT1,
	EXTI_tenuINT2

}EXTI_tenuINT_NUM;   //return type of EXTI Functions to Interrupt Number

/**********************************************************************************/

#define NULL 0

#endif /*EXTI_Config_H*/





