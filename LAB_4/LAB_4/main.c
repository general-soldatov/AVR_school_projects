/*
 * LAB_4.c
 *
 * Created: 20.01.2025 14:49:22
 * Author : GS
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0xFF;
	DDRD = 0x00;
	PORTD = 1 << 0;
	
    while (1) 
    {
		if (!(PIND&(1 << 0)))
		{
			PORTB = 0xFF;
		}
		else
		{
			PORTB = 0x00;
		}
    }
}

