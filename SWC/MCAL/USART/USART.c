///****************************************************************************/
///****************************************************************************/
///**************************		Author: SAHER GHANEM 	*********************/
///**************************		   ITI-INTAKE43         *********************/
///**************************		   Layer:  MCAL    		*********************/
///************************** 		SWC:  USART			*********************/
///**************************		   Version:1.00 	    *********************/
///**************************   	  USART_Interface       *********************/
///**************************		  DATE: 03/17/2023      *********************/
///****************************************************************************/
///****************************************************************************/
//
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART.h"
#include "USART_Prv.h"
#include "USART_Cfg.h"



static u8* USART_pu8Reading= USART_enuNullPtr;

static void (*USART_pvCallBackNotificationFunc)(void)=USART_enuNullPtr;

u8 USART_u8BusyState= USART_enuIDLE;
static char * USART_pcString = USART_enuNullPtr;
static u8 USART_u8ChainCharSendingIndex;


static u8 USART_u8ISRSource;


void USART_voidInit(void){
	u8 Local_u8UCSRCValue=0; //To Write Values
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);

	//Size of data Transmit/Received
#if(Character_Size==CSIZE_5)
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UC271);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UC270);
	UCSRC= Local_u8UCSRCValue;
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(Character_Size==CSIZE_6)
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UC271);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC270);
	UCSRC= Local_u8UCSRCValue;
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(Character_Size==CSIZE_7)
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC271);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UC270);
	UCSRC= Local_u8UCSRCValue;
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(Character_Size==CSIZE_8)
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC271);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC270);
	 //UCSRC= Local_u8UCSRCValue;
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif(Character_Size==CSIZE_9)
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC271);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UC270);
	UCSRC= Local_u8UCSRCValue;
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#else
#error "Wrong Character Size"
#endif




	//SET PARITY MODE
#if(PARITY==UART_PARITY_EVEN)
	CLR_BIT(UCSRC,UCSRC_UPM0);
	SET_BIT(UCSRC,UCSRC_UPM1);
#elif(PARITY==UART_PARITY_ODD)
	SET_BIT(UCSRC,UCSRC_UPM0);
	SET_BIT(UCSRC,UCSRC_UPM1);
#elif(PARITY==UART_PARITY_DISABLED)
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
#else
#error "Wrong PARITY MODE"
#endif

	// USART MODE Asynchronous/synchronous
#if(USART_MODE_SELECT==Asynchronous)
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
#elif(USART_MODE_SELECT==synchronous)
	SET_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);

#else
#error "Wrong USART Mode Select"
#endif




	//Setting Baud Rate
	CLR_BIT(UCSRA,UCSRA_U2X);

	/*baud rate 9600*/
	UBRRL=51;


	//Number of stop bits
#if(STOPBITS==STOPBITS_1)
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#elif(STOPBITS==STOPBITS_2)
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#else
#error "Wrong Number of stop bits "
#endif
	UCSRC= Local_u8UCSRCValue;

	//Enable Transmit/Receive
	SET_BIT(UCSRB,UCSRB_TXEN);  //Transmit Enable bit
	SET_BIT(UCSRB,UCSRB_RXEN);  //Receiver Enable bit


}




u8 USART_u8Receive(void){
	while(GET_BIT(UCSRA,UCSRA_RXC)==0); /*POLLING*/
	return UDR;
}


void USART_voidSend(u8 Copy_u8Data){
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0); /*Wait until Transmit Data Buffer is Empty*/
	UDR=Copy_u8Data;
}




