
#include "ADC_Prv.h"
#include "ADC_Cfg.h"
#include "ADC.h"
#include "Std_types.h"
#include "BIT_MATH.h"


static u8* ADC_pu8Reading= NULL;       /*In ASynch take the pointer of the result and assign it to global because the final result will be in ISR FUNCTION*/
static void (*ADC_pvCallBackEOJFUNC)(void)=NULL;  /*Pointer to Function for EOJ Function */
u8 ADC_u8BusyState = ADC_enuREADY;       /*Global variable to State Machine initialize with READY State*/



static u8* ADC_pu8ChainChannelArr= NULL; /*Global variable to carry the chain array*/
static u8 ADC_u8ChainSize;               /*Global variable to carry number of channels*/
static u16* ADC_pu16ChainResultArr= NULL;/*Global variable to carry chain result*/
static u8 ADC_u8ChainConversionIndex=0;  /*Global variable to carry the current Conversion Index*/
static u8 ADC_u8ISRSource;               /*Global variable to Know the Source of ISR Chain Channel or Single Channel*/

void ADC_voidInit(void){

	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
	/*Activate Left Adjust Result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Set Prescaler to divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*Enable Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}



u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	ADC_tenuErrorStatus Local_u8ErrorState=ADC_enuOK;
	if (ADC_u8BusyState == ADC_enuREADY)
	{
		/*ADC is now busy*/
		ADC_u8BusyState= ADC_enuBUSY;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel into the MUX bits*/
		ADMUX|= Copy_u8Channel;

		/*Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reaching timeout value*/
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)  && (Local_u32Counter != ADC_u32TimeOut ) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter== ADC_u32TimeOut)
		{
			/*Loop is broken because the timeout is reached*/
			Local_u8ErrorState=ADC_enuNotOK;
		}
		else
		{
			/* Loop is broken because flag is raised */
			/* clear the conversion complete flag */
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			/*Return the reading*/
			*Copy_pu8Reading=ADCH;

			/*ADC is finished, return it to READY*/
			ADC_u8BusyState= ADC_enuREADY;
		}
	}
		else
		{
			Local_u8ErrorState= BUSY_FUNC;
		}

	return Local_u8ErrorState;
}


ADC_tenuErrorStatus ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvEOJFunc)(void))
{
	ADC_tenuErrorStatus Local_u8ErrorState = ADC_enuOK;

if(ADC_u8BusyState== ADC_enuREADY)
{
	if((Copy_pu8Reading == NULL) || (Copy_pvEOJFunc == NULL))
	{
		Local_u8ErrorState = ADC_enuNullPtr;
	}
	else
	{
			/*Make */
			ADC_u8BusyState = ADC_enuBUSY;

			/*Make ISR Source: Single Channel Asynchronous*/
			ADC_u8ISRSource = SINGLE_CHANNEL_ASYNCH;

			/*Initialize the reading variable globally*/
			ADC_pu8Reading = Copy_pu8Reading;

			/*Initialize the callback EOJ function globally*/
			ADC_pvCallBackEOJFUNC = Copy_pvEOJFunc;

			/*Clear the MUX bits in ADMUX Register*/
			ADMUX &= 0b11100000;

			/*Set the required channel into the MUX bits*/
			ADMUX|= Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
}
	else{

		Local_u8ErrorState = BUSY_FUNC;
	}

return Local_u8ErrorState;
}



ADC_tenuErrorStatus ADC_u8StartChainAsynch(Chain_t * Copy_chain)
{
	ADC_tenuErrorStatus Local_u8ErrorState = ADC_enuOK;
	/*Check NULL pointer*/
	if(Copy_chain == NULL){
		Local_u8ErrorState = ADC_enuNullPtr;
	}
	else
	{
			if(ADC_u8BusyState == ADC_enuREADY){

			    /*ADC is now busy*/
			    ADC_u8BusyState= ADC_enuBUSY;

			    /*Make ISR Source: Chain Asynchronous*/
			    ADC_u8ISRSource = CHAIN_ASYNCH;

			    /*Initialize Chain Channel Array*/
			    ADC_pu8ChainChannelArr= Copy_chain->Channel;

			    /*Initialize Result Array*/
			    ADC_pu16ChainResultArr= Copy_chain->Result;

			    /*Initialize Chain Size*/
			    ADC_pvCallBackEOJFUNC= Copy_chain->EOJ;

			    /*Initialize Current Conversion Index*/
			    ADC_u8ChainConversionIndex=0;

			    /*Set Required Channel(first channel)*/
			    ADMUX &= 0b11100000;
			    ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			    /*Start Conversion*/
			    SET_BIT(ADCSRA,ADCSRA_ADSC);

			    /*Enable Conversion Complete Interrupt*/
			    SET_BIT(ADCSRA,ADCSRA_ADIE);
			}
			else
			{
				Local_u8ErrorState = BUSY_FUNC;
			}

	}
	return Local_u8ErrorState;
}








void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
		     /*SINGLE_CHANNEL_ASYNCH*/
	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNCH)
	{
		/*Read ADC Result*/
		*ADC_pu8Reading =ADCH;

		/*Make ADC state be READY because it finished*/
		ADC_u8BusyState = ADC_enuREADY;

		/*Invoke the callback notification function*/
		ADC_pvCallBackNotificationFunc();

		/*Disable ADC Conversion Complete interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}


				/*CHAIN_ASYNCH*/
	else if (ADC_u8ISRSource == CHAIN_ASYNCH)
	{
		/*Read the current conversion*/
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]= ADCH;

		/*Increment chain Index*/
		ADC_u8ChainConversionIndex++;

		/*Check Chain is Finished or not*/
		if(ADC_u8ChainConversionIndex==ADC_u8ChainSize)
		{
			/*Chain is Finished*/

			/*Make ADC Now READY*/
			ADC_u8BusyState= ADC_enuREADY;

			/*Invoke the callback EOJ function*/
			ADC_pvCallBackEOJFUNC();

			/*Disable ADC Conversion Complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			/*Chain is not finished*/
			/*Set new required channel*/

			/*Clear the MUX bits in ADMUX Register*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/*Start New Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}

	}

}

