/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/************************** 		SWC:  USART			*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   	       USART            *********************/
/**************************		  DATE: 03/17/2023      *********************/
/****************************************************************************/
/****************************************************************************/

#ifndef USART_H_
#define USART_H_
#include "Std_types.h"


typedef enum
{
	USART_enuOK = 0,
	USART_enuNotOK,
	USART_enuNullPtr


}USART_tenuErrorStatus;   //return type of USART Functions to report errors

typedef enum
{
	USART_enuIDLE=0,
	USART_enuBUSY,
	USART_enuBUSY_FUNC
}USART_tenuStatus;

void USART_voidInit(void);
u8 USART_u8Receive(void);
void USART_voidSend(u8 Copy_u8Data);

void USART_voidSendString(const char* Copy_pcString);
#endif
