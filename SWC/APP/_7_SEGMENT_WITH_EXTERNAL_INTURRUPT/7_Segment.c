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

