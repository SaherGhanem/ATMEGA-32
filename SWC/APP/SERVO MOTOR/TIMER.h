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


/*TIMER Interface File */

#ifndef TIMER_H
#define TIMER_H
#include "Std_types.h"



typedef enum
{
	TIMER_enuOK = 0,
	TIMER_enuNotOK,
	TIMER_enuNullPtr

}TIMER_tenuErrorStatus;   //return type of TIMER Functions to report errors

typedef struct
{
	u8  Mode;
	u8  Clock_Cfg;
	u16 TickTimeMS;

}Timer0_Config_t;


#define Timer_NormalMode          0b10111011U
#define Timer_PWMPhaseCorrectMode 0b10111111U
#define Timer_CTCMode             0b11111011U
#define Timer_FastPWMMode         0b11111111U




#define NO_Clock_Source              0
#define No_Prescaling                1
#define Prescaler_Division_by_8      2
#define Prescaler_Division_by_64     3
#define Prescaler_Division_by_256    4
#define Prescaler_Division_by_1024   5



#define Inverted_Mode                0   	//Clear on compare match set on top
#define Non_Inverted_Mode            1    	//Clear on top match set on compare



#define TMR02_CLK_OFF			  0b11111000U
#define TMR02_CLK_ON			  0x01U


#define TIMER0_RESET_MODE_MASK    0b10111011U



void TIMER0_voidInitPreCompile(void);
void TIMER0_voidSetCompMatchValue(u8 Copy_u8value);
TIMER_tenuErrorStatus TIMER0_enuRegisterCallback(void (*Copy_pvCallBackFunc)(void));

TIMER_tenuErrorStatus TIMER0_voidInitPostCompile(Timer0_Config_t* Addr_pstr_Modulecfg);
TIMER_tenuErrorStatus TIMER0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 Copy_u8Clock);

/****************************TIMER1******************************/
void TIMER1_voidInit(void);

void Timer1_voidSetTimerValue(u16 Copy_u16Value);

void Timer1_voidSetICRValue(u16 Copy_u8value);
void Timer1_voidSetChannelACompMatchValue(u16 Copy_u8value);
void Timer1_voidSetChannelBCompMatchValue(u16 Copy_u8value);
//u16 Timer1_voidSetTimerValue(void);
/****************************Input Capture Unit******************************/


#define ICU_FALLING_EDGE 0
#define ICU_RISING_EDGE 1

void ICU_voidInit(void);

TIMER_tenuErrorStatus ICU_voidSetTriggerEdge(u8 Copy_u8Edge);

void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);

u16 ICU_voidReadInputCapture(void);

TIMER_tenuErrorStatus ICU_enuRegisterCallback(void (*Copy_pvCallBackFunc)(void));


#endif

