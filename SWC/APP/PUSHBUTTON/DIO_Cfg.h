/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************		   SWC:	   DIO     		*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   DIO Configuration File    *********************/
/**************************		DATE: 01/12/2023       	*********************/
/****************************************************************************/
/****************************************************************************/


/*DIO Configuration File */

#ifndef DIO_Config_H
#define DIO_Config_H
#include "Std_types.h"
#include "Bit_math.h"
#define DIO_DIR_INPUT    0
#define DIO_DIR_OUTPUT   1


#define DIO_INPUT_PULL_UP   0
#define DIO_INPUT_PULL_DOWN 1

typedef struct
{
	u8 DIO_PinDirection;
	u8 DIO_InputStatus;

}DIO_tstrPinCfg_t;

const DIO_tstrPinCfg_t DIO_strPinCFG[32]  =
{
/*PORTA*//*Pin Direction*/ /*DIO_INPUT_PULL_DOWN*/

/*PIN0*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN1*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN2*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN3*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN4*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN5*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN6*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN7*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},


/*PORTB*//*Pin Direction*/ /*DIO_INPUT_PULL_DOWN*/

/*PIN8*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN9*/ {DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN10*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN11*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN12*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN13*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN14*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN15*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},

/*PORTC*//*Pin Direction*/ /*DIO_INPUT_PULL_DOWN*/

/*PIN16*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN17*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN18*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN19*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN20*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN21*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN22*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN23*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},

/*PORTD*//*Pin Direction*/ /*DIO_INPUT_PULL_DOWN*/

/*PIN24*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN25*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN26*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN27*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN28*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN29*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN30*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
/*PIN31*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN}

};

#endif /*DIO_Config_H*/