void USART_voidSendStringSynch(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		USART_voidSend(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
	USART_voidSend('\0');
}


u8 USART_u8SendCharSynch(u8 Copy_u8Data)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=USART_enuOK;
	if (USART_u8BusyState == USART_enuIDLE)
	{
		//USART is now busy
		USART_u8BusyState= USART_enuBUSY;

		//Polling (busy waiting) until the complete flag is set or counter reaching timeout value
		while((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (Local_u32Counter != USART_u32TIMEOUT ) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter== USART_u32TIMEOUT)
		{
			//Loop is broken because the timeout is reached
			Local_u8ErrorState=USART_enuNotOK;
		}
		else
		{

			//Return the reading
			UDR = Copy_u8Data;

			//USART is finished, return it to IDLE
			USART_u8BusyState= USART_enuIDLE;
		}
	}
	else
	{
		Local_u8ErrorState= USART_enuBUSY_FUNC;
	}

	return Local_u8ErrorState;
}


u8 USART_u8ReceiveCharSynch(u8 *Copy_u8Data)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=USART_enuOK;
	if (USART_u8BusyState == USART_enuIDLE)
	{
		//USART is now busy
		USART_u8BusyState= USART_enuBUSY;

		//Polling (busy waiting) until the complete flag is set or counter reaching timeout value
		while((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (Local_u32Counter != USART_u32TIMEOUT ) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter== USART_u32TIMEOUT)
		{
			//Loop is broken because the timeout is reached
			Local_u8ErrorState=USART_enuNotOK;
		}
		else
		{

			//Return the reading
			*Copy_u8Data=UDR;

			//ADC is finished, return it to IDLE
			USART_u8BusyState= USART_enuIDLE;
		}
	}
	else
	{
		Local_u8ErrorState= USART_enuBUSY_FUNC;
	}

	return Local_u8ErrorState;
}
//UDRIE
u8 USART_u8SendCharAsynch(u8* Copy_u8Data, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_uErrorState=USART_enuOK;
	if(USART_u8BusyState== USART_enuIDLE)
	{
		if((Copy_u8Data ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_uErrorState= USART_enuNullPtr;
		}
		else
		{
			/*make USART busy in order not to work until being idle*/
			USART_u8BusyState= USART_enuBUSY;


			USART_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			/*Initialize the reading variable globally*/
			USART_pu8Reading = Copy_u8Data;

			/*Initialize the callback notification function globally*/
			USART_pvCallBackNotificationFunc= Copy_pvNotificationFunc;


			//USART interrupt enable
			SET_BIT(UCSRB,UCSRB_TXCIE);



		}
	}
	else
	{
		Local_uErrorState= USART_enuBUSY_FUNC;
	}

	return Local_uErrorState;
}


u8 USART_u8ReceiveCharAsynch(u8* Copy_u8Data, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_uErrorState=USART_enuOK;
	if(USART_u8BusyState== USART_enuIDLE)
	{
		if((Copy_u8Data ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_uErrorState= USART_enuNullPtr;
		}
		else
		{
			/*make USART busy in order not to work until being idle*/
			USART_u8BusyState= USART_enuBUSY;


			USART_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			/*Initialize the reading variable globally*/
			USART_pu8Reading = Copy_u8Data;

			/*Initialize the callback notification function globally*/
			USART_pvCallBackNotificationFunc= Copy_pvNotificationFunc;

			//UDRIE
			//USART interrupt enable
			SET_BIT(UCSRB,UCSRB_RXCIE);



		}
	}
	else
	{
		Local_uErrorState= USART_enuBUSY_FUNC;
	}

	return Local_uErrorState;
}


u8 USART_u8SendStringAsynch(char * Copy_pcString , void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_uErrorState = USART_enuOK;
	if(USART_u8BusyState == USART_enuIDLE)
		{
	       if((Copy_pcString == NULL)|| (Copy_pvNotificationFunc == NULL))
	         {
		        return Local_uErrorState = USART_enuNullPtr;
	}
	else
	{

			USART_u8BusyState = USART_enuBUSY;

			/*MakIe ISR Source: ChainCharAsynch*/
/////////////			USART_u8ISRSource = ChainCharAsynch;

			/*Initialize Globally Array*/
			USART_pcString = Copy_pcString;

			/*Initialize Notification function*/
			USART_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*Initialize current conversion Index*/
			USART_u8ChainCharSendingIndex = 0;

			/*USART Data Register Empty interrupt enable*/
			SET_BIT(UCSRB,UCSRB_UDRIE);
		}

	}
	else
		{
			Local_uErrorState= USART_enuBUSY_FUNC;
		}

		return Local_uErrorState;

}


//USART, TXC --> USART, Tx Complete
void __vector_15 (void)  __attribute__((signal));
void __vector_15 (void)
{

	UDR=*USART_pu8Reading;

	/*Disable USART_TXC interrupt*/
	CLR_BIT(UCSRB,UCSRB_TXCIE);


	//Invoke the callback notification function
	USART_pvCallBackNotificationFunc();

}
//USART, UDRE --> USART Data Register Empty
void __vector_14 (void)  __attribute__((signal));
void __vector_14 (void)
{

		/*Send Data*/
		UDR = USART_pcString[USART_u8ChainCharSendingIndex];

		/*Increment Chain index*/
		USART_u8ChainCharSendingIndex++;

		/*check chain is finished or not*/
	if(	USART_pcString[USART_u8ChainCharSendingIndex] == '\0'){


			/*Disable USART Data Register Empty interrupt*/
			CLR_BIT(UCSRB,UCSRB_UDRIE);

			/*Invoke the callback notification function*/
			USART_pvCallBackNotificationFunc();
	}
		}




//USART, RXC --> USART, Rx Complete
void __vector_13 (void)  __attribute__((signal));
void __vector_13 (void)
{

	*USART_pu8Reading=UDR;



	/*Disable RXCIE interrupt*/
	CLR_BIT(UCSRB,UCSRB_RXCIE);

	/*Invoke the callback notification function*/
	USART_pvCallBackNotificationFunc();



}




///////////////////////////////////////////////////////////////////////////////////////////////

//
//void USART_voidInit(void) {
//u8 Local_u8UCSRCValue=0; /*To Write Values*/
//SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);
///*A_synchronus USART*/
//CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
//
///*8 bit Character size*/
//SET_BIT(Local_u8UCSRCValue,UCSRC_UC271);
//SET_BIT(Local_u8UCSRCValue,UCSRC_UC270);
//
//
//
///*Setting Baud Rate*/
//CLR_BIT(UCSRA,UCSRA_U2X);
//
///*baud rate 9600*/
//UBRRL=51;
//
///*1 bit Stop */
//CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
//
//UCSRC= Local_u8UCSRCValue;
///*Enable Tx & Rx*/
//SET_BIT(UCSRB,UCSRB_TXEN);
//SET_BIT(UCSRB,UCSRB_RXEN);
//
//
//}
//u8 USART_u8Receive(void){
//	while(GET_BIT(UCSRA,UCSRA_RXC)==0); /*POLLING*/
//	return UDR;
//
//}
//
//void USART_voidSend(u8 Copy_u8Data){
//	while(GET_BIT(UCSRA,UCSRA_UDRE)==0); /*Wait until Transmit Data Buffer is Empty*/
//	UDR=Copy_u8Data;
//
//}
//
//void USART_voidSendString(const char* Copy_pcString)
//{
//	u8 Local_u8Counter = 0;
//	while(Copy_pcString[Local_u8Counter] != '\0')
//	{
//		USART_voidSend(Copy_pcString[Local_u8Counter]);
//		Local_u8Counter++;
//	}
//	USART_voidSend('\0');
//}
