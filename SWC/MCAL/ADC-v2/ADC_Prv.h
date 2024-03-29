/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/*********************** SWC: Analog to Digital Converter *******************/
/**************************		   Version:1.00 	    *********************/
/**************************  	 ADC Privet File        *********************/
/**************************		DATE: 02/02/2023       	*********************/
/****************************************************************************/
/****************************************************************************/

/*ADC Privet File */

#ifndef ADC_Prv_H
#define ADC_Prv_H

#define ADMUX              *((volatile u8*)0x27)     //ADC multiplexer selection register
#define ADMUX_REFS1			7                        //Reference selection bit1
#define ADMUX_REFS0 	    6                        //Reference selection bit0
#define ADMUX_ADLAR			5                        //ADC left adjust result

#define ADCSRA			   *((volatile u8*)0x26)     //ADC control and status regidter A
#define ADCSRA_ADEN			7                        //ADC enable 
#define ADCSRA_ADSC			6                        //Start conversion
#define ADCSRA_ADATE		5                        //Auto trigger enable 
#define ADCSRA_ADIF			4                        //Interrupt flag 
#define ADCSRA_ADIE			3                        //Interrupt enable 
#define ADCSRA_ADPS2		2                        //Prescaler bit2
#define ADCSRA_ADPS1		1                        //Prescaler bit1
#define ADCSRA_ADPS0		0                        //Prescaler bit0

#define ADCH				*((volatile u8*)0x25)    //ADC High Register
#define ADCL				*((volatile u8*)0x24)    //ADC Low Register



#endif