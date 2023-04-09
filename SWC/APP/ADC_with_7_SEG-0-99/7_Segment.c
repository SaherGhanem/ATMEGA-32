/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	7_SEGMENT       *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   7_SEGMENT Interface File  *********************/
/**************************		  DATE: 01/20/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*7_SEGMENT Interface File */



#include "7_Segment.h"
#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Prv.h"
#include "DIO.h"

_7_SEG_tenuErrorStatus _7_SEG_enuSEG_(u8 Cpy_u8_7_SEG_PORT_NUM, u8 Cpy_u8_7_SEG_DISPLAY_NUM){

	switch (Cpy_u8_7_SEG_PORT_NUM)
			{
				case(DIO_PORTA):
					switch(Cpy_u8_7_SEG_DISPLAY_NUM){
						case(_7_SEG_ZERO):
							 PORTA=DIS_7_SEG_ZERO;
							break;
						case(_7_SEG_ONE):
							 PORTA=DIS_7_SEG_ONE;
							break;
						case(_7_SEG_TWO):
							 PORTA=DIS_7_SEG_TWO;
							break;
						case(_7_SEG_THREE):
							PORTA=DIS_7_SEG_THREE;
							break;
						case(_7_SEG_FOUR):
							PORTA=DIS_7_SEG_FOUR;
							break;
						case(_7_SEG_FIVE):
							 PORTA=DIS_7_SEG_FIVE;
							break;
						case(_7_SEG_SIX):
							 PORTA=DIS_7_SEG_SIX;
							break;
						case(_7_SEG_SEVEN):
							PORTA=DIS_7_SEG_SEVEN;
							break;
						case(_7_SEG_EIGHT):
								PORTA=DIS_7_SEG_EIGHT;
								break;
						case(_7_SEG_NINE):
								 PORTA=DIS_7_SEG_NINE;
								break;
					}
						break;

				case(DIO_PORTB):
					switch(Cpy_u8_7_SEG_DISPLAY_NUM){
						case(_7_SEG_ZERO):
							 PORTB=DIS_7_SEG_ZERO;
							break;
						case(_7_SEG_ONE):
							 PORTB=DIS_7_SEG_ONE;
							break;
						case(_7_SEG_TWO):
							 PORTB=DIS_7_SEG_TWO;
							break;
						case(_7_SEG_THREE):
							PORTB=DIS_7_SEG_THREE;
							break;
						case(_7_SEG_FOUR):
							PORTB=DIS_7_SEG_FOUR;
							break;
						case(_7_SEG_FIVE):
							 PORTB=DIS_7_SEG_FIVE;
							break;
						case(_7_SEG_SIX):
							 PORTB=DIS_7_SEG_SIX;
							break;
						case(_7_SEG_SEVEN):
							PORTB=DIS_7_SEG_SEVEN;
							break;
						case(_7_SEG_EIGHT):
							PORTB=DIS_7_SEG_EIGHT;
							break;
						case(_7_SEG_NINE):
							PORTB=DIS_7_SEG_NINE;
							break;
					}
						break;

					case(DIO_PORTC):
						switch(Cpy_u8_7_SEG_DISPLAY_NUM){
							case(_7_SEG_ZERO):
								 PORTC=DIS_7_SEG_ZERO;
								break;
							case(_7_SEG_ONE):
								 PORTC=DIS_7_SEG_ONE;
								break;
							case(_7_SEG_TWO):
								 PORTC=DIS_7_SEG_TWO;
								break;
							case(_7_SEG_THREE):
								PORTC=DIS_7_SEG_THREE;
								break;
							case(_7_SEG_FOUR):
								PORTC=DIS_7_SEG_FOUR;
								break;
							case(_7_SEG_FIVE):
								 PORTC=DIS_7_SEG_FIVE;
								break;
							case(_7_SEG_SIX):
								 PORTC=DIS_7_SEG_SIX;
								break;
							case(_7_SEG_SEVEN):
								PORTC=DIS_7_SEG_SEVEN;
								break;
							case(_7_SEG_EIGHT):
								PORTC=DIS_7_SEG_EIGHT;
								break;
							case(_7_SEG_NINE):
								 PORTC=DIS_7_SEG_NINE;
								break;
						}
							break;

					case(DIO_PORTD):
							switch(Cpy_u8_7_SEG_DISPLAY_NUM){
								case(_7_SEG_ZERO):
									 PORTD=DIS_7_SEG_ZERO;
									break;
								case(_7_SEG_ONE):
									 PORTD=DIS_7_SEG_ONE;
									break;
								case(_7_SEG_TWO):
									 PORTD=DIS_7_SEG_TWO;
									break;
								case(_7_SEG_THREE):
									PORTD=DIS_7_SEG_THREE;
									break;
								case(_7_SEG_FOUR):
									PORTD=DIS_7_SEG_FOUR;
									break;
								case(_7_SEG_FIVE):
									 PORTD=DIS_7_SEG_FIVE;
									break;
								case(_7_SEG_SIX):
									 PORTD=DIS_7_SEG_SIX;
									break;
								case(_7_SEG_SEVEN):
									PORTD=DIS_7_SEG_SEVEN;
									break;
								case(_7_SEG_EIGHT):
									PORTD=DIS_7_SEG_EIGHT;
									break;
								case(_7_SEG_NINE):
									PORTD=DIS_7_SEG_NINE;
									break;
							}
								break;
					}
	return _7_SEG_enuOK;
}



void _7_SEG_voidDIS(u8 Cpy_u8_7_SEG_DISPLAY_NUM){
	switch(Cpy_u8_7_SEG_DISPLAY_NUM){
	case 0 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 1 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 2 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 3 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 4 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 5 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 6 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 7 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 8 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 9 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ZERO);
		break;
	case 10 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 11 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 12 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 13 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case  14 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case  15 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 16 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 17 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 18 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 19 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_ONE);
		break;
	case 20 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 21 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 22 :
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 23:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 24:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 25:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 26:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 27:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 28:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 29:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_TWO);
		break;
	case 30:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 31:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 32:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 33:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 34:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 35:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 36:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 37:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 38:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 39:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 40:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 41:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 42:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 43:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 44:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 45:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 46:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 47:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 48:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 49:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FOUR);
		break;
	case 50:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_THREE);
		break;
	case 51:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 52:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 53:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 54:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 55:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 56:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 57:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 58:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 59:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_FIVE);
		break;
	case 60:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 61:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 62:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 63:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 64:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 65:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 66:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 67:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 68:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 69:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SIX);
		break;
	case 70:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 71:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 72:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 73:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 74:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 75:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 76:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 77:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 78:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 79:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_SEVEN);
		break;
	case 80:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 81:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 82:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 83:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 84:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 85:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 86:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 87:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 88:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 89:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_EIGHT);
		break;
	case 90:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ZERO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 91:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_ONE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 92:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_TWO);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 93:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_THREE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 94:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FOUR);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 95:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_FIVE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 96:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SIX);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 97:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_SEVEN);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 98:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_EIGHT);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
		break;
	case 99:
		 _7_SEG_enuSEG_(DIO_PORTC,_7_SEG_NINE);
		 _7_SEG_enuSEG_(DIO_PORTB,_7_SEG_NINE);
	}
}
