#include "Std_types.h"
#include "Bit_math.h"

#include "GIE.h"
#include "GIE_Prv.h"


GIE_tenuErrorStatus GIE_enuEnable(void){
	
	SET_BIT(SREG,SREG_I);
	
	return GIE_enuOK;
}
GIE_tenuErrorStatus GIE_enuDisable(void){
	
	CLR_BIT(SREG,SREG_I);


	return GIE_enuOK;
	
}
