/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  HAL    		*********************/
/**************************		   SWC:	7_SEGMENT       *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   7_SEGMENT Interface File  *********************/
/****************
 * **********		  DATE: 01/20/2023      *********************/
/****************************************************************************/
/****************************************************************************/


/*7_SEGMENT Interface File */


#ifndef _7_SEGMENT_H_
#define _7_SEGMENT_H_
#include "DIO.h"
#include "Std_types.h"
#include "Bit_math.h"


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

typedef enum
{

	_7_SEG_enuOK = 0,
	_7_SEG_enuNotOK,
	_7_SEG_enuNullPtr

}_7_SEG_tenuErrorStatus;   //return type of 7SEG Functions to report errors


#define     _7_SEG_ZERO   0
#define  	_7_SEG_ONE    1
#define 	_7_SEG_TWO    2
#define 	_7_SEG_THREE  3
#define 	_7_SEG_FOUR   4
#define 	_7_SEG_FIVE   5
#define 	_7_SEG_SIX    6
#define 	_7_SEG_SEVEN  7
#define 	_7_SEG_EIGHT  8
#define 	_7_SEG_NINE   9
//#define 	_7_SEG_DOT



		//ZERO
#define DIS_7_SEG_ZERO  0b00111111
		//ONE
#define DIS_7_SEG_ONE   0b00000110
		//TWO
#define DIS_7_SEG_TWO   0b01011011
		//THREE
#define DIS_7_SEG_THREE 0b01001111
		//FOUR
#define DIS_7_SEG_FOUR  0b01100110
		//FIVE
#define DIS_7_SEG_FIVE  0b01101101
		//SIX
#define DIS_7_SEG_SIX   0b01111101
		//SEVEN
#define DIS_7_SEG_SEVEN 0b00000111
		//EIGHT
#define DIS_7_SEG_EIGHT 0b01111111
		//NINE
#define DIS_7_SEG_NINE  0b01101111
		//DOT



_7_SEG_tenuErrorStatus _7_SEG_enuSEG_(u8 Cpy_u8_7_SEG_PORT_NUM, u8 Cpy_u8_7_SEG_DISPLAY_NUM);

void _7_SEG_voidDIS(u8 Cpy_u8_7_SEG_DISPLAY_NUM);


#endif /* 7_SEGMENT_H_ */
