/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Layer:  MCAL    		*********************/
/************************** 		SWC:  USART			*********************/
/**************************		   Version:1.00 	    *********************/
/**************************   		  USART             *********************/
/**************************		  DATE: 03/17/2023      *********************/
/****************************************************************************/
/****************************************************************************/

#ifndef USART_Cfg_H_
#define USART_Cfg_H_

#define USART_u32TIMEOUT		50000


#define UART_PARITY_EVEN      0
#define UART_PARITY_ODD       1
#define UART_PARITY_DISABLED  2
#define PARITY  UART_PARITY_DISABLED
/*Choose PARITY MODE : EVEN OR ODD OR DISABLED
 Options: 1-UART_PARITY_EVEN
 	 	  2-UART_PARITY_ODD
 	 	  3-UART_PARITY_DISABLED  */



#define STOPBITS_1 1
#define STOPBITS_2 2
#define STOPBITS  STOPBITS_1
/*Choose Number of stop bits :
 Options: 1-STOPBITS_1
 	 	  2-STOPBITS_2            */


#define Asynchronous  0
#define Synchronous   1
#define USART_MODE_SELECT Asynchronous
/*Choose USART MODE : Select between Asynchronous and Synchronous mode of operation
 Options: 1-Asynchronous
 	 	  2-Synchronous           */



#define CSIZE_5 5
#define CSIZE_6 6
#define CSIZE_7 7
#define CSIZE_8 8
#define CSIZE_9 9
#define Character_Size   CSIZE_8
/*Choose Character Size : The UCSZ1:0 bits combined with the UCSZ2 bit in UCSRB sets the number of data bits
(Character Size) in a frame the Receiver and Transmitter use.
Options: 1-CSIZE_5   for 5-bit
 	 	 2-CSIZE_6   for 6-bit
 	 	 3-CSIZE_7   for 7-bit
 	 	 4-CSIZE_8   for 8-bit
 	 	 5-CSIZE_9   for 9-bit    */




/*Select Clock Polarity
 * Choose: 1-Rising_Edge
 * 		   2-Falling_Edge
 */
#define USART_ClockPolarity			       Rising_Edge


/*Setting Oscillator Frequency*/
#define USART_OscillatorFrequency	       8000000

/*Select Speed
 * Choose: 1-NormalSpeed
 * 		   2-DoubleSpeed
 */

#define USART_SelectSpeed			       NormalSpeed

#define USART_BaudRate        3
/*Choose baud_rate :
Options: 1-baud_2400
 	 	 2-baud_4800
 	 	 3-baud_9600
 	 	 4-baud_14.4k
 	 	 5-baud_19.2k            */



#endif
