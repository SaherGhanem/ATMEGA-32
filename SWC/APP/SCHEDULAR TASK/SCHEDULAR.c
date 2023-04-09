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

#include "Std_types.h"
#include "TIMER.h"
#include "RTOS.h"
#include "RTOS_Prv.h"
#include "RTOS_Cfg.h"

Task_t SystemTasks [TASK_NUM] = {{NULL}};


RTOS_tenuErrorStatus RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u8 Copy_FristDelay)
{
	RTOS_tenuErrorStatus Local_u8ErrorState= RTOS_enuOK;

	if(SystemTasks[Copy_u8Priority].TaskFunc == NULL){
	SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
	SystemTasks[Copy_u8Priority].State = TASK_RESUMED;  // Initialize the  task state as resumed
	SystemTasks[Copy_u8Priority].FirstDelay = Copy_FristDelay;
}
	else
	{
		/*Required priority is reserved for another function*/
		Local_u8ErrorState = RTOS_enuNotOK;
	}
	return Local_u8ErrorState;
}
void RTOS_voidStart(void)
{
	TIMER0_enuRegisterCallback(&Scheduler);
	TIMER0_voidInitPreCompile();
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
}


/*
static void Scheduler(void)
{
	static u16 Local_u16Counter=0;
	u8 Local_u16TaskCounter;

	//Increment the scheduler counter
	Local_u16Counter++;

	for(Local_u16TaskCounter=0 ; Local_u16TaskCounter<TASK_NUM; Local_u16TaskCounter++)
	{
		//Check if the task is resumed or suspended
		if(SystemTasks[Local_u16TaskCounter].State == TASK_RESUMED)
		{
		if((Local_u16Counter % SystemTasks[Local_u16TaskCounter].Periodicity)==0)
		{
			//Invoke the task function
			if(SystemTasks[Local_u16TaskCounter].TaskFunc!=NULL)
			{
			SystemTasks[Local_u16TaskCounter].TaskFunc();
			}
		    }
	        }
		else
		{
			//Task is suspended , do nothing
		}
	}

}
*/
static void Scheduler(void)
{
	u8 Local_u16TaskCounter;



	for(Local_u16TaskCounter=0 ; Local_u16TaskCounter<TASK_NUM; Local_u16TaskCounter++)
	{
		//Check if the task is resumed or suspended
		if(SystemTasks[Local_u16TaskCounter].State == TASK_RESUMED)
		{
		if(SystemTasks[Local_u16TaskCounter].FirstDelay==0)
		{
			//Invoke the task function
			if(SystemTasks[Local_u16TaskCounter].TaskFunc!=NULL)
			{
			SystemTasks[Local_u16TaskCounter].TaskFunc();
			SystemTasks[Local_u16TaskCounter].FirstDelay= SystemTasks[Local_u16TaskCounter].Periodicity;

			}
		    }else
		    {
		    	//Decrement the first dealy
		    	SystemTasks[Local_u16TaskCounter].FirstDelay--;
		    }
	        }
		else
		{
			//Task is suspended , do nothing
		}
	}

}
