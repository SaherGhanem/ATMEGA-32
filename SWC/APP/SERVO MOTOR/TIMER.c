
#include "TIMER.h"
#include "TIMER_Prv.h"
#include "TIMER_Cfg.h"
#include "Std_types.h"
#include "Bit_math.h"
#include "math.h"
static void (*TIMER0_pvCallBackFunc)(void) = NULL;

static void (*ICU_pvCallBackFunc)(void) = NULL;



u32 Max_Count = 0;

void TIMER0_voidInitPreCompile(void){
	/*Set Timer : NO Clock Source (Timer/Counter Stopped)*/
	#if Clock_Select == NO_Clock_Source
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		/*Set Timer : No Prescaling*/
	#elif Clock_Select == No_Prescaling
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		/*Set Timer : Prescaler Division by 8*/
	#elif Clock_Select == Prescaler_Division_by_8
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		/*Set Timer : Prescaler Division by 64*/
	#elif Clock_Select == Prescaler_Division_by_64
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		/*Set Timer : Prescaler Division by 256*/
	#elif Clock_Select == Prescaler_Division_by_256
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		/*Set Timer : Prescaler Division by 1024*/
	#elif Clock_Select == Prescaler_Division_by_1024
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
	#else
	#error "Wrong Select Clock"
	#endif


	/*Select MODE*/
#if TIMER_SelectMode == Timer_NormalMode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Enable OverFlow Interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

	/*Set preLoad*/
	TCNT0 = 0;

#elif TIMER_SelectMode == Timer_PWMPhaseCorrectMode
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#elif TIMER_SelectMode == Timer_CTCMode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Output compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set compare match value to 250*/
	OCR0 = 250;  // My choice because this number can be divide by 100000 microsec to reach 1sec so the count in isr will be 4000

#elif TIMER_SelectMode == Timer_FastPWMMode
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//Clear on compare match set on top
	#if Compare_OutputMode == Non_Inverted_Mode
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	//Clear on top match set on compare
	#elif Compare_OutputMode == Inverted_Mode
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#else
	#error "Wrong Select Mode"
	#endif



#else
#error "Wrong Select Mode"
#endif


}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8value)
{
	OCR0 = Copy_u8value;
}

TIMER_tenuErrorStatus TIMER0_enuRegisterCallback(void (*Copy_pvCallBackFunc)(void)){
	TIMER_tenuErrorStatus Local_u8ErrorStatus = TIMER_enuOK;

if(Copy_pvCallBackFunc != NULL)
{
	TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
}
else
{
	Local_u8ErrorStatus = TIMER_enuNullPtr;
}
return Local_u8ErrorStatus;

}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}else
	{
		/*Do Noting*/
	}
}



TIMER_tenuErrorStatus TIMER0_voidInitPostCompile(Timer0_Config_t* Addr_pstr_Modulecfg)
{
	TIMER_tenuErrorStatus Local_enuErrorstat = TIMER_enuOK;
	u8 Local_u8TCCR0 = 0;
	if(Addr_pstr_Modulecfg != NULL)
	{
		Local_u8TCCR0 = TCCR0;
		Local_u8TCCR0 &= TIMER0_RESET_MODE_MASK;
		Local_u8TCCR0 |= Addr_pstr_Modulecfg->Mode;
		TCCR0 = Local_u8TCCR0;

		TIMER0_enuSetTickTimeMS(Addr_pstr_Modulecfg->TickTimeMS,Addr_pstr_Modulecfg->Clock_Cfg);

		Local_u8TCCR0 &= TMR02_CLK_OFF;
		Local_u8TCCR0 |= Addr_pstr_Modulecfg->Clock_Cfg;
		TCCR0 = Local_u8TCCR0;
	}
	else
	{
		Local_enuErrorstat = TIMER_enuNullPtr;
	}
	return Local_enuErrorstat;
}




TIMER_tenuErrorStatus TIMER0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 Copy_u8Clock)
{
	TIMER_tenuErrorStatus Local_enuErrorStat = TIMER_enuOK;
	f32 Local_OV_Time = 0;
	f32 Local_NumberOfOVs = 0;
	f32 Local_PreLoadValue = 0;
	f32 Local_DecimalPortion = 0;
	u8 Local_TCCR0 = TCCR0;

	if((Local_TCCR0 & Timer_CTCMode) == Timer_CTCMode)
	{
		OCR0 = (u8)COMPARE_MATCH_VAL;
		Max_Count = ((u32)Copy_u16TickTime * (u32)TIME_MILISEC)/(u32)COMPARE_MATCH_VAL;
	}
	else
	{
		Local_OV_Time = (((f32)Copy_u8Clock/(f32)ATMEGA_F_CPU) * (f32)TIMER_RESOLUTION);
		Local_NumberOfOVs = ((f32)Copy_u16TickTime * (f32)TIME_MILISEC)/Local_OV_Time;
		Local_DecimalPortion = (Local_NumberOfOVs - (u32)Local_NumberOfOVs);
		Local_PreLoadValue = TIMER_RESOLUTION * (1-Local_DecimalPortion);
		Max_Count = ceil(Local_NumberOfOVs);
		TCNT0 = Local_PreLoadValue;
	}


	return Local_enuErrorStat;

}




/****************************TIMER1******************************/


void TIMER1_voidInit(void)
{
	/*Compare Output ModeChannel A, Fast PWM*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);


	/*Waveform Generation Mode, Fast PWM ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Set prescaler Division by 8*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}

void Timer1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

void Timer1_voidSetICRValue(u16 Copy_u8value)
{
	ICR1 = Copy_u8value;
}
void Timer1_voidSetChannelACompMatchValue(u16 Copy_u8value)
{
	OCR1A = Copy_u8value;
}
void Timer1_voidSetChannelBCompMatchValue(u16 Copy_u8value)
{
	OCR1B = Copy_u8value;
}


//u16 Timer1_voidSetTimerValue(void){
//	return TCNT1;
//}
/****************************Input Capture Unit******************************/


void ICU_voidInit(void)
{
/*Set trigger source to rising edge initially*/
	SET_BIT(TCCR1B, TCCR1B_ICES1);

/*Enable Input Capture Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}


TIMER_tenuErrorStatus ICU_voidSetTriggerEdge(u8 Copy_u8Edge){
	TIMER_tenuErrorStatus Local_u8ErrorStatus = TIMER_enuOK;
if(Copy_u8Edge == ICU_RISING_EDGE)
{
	SET_BIT(TCCR1B,TCCR1B_ICES1);
}
else if(Copy_u8Edge == ICU_FALLING_EDGE)
{
	CLR_BIT(TCCR1B,TCCR1B_ICES1);
}
else
{
	Local_u8ErrorStatus = TIMER_enuOK;
}
return Local_u8ErrorStatus;
}

void ICU_voidEnableInterrupt(void){
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void){
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_voidReadInputCapture(void){
	return ICR1;
}

TIMER_tenuErrorStatus ICU_enuRegisterCallback(void (*Copy_pvCallBackFunc)(void)){
	TIMER_tenuErrorStatus Local_u8ErrorStatus = TIMER_enuOK;

if(Copy_pvCallBackFunc != NULL)
{
	ICU_pvCallBackFunc = Copy_pvCallBackFunc;
}
else
{
	Local_u8ErrorStatus = TIMER_enuNullPtr;
}
return Local_u8ErrorStatus;

}


void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}else
	{
		/*Do Noting*/
	}
}

