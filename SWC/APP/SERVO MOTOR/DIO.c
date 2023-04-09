#include "Std_types.h"
#include "Bit_math.h"

#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"

//#include <avr/io.h>



#define DIO_PINA 0
#define DIO_PINB 1
#define DIO_PINC 2
#define DIO_PIND 3

DIO_tenuErrorStatus DIO_enuInit(void)
{
	
	u8 i;
	u8 Loc_u8PortNumber = 0;
	u8 Loc_u8PinNumber = 0;

	for(i = 0; i<DIO_enuNumberOfPins;i++)
	{
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		switch (Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if (DIO_strPinCFG[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRA,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCFG[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTA,Loc_u8PinNumber);

					}
				}
				break;
			case(DIO_PORTB):
				if (DIO_strPinCFG[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRB,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRB,Loc_u8PinNumber);
					if(DIO_strPinCFG[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTB,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTB,Loc_u8PinNumber);

					}
				}
				break;
			case(DIO_PORTC):
				if (DIO_strPinCFG[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRC,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRC,Loc_u8PinNumber);
					if(DIO_strPinCFG[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTC,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTC,Loc_u8PinNumber);

					}
				}
				break;
			case(DIO_PORTD):
				if (DIO_strPinCFG[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRD,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRD,Loc_u8PinNumber);
					if(DIO_strPinCFG[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTD,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTD,Loc_u8PinNumber);

					}
				}
				break;
		}
		
	}
	

	return DIO_enuOK;

}




DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber){

		if(Cpy_u8PinNumber<0 || Cpy_u8PinNumber>31){
				return DIO_enuNotOK;
		}
			u8 Loc_u8PortNumber = Cpy_u8PinNumber/8;
			u8 Loc_u8PinNumber = Cpy_u8PinNumber%8;
			switch (Loc_u8PortNumber)
			{
				case(DIO_PORTA):
					SET_BIT(PORTA,Loc_u8PinNumber);
					break;
				case(DIO_PORTB):
					SET_BIT(PORTB,Loc_u8PinNumber);
					break;
				case(DIO_PORTC):
						SET_BIT(PORTC,Loc_u8PinNumber);
					break;
				case(DIO_PORTD):
						SET_BIT(PORTD,Loc_u8PinNumber);
					break;

}
			return DIO_enuOK;
}

DIO_tenuErrorStatus DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=DIO_enuOK;

	switch(Copy_u8Port)
	{
	case DIO_PORTA : PORTA = Copy_u8Value; break;
	case DIO_PORTB : PORTB = Copy_u8Value; break;
	case DIO_PORTC : PORTC = Copy_u8Value; break;
	case DIO_PORTD : PORTD = Copy_u8Value; break;
	default: Local_u8ErrorState=DIO_enuNotOK;
	}

	return Local_u8ErrorState;
}

DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_u8PinNumber){
	if(Cpy_u8PinNumber<0 || Cpy_u8PinNumber>31){
			return DIO_enuNotOK;
	}
		u8 Loc_u8PortNumber = Cpy_u8PinNumber/8;
		u8 Loc_u8PinNumber = Cpy_u8PinNumber%8;
		switch (Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				CLR_BIT(PORTA,Loc_u8PinNumber);
				break;
			case(DIO_PORTB):
				CLR_BIT(PORTB,Loc_u8PinNumber);
				break;
			case(DIO_PORTC):
				CLR_BIT(PORTC,Loc_u8PinNumber);
				break;
			case(DIO_PORTD):
		        CLR_BIT(PORTD,Loc_u8PinNumber);
				break;

}
		return DIO_enuOK;
}


DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_u8PinNumber,u8* Add_pu8PinValue){
	if(Cpy_u8PinNumber<0 || Cpy_u8PinNumber>31){
			return DIO_enuNotOK;
	}
	u8 Loc_u8PINNumber = Cpy_u8PinNumber/8;
	u8 Loc_u8PinNumber = Cpy_u8PinNumber%8;
	switch (Loc_u8PINNumber)
	{
		case(DIO_PINA):
		*Add_pu8PinValue= GET_BIT(PINA,Loc_u8PinNumber);
			break;
		case(DIO_PINB):
		*Add_pu8PinValue= GET_BIT(PINB,Loc_u8PinNumber);
			break;
		case(DIO_PINC):
		*Add_pu8PinValue= GET_BIT(PINC,Loc_u8PinNumber);
			break;
		case(DIO_PIND):
		*Add_pu8PinValue= GET_BIT(PIND,Loc_u8PinNumber);
			break;

}
	return DIO_enuOK;

}
