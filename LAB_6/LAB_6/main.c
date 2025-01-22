/*
 * LAB_6.c
 *
 * Created: 21.01.2025 12:52:57
 * Author : GS
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "digit.h"
#define DIGIT 10

char digit_out(unsigned char digit)
{
	
	switch(digit)
	{
		case 0: return ZERO;
		case 1: return ONE;
		case 2: return TWO;
		case 3: return THREE;
		case 4: return FOUR;
		case 5: return FIVE;
		case 6: return SIX;
		case 7: return SEVEN;
		case 8: return EIGHT;
		case 9: return NINE;
		
	}
}


int main(void)
{
    unsigned char i, butcount = 0, butstate = 1;
	DDRB = 0xFF;
	DDRD = 0x00;
	PORTD = (1 << 0);
    while (1) 
    {
		for (i = 0; i < DIGIT; i++)
		{
			while (butstate == 0)
			{
				if (!(PIND&(1 << 0)))
				{
					if (butcount < 5)
					{
						butcount++;
					}
					else
					{
						i = 0;
						butstate = 1;
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
						butstate = 1;
					}
				}
			}
			PORTB = digit_out(i);
			_delay_ms(1000);
			butstate = 0;
		}
    }
}

