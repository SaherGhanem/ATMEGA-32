/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/************************** 		SWC:  SPI			*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   	  	    SPI             *********************/
/**************************		  DATE: 04/01/2023      *********************/
/****************************************************************************/
/****************************************************************************/


#include "Std_types.h"
#include "Bit_math.h"

#include "SPI.h"
#include "SPI_Cfg.h"
#include "SPI_Prv.h"


void SPI_voidInitMaster(void)
{
	//MASTER INITIALIZATION
	SET_BIT(SPCR,SPCR_MSTR);

	//CLOCK PRESCALER: DIVIDE BY 16
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	//CLOCK PLOARITY & CLOCK PHASE --> take it for the default

	//SPI Enable
	SET_BIT(SPCR,SPCR_SPE);

}

void SPI_voidInitSlave(void)
{
	//MASTER INITIALIZATION
	CLR_BIT(SPCR,SPCR_MSTR);

	//CLOCK PLOARITY & CLOCK PHASE --> take it for the default

	//SLAVE NOT INTERSTED IN CLOCK

	//SPI Enable
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transcevie(u8 Copy_u8Data)
{
	/*Send the Data*/
	SPDR = Copy_u8Data;

	/*Wait (busy waiting) until transfer complete*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	//Get the exchange data
	return SPDR;
}










