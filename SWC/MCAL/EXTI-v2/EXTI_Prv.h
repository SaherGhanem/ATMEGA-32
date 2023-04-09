/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/**************************	    SWC: External Interrupt *********************/
/**************************		   Version:1.00 	    *********************/
/**************************   EXTI Configuration File   *********************/
/**************************		DATE: 01/24/2023       	*********************/
/****************************************************************************/
/****************************************************************************/

/*EXTI Privet File */

#ifndef EXTI_Prv_H
#define EXTI_Prv_H


//Perperal Interrupt Enable or Specific Interrupt Enable
#define GICR 		       *((volatile u8*)0x5B)    //General Interrupt Flag Register
#define GICR_INT1		   7   //INT1: External Interrupt Request 1 Enable
#define GICR_INT0		   6   //INT0: External Interrupt Request 0 Enable
#define GICR_INT2		   5   //INT2: External Interrupt Request 2 Enable



#define GIFR               *((volatile u8*)0x5A)    //General Interrupt Flag Register




#define MCUCR              *((volatile u8*)0x55)    //MCU Control and Status Register
#define MCUCR_ISC11        3  //ISC11, ISC10: Interrupt 1 Sense Control Bit 1 and Bit 0
#define MCUCR_ISC10        2  //ISC11, ISC10: Interrupt 1 Sense Control Bit 1 and Bit 0
#define MCUCR_ISC01        1  //ISC01, ISC00: Interrupt 0 Sense Control Bit 1 and Bit 0
#define MCUCR_ISC00        0  //ISC01, ISC00: Interrupt 0 Sense Control Bit 1 and Bit 0




#define MCUCSR             *((volatile u8*)0x54)   //The Asynchronous External Interrupt 2 is activated by the external pin INT2
#define MCUCSR_INT2        6   //ISC2: Interrupt Sense Control

#endif /*EXTI_Prv_H*/
