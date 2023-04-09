/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	       SWC: TIMER           *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   TIMER Configuration File  *********************/
/**************************		DATE: 02/19/2023       	*********************/
/****************************************************************************/
/****************************************************************************/

/*TIMER Configration File */

#ifndef TIMER_Cfg_H
#define TIMER_Cfg_H




/*
Timer_NormalMode
Timer_PWMPhaseCorrectMode
Timer_CTCMode
Timer_FastPWMMode
*/
#define TIMER_SelectMode Timer_FastPWMMode



/*
 NO_Clock_Source
 No_Prescaling
 Prescaler_Division_by_8
 Prescaler_Division_by_64
 Prescaler_Division_by_256
 Prescaler_Division_by_1024
*/
#define Clock_Select       Prescaler_Division_by_64



#define TIMER_RESOLUTION    256
#define ATMEGA_F_CPU		16
#define TIME_MILISEC		1000
#define COMPARE_MATCH_VAL	250


#endif
