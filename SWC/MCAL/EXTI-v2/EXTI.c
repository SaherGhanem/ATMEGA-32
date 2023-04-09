#include "Std_types.h"
#include "Bit_math.h"

#include "EXTI.h"
#include "EXTI_Cfg.h"
#include "EXTI_Prv.h"

#define INT0_MODE INT0_MODE_RISING_EDGE

#define INT1_MODE INT1_MODE_LOGICAL_CHANGE



#if INT0_MODE == INT0_MODE_FALLING_EDGE

EXTI_tenuErrorStatus EXTI_enuInt0Init(void){

	/* Set sence control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}

#elif INT0_MODE == INT0_MODE_RISING_EDGE

EXTI_tenuErrorStatus EXTI_enuInt0Init(void){
	
	/* Set Sence control for INT0_MODE_RISING_EDGE */
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}
#elif INT0_MODE == INT0_MODE_LOGICAL_CHANGE

EXTI_tenuErrorStatus EXTI_enuInt0Init(void){

	/* Set Sence control for INT0_MODE_LOGICAL_CHANGE */
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}
#else INT0_MODE == INT0_MODE_LOW_LEVEL

EXTI_tenuErrorStatus EXTI_enuInt0Init(void){

	/* Set Sence control for INT0_MODE_LOW_LEVEL */
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}

#endif







#if INT1_MODE == INT1_MODE_FALLING_EDGE

EXTI_tenuErrorStatus EXTI_enuInt1Init(void){

	/* Set sence control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}

#elif INT1_MODE == INT1_MODE_RISING_EDGE

EXTI_tenuErrorStatus EXTI_enuInt1Init(void){

	/* Set Sence control for INT0_MODE_RISING_EDGE */
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}
#elif INT1_MODE == INT1_MODE_LOGICAL_CHANGE

EXTI_tenuErrorStatus EXTI_enuInt1Init(void){

	/* Set Sence control for INT0_MODE_LOGICAL_CHANGE */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}
#else INT1_MODE == INT1_MODE_LOW_LEVEL

EXTI_tenuErrorStatus EXTI_enuInt1Init(void){

	/* Set Sence control for INT0_MODE_LOW_LEVEL */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	return EXTI_enuOK;
}
#endif
