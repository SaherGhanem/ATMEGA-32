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



#ifndef RTOS_Prv_H
#define RTOS_Prv_H

typedef struct
{
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 State;
	u8 FirstDelay;
}Task_t;



static void Scheduler(void);

#define TASK_SUSPENDED  0
#define TASK_RESUMED    1


#endif