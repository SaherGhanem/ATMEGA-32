/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	    SWC: EXternal Interrupt *********************/
/**************************		   Version:2.00 	    *********************/
/**************************     EXTI Interface File     *********************/
/**************************		 DATE: 02/09/2023      	*********************/
/****************************************************************************/
/****************************************************************************/


/*EXTI Interface File */

#ifndef EXTI_H
#define EXTI_H
#include "Std_types.h"
#include "EXTI_Cfg.h"


EXTI_tenuErrorStatus EXTI_enuInt0Init(void);
EXTI_tenuErrorStatus EXTI_enuInt1Init(void);
EXTI_tenuErrorStatus EXTI_enuInt2Init(void);






/**********************************************************************************************************************************/

/* Description: A Function to set the required Sense Control of INT using post_build Configuration
 * Input: 				Copy_u8Int, option are:
 * 									  1-EXTI_tenuINT0
 * 									  2-EXTI_tenuINT1
 * 									  3-EXTI_tenuINT2
 * 						Copy_u8Sence, option are:
 *  								  1-RISING_EDGE
 * 			 						  2-FALLING_EDGE
 * 									  3-LOGICAL_CHANGE
 * 		 							  4-LOW_LEVEL
 * Output: Error Status with type EXTI_tenuErrorStatus
 */
EXTI_tenuErrorStatus EXTI_enuIntSetSenseControl(u8 Copy_u8Int, u8 Copy_u8Sence);

/* Description: A Function to Enable the required External Interrupt INT0 or INT1 or INT2 using post_build Configuration
 * Input: 				Copy_u8Int, option are:
 * 									  1-EXTI_tenuINT0
 * 									  2-EXTI_tenuINT1
 * 									  3-EXTI_tenuINT2
 * 			Copy_u8IntEnableState, option are:
 * 									  1-ENABLED
 * 									  2-DISABLED
 * Output: Error Status with type EXTI_tenuErrorStatus
 */
EXTI_tenuErrorStatus EXTI_enuIntEnableState(u8 Copy_u8Int, u8 Copy_u8IntEnableState);









EXTI_tenuErrorStatus EXTI_enuInt0_ISR_SetCallBack(void (*Copy_pvInt0Func)(void));
EXTI_tenuErrorStatus EXTI_enuInt1_ISR_SetCallBack(void (*Copy_pvInt1Func)(void));
EXTI_tenuErrorStatus EXTI_enuInt2_ISR_SetCallBack(void (*Copy_pvInt2Func)(void));

#endif /*EXTI_H*/
