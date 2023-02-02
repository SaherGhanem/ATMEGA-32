#include "Std_types.h"
#include "Bit_math.h"

#include "EXTI.h"
#include "EXTI_Cfg.h"
#include "EXTI_Prv.h"



EXTI_tenuErrorStatus EXTI_enuInt0Init(void){
	/* Set sence control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
	
	return EXTI_enuOK;
}
