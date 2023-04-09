/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/*********************** SWC: Analog to Digital Converter *******************/
/**************************		   Version:1.00 	    *********************/
/**************************   	ADC Interface File      *********************/
/**************************		 DATE: 02/02/2023       *********************/
/****************************************************************************/
/****************************************************************************/


/*ADC Interface File */

#ifndef ADC_H
#define ADC_H
#include "Std_types.h"

typedef enum
{
	ADC_enuOK = 0,
	ADC_enuNotOK,
	ADC_enuNullPtr

}ADC_tenuErrorStatus;   //return type of ADC Functions to report errors


typedef enum
{
	ADC_enuREADY = 0,
	ADC_enuBUSY

}ADC_tenuStateMachine;   //return type of ADC StateMachine



typedef struct
{
	u8* Channel;   /*Array*/
	u16* Result;   /*Array*/
	u8 Size;
	void (*EOJ)(void);

}Chain_t;



typedef enum
{
	SINGLE_CHANNEL_ASYNCH=0,    /*Single Channel ASynchrouns*/
	CHAIN_ASYNCH				/*Chain of Channels ASynchrouns*/
}ADC_tenuChannelType;



void ADC_voidInit(void);

ADC_tenuErrorStatus ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading);

ADC_tenuErrorStatus ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvEOJFunc)(void));

ADC_tenuErrorStatus ADC_u8StartChainAsynch(Chain_t * Copy_chain);

#endif
