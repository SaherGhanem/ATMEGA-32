#include "Std_types.h"
#include "Bit_math.h"

#include "EXTI.h"
#include "EXTI_Cfg.h"
#include "EXTI_Prv.h"
/**********************************************************************************************************************************/
/*Global pointer to function to hold INT0 ISR address*/
static void (*EXTI_pvInt0Func)(void) = NULL;

/*Global pointer to function to hold INT1 ISR address*/
static void (*EXTI_pvInt1Func)(void) = NULL;

/*Global pointer to function to hold INT2 ISR address*/
static void (*EXTI_pvInt2Func)(void) = NULL;
/**********************************************************************************************************************************/


EXTI_tenuErrorStatus EXTI_enuInt0Init(void){

				/*Check Sense Control*/

	/* Set Sense control for INT0 to RISING_EDGE*/
#if INT0_MODE ==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

	/* Set Sense control for INT0 to falling edge */
#elif INT0_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0_MODE Configuration Option"
#endif


	/*Check Peripheral interrupt enable initial state*/
#if  INT0_INITIAL_STATE == ENABLED
	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLED
	/* Peripheral interrupt disable for INT0 */
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE Configuration Option"
#endif


	return EXTI_enuOK;
}

/**********************************************************************************************************************************/
EXTI_tenuErrorStatus EXTI_enuInt1Init(void){

	/*Check Sense Control*/

/* Set Sense control for INT1 to RISING_EDGE*/
#if INT1_MODE ==RISING_EDGE
SET_BIT(MCUCR,MCUCR_ISC10);
SET_BIT(MCUCR,MCUCR_ISC11);
/* Set Sense control for INT1 to falling edge */
#elif INT1_MODE == FALLING_EDGE
CLR_BIT(MCUCR,MCUCR_ISC10);
SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_MODE == LOGICAL_CHANGE
SET_BIT(MCUCR,MCUCR_ISC10);
CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_MODE == LOW_LEVEL
CLR_BIT(MCUCR,MCUCR_ISC10);
CLR_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1_MODE Configuration Option"
#endif


/*Check Peripheral interrupt enable initial state*/
#if  INT1_INITIAL_STATE == ENABLED
/* Peripheral interrupt enable for INT1 */
SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
/* Peripheral interrupt disable for INT1 */
CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE Configuration Option"
#endif


return EXTI_enuOK;
}

/**********************************************************************************************************************************/
EXTI_tenuErrorStatus EXTI_enuInt2Init(void){

	/*Check Sense Control*/

/* Set Sense control for INT2 to RISING_EDGE*/
#if INT2_MODE ==RISING_EDGE
SET_BIT(MCUCSR,MCUCSR_INT2);
/* Set Sense control for INT2 to falling edge */
#elif INT2_MODE == FALLING_EDGE
CLR_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT1_MODE Configuration Option"
#endif


/*Check Peripheral interrupt enable initial state*/
#if  INT2_INITIAL_STATE == ENABLED
/* Peripheral interrupt enable for INT2 */
SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
/* Peripheral interrupt disable for INT2 */
CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE Configuration Option"
#endif


return EXTI_enuOK;


}
/**********************************************************************************************************************************/



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
EXTI_tenuErrorStatus EXTI_enuIntSetSenseControl(u8 Copy_u8Int, u8 Copy_u8Sence){
	EXTI_tenuErrorStatus Local_u8ErrorState = EXTI_enuOK ;
	switch(Copy_u8Sence)
	{

	/*EXTI Int0 Set Sense Control*/
	case EXTI_tenuINT0:
	switch(Copy_u8Sence)
	{
	case RISING_EDGE: 		SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	case FALLING_EDGE: 		CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	case LOGICAL_CHANGE: 	SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	case LOW_LEVEL: 		CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	default: Local_u8ErrorState= EXTI_enuNotOK;
	}
	break;

	/*EXTI Int1 Set Sense Control*/
	case EXTI_tenuINT1:
	switch(Copy_u8Sence)
	{
	case RISING_EDGE: 		SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	case FALLING_EDGE: 		CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	case LOGICAL_CHANGE: 	SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	case LOW_LEVEL: 		CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	default: Local_u8ErrorState= EXTI_enuNotOK;
	}
	break;

	/*EXTI Int2 Set Sense Control*/
	case EXTI_tenuINT2:

	break;
	default: Local_u8ErrorState= EXTI_enuNotOK;
	}

return Local_u8ErrorState;
}
/**********************************************************************************************************************************/





