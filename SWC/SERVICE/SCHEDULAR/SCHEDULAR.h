/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  RTOS Stack   *********************/
/**************************	       SWC: RTOS            *********************/
/**************************		   Version:1.00 	    *********************/
/**************************		DATE: 03/11/2023       	*********************/
/****************************************************************************/
/****************************************************************************/

#ifndef RTOS_H_
#define RTOS_H_


typedef enum
{
	RTOS_enuOK = 0,
	RTOS_enuNotOK,
	RTOS_enuNullPtr

}RTOS_tenuErrorStatus;   //return type of RTOS Functions to report errors


RTOS_tenuErrorStatus RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u8 Copy_FristDelay);
void RTOS_voidStart(void);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

#endif
