/****************************************************************************/
/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		Layer:  Libraries		*********************/
/**************************		SWC:	BIT_MATH		*********************/
/**************************		   Version:1.00 	    *********************/
/**************************		DATE: 12/06/2022       	*********************/
/****************************************************************************/
/****************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/**************************		SET - CLEAR - TOGGLE - GET --> Bit_NO      *********************/
#define SET_BIT(REG,Bit_NO)             ((REG) |= (1<<(Bit_NO))) 									// Set The Bit number Bit_NO
#define CLR_BIT(REG,Bit_NO)             ((REG) &= (~(1<<(Bit_NO))))									// Clear The Bit number Bit_NO
#define TGL_BIT(REG,Bit_NO)				((REG) ^= (1<<(BIT_NO)))									// TOGGLE The Bit number Bit_NO
//#define GET_BIT(REG,Bit_NO) 	    	(((REG)>> (Bit_NO)) &1)		   					            // Get The Bit number Bit_NO
//#define GET_BIT(REG,Bit_NO)              ((REG & (1<<Bit_NO))>>Bit_NO)
#define GET_BIT(REG,Bit_NO)          	((REG>>Bit_NO)&0X01)
/**************************		SET - CLEAR - TOGGLE - GET --> HIG_NIB     *********************/
#define SET_HIG_NIB(REG)			    ((REG) |(0xFF << (sizeof(REG)*8 - 4)))                      // Set The High Nibble in a Register. 
#define CLR_HIG_NIB(REG)			    ((REG) | ~((0xFF >> sizeof(REG)*8 - 4))) 	                // Clear The High Nibble in a Register. 
#define GET_HIG_NIB(REG)			    ((REG) >> sizeof(REG) * 8 - 4) 			                    // Get The High Nibble in a Register. 
#define TGL_HIG_NIB(REG)			    ((REG) ^ (0xFF << sizeof(REG)*8 - 4))   			        // Toggle the High Nibble in a Register.


/**************************		SET - CLEAR - TOGGLE - GET --> LOW_NIB     *********************/
#define SET_LOW_NIB(REG)			    ((REG) | (0xF))                                             // Set The Low Nibble in a Register.
#define CLR_LOW_NIB(REG)			    ((REG) | 0)		                                            // Clear The Low Nibble in a Register. 
#define GET_LOW_NIB(REG)	    	    ((REG) & (0xF))	                                            // Get The Low Nibble in a Register. 
#define TGL_LOW_NIB(REG)			    ((REG) ^ (0xF))		                                        // Toggle the Low Nibble in a Register.


/**************************		   ASSIGN --> REG - HIG_NIB - LOW_NIB      *********************/
#define ASSIGN_REG(REG,VALUE)           ((REG) = VALUE)												// Assign REG with VALUE
#define ASSIGN_HIG_NIB(REG,VALUE)		(CLR_H_NIB(REG) | VALUE << sizeof(REG) * 8 - 4)             // Assign HIGH nibble in REG with VALUE
#define ASSIGN_LOW_NIB(REG,VALUE)		(CLR_L_NIB(REG) | VALUE)                                    // Assign LOW nibble in REG with VALUE



/**************************		      SHIFT_RIGHT - SHIFT_Left             *********************/
#define SHIFT_RIGHT(REG,VALUE)         	((REG)>> (Bit_NO))                                          // Right Shift by NO
#define SHIFT_Left(REG,VALUE)			((REG)<< (Bit_NO))                                          // Left Shift by NO


/**************************   Circular Right Shift & Circular Left Shift   *********************/
#define CLR_RIGHT_SHIFT(REG,VALUE)		(((REG) >> Bit_NO) | ((REG) << sizeof(REG) * 8 - Bit_NO))   // Circular Right Shift
#define CLR_LEFT_SHIFT(REG,VALUE)       (((REG) << Bit_NO) | ((REG) >> sizeof(REG) * 8 - Bit_NO))   // Circular Left Shift


#endif
