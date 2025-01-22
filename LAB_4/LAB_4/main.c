/*
 * LAB_4.c
 *
 * Created: 20.01.2025 14:49:22
 * Author : GS
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char butcount = 0;
    DDRB = 0xFF;
	DDRD = 0x00;
	PORTD = 1 << 0;
	
    while (1) 
    {
		if (!(PIND&(1 << 0)))
		{
			if (butcount < 5)
			{
				butcount++;
			}
			else
			{
				PORTB = 0xFF;
			}
			
		}
		else
		{
			if (butcount > 0)
			{
				butcount--;
			}
			else
			{
				PORTB = 0x00;
			}			
		}
    }
}

