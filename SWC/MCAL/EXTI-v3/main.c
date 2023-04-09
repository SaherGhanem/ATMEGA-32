

#include "Std_types.h"
#include "Bit_math.h"

//#include "Delay_Interface.h"
//#include "DIO.h"
//#include "LED.h"
//#include "PUSHBUTTON.h"
//#include "GIE.h"
#include "EXTI.h"


//LED_tstrLEDCfg_t Led0 = {ACTIVE_HIGH,DIO_enuPin0};
void INT0_ISR(void);

int main(void)
{
	//DIO_enuInit();
	//GIE_enuEnable();
	EXTI_enuInt0Init();
EXTI_enuInt0_ISR_SetCallBack(&INT0_ISR);  // (&) or Not before but MSRA Rules tell us to but it


    while (1)
    {

    }
}

void INT0_ISR(void)
{
	/*Your Code*/
}
