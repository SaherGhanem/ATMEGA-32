/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	    SWC: External Interrupt *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   EXTI Configuration File   *********************/
/**************************		DATE: 01/24/2023       	*********************/
/****************************************************************************/
/****************************************************************************/


/*EXTI Configuration File */

#ifndef EXTI_Config_H
#define EXTI_Config_H
#include "Std_types.h"
#include "Bit_math.h"

#define INT0_MODE_RISING_EDGE     0   // ISC00 : 1  && ISC01 : 1  in MCUCR Register
#define INT0_MODE_FALLING_EDGE    1   // ISC00 : 0  && ISC01 : 1  in MCUCR Register
#define INT0_MODE_LOGICAL_CHANGE  2   // ISC00 : 1  && ISC01 : 0  in MCUCR Register
#define INT0_MODE_LOW_LEVEL       3   // ISC00 : 0  && ISC01 : 0  in MCUCR Register


#define INT1_MODE_RISING_EDGE     0   // ISC10 : 1  && ISC11 : 1  in MCUCR Register
#define INT1_MODE_FALLING_EDGE    1   // ISC10 : 0  && ISC11 : 1  in MCUCR Register
#define INT1_MODE_LOGICAL_CHANGE  2   // ISC10 : 1  && ISC11 : 0  in MCUCR Register
#define INT1_MODE_LOW_LEVEL       3   // ISC10 : 0  && ISC11 : 0  in MCUCR Register




#endif /*EXTI_Config_H*/





