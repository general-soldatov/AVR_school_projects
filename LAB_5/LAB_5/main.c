/*
 * LAB_5.c
 *
 * Created: 22.01.2025 17:23:01
 * Author : GS
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "digit.h"
#define DIGIT 10

char i, butcount = 0, butstate = 0;
unsigned char R1 = 0, R2 = 0;

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

void button(void)
{
	while (butstate == 0)
	{
		if (!(PINC&(1 << 0)))
		{
			if (butcount < 5)
			{
				butcount++;
			}
			else
			{
				i = -1;
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

}

void ledout(unsigned char number)
{
	R1 = number % 10;
	R2 = number / 10;
	unsigned char j;
	for (j = 0; j < 100; j++)
	{
		button();
		PORTB = digit_out(R1);
		PORTD = 0b00000001;
		_delay_ms(5);
		PORTB = digit_out(R2);
		PORTD = 0b00000010;	
		_delay_ms(5);
	}
	
}


int main(void)
{
    DDRB = 0xFF;
	DDRD = (1 << 0)|(1 << 1);
	DDRC = 0x00;
	PORTC = (1 << 0);
	
    while (1) 
    {
		
		for(i = 0; i < 100; i++)
		{
			
			butstate = 0;
			ledout(i);
		}
    }
}