/**********************************************************************************************************************************/

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
EXTI_tenuErrorStatus EXTI_enuIntEnableState(u8 Copy_u8Int, u8 Copy_u8IntEnableState){

	EXTI_tenuErrorStatus Local_u8ErrorState = EXTI_enuOK ;



	switch(Copy_u8Int)
	{
	case  EXTI_tenuINT0:
		switch(Copy_u8IntEnableState)
		{
		case  ENABLED: SET_BIT(GICR,GICR_INT0);  break;
		case  DISABLED: CLR_BIT(GICR,GICR_INT0); break;
		default: Local_u8ErrorState= EXTI_enuNotOK;
		}break;
	case  EXTI_tenuINT1:
		switch(Copy_u8IntEnableState)
		{
		case  ENABLED: SET_BIT(GICR,GICR_INT1);  break;
		case  DISABLED: CLR_BIT(GICR,GICR_INT1); break;
		default: Local_u8ErrorState= EXTI_enuNotOK;
		}
	break;
	case  EXTI_tenuINT2:
		switch(Copy_u8IntEnableState)
		{
		case  ENABLED: SET_BIT(GICR,GICR_INT2);  break;
		case  DISABLED: CLR_BIT(GICR,GICR_INT2); break;
		default: Local_u8ErrorState= EXTI_enuNotOK;
		}
	break;
	default: Local_u8ErrorState= EXTI_enuNotOK;
	}


return Local_u8ErrorState;
}
/**********************************************************************************************************************************/







/**********************************************************************************************************************************/

EXTI_tenuErrorStatus EXTI_enuInt0_ISR_SetCallBack(void (*Copy_pvInt0Func)(void)){
	u8 Local_u8ErrorState= EXTI_enuNotOK;
	if(Copy_pvInt0Func == NULL)
	{
		Local_u8ErrorState = EXTI_enuNullPtr;
	}
	else
	{
		EXTI_pvInt0Func =Copy_pvInt0Func;
	}
return Local_u8ErrorState;
}

/*ISR For INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func == NULL)
	{
		/*DO NOTING*/
	}
	else
	{
		EXTI_pvInt0Func();
	}
}

/**********************************************************************************************************************************/


EXTI_tenuErrorStatus EXTI_enuInt1_ISR_SetCallBack(void (*Copy_pvInt1Func)(void)){
	u8 Local_u8ErrorState= EXTI_enuNotOK;
	if(Copy_pvInt1Func == NULL)
	{
		Local_u8ErrorState = EXTI_enuNullPtr;
	}
	else
	{
		EXTI_pvInt1Func =Copy_pvInt1Func;
	}
return Local_u8ErrorState;
}

/*ISR For INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func == NULL)
	{
		/*DO NOTING*/
	}
	else
	{
		EXTI_pvInt1Func();
	}
}

/**********************************************************************************************************************************/


EXTI_tenuErrorStatus EXTI_enuInt2_ISR_SetCallBack(void (*Copy_pvInt2Func)(void)){
	u8 Local_u8ErrorState= EXTI_enuNotOK;
	if(Copy_pvInt2Func == NULL)
	{
		Local_u8ErrorState = EXTI_enuNullPtr;
	}
	else
	{
		EXTI_pvInt2Func =Copy_pvInt2Func;
	}
return Local_u8ErrorState;
}

/*ISR For INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func == NULL)
	{
		/*DO NOTING*/
	}
	else
	{
		EXTI_pvInt2Func();
	}
}

/**********************************************************************************************************************************/

