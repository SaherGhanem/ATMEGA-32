/*
 * First_Project.c
 *
 * Created: 1/10/2023 7:30:20 PM
 * Author : hp
 */ 
 #include "Std_types.h"

#include "Bit_math.h"

#include "Delay_Interface.h"
 
#define FCPU 8000000UL

void Delay_ms(u32 Delay)
{
	Delay = (u32)((f32)Delay*((f32)FCPU/1000000.0)*29.41);
	while(Delay)
	{
		asm("NOP");
		Delay--;
	}

}
