/*
 * LAB_5.c
 *
 * Created: 22.01.2025 17:23:01
 * Author : GS
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include "digit.h"
#define DIGIT 10

unsigned char i, butcount = 0, butstate = 0;
unsigned char R1 = 0, R2 = 0;

void button(void)
{
	while (butstate == 0)
	{
		if (!(PIND&(1 << 3)))
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
}

void ledout(unsigned char number)
{
	R1 = number % 10;
	R2 = number / 10;	
}

void timer_ini(void)
{
	TCCR1B |= (1 << WGM12);
	TIMSK |= (1 << OCIE1A);
	OCR1AH = 0b00001111;
	OCR1AL = (1 << 1)|(1 << 6);
	TCCR1B |= (1 << CS10);
}

unsigned char n_count = 0;

ISR (TIMER1_COMPA_vect)
{
	if (n_count == 0) 
	{
		PORTD &= ~(1 << 0);
		PORTD |= (1 << 1);
		PORTB = digit_out(R2);
	}
	if (n_count == 1)
	{
		PORTD &= ~(1 << 1);
		PORTD |= (1 << 0);
		PORTB = digit_out(R1);
	}
	if (n_count > 1) n_count = 0;
}

int main(void)
{
	timer_ini();
    DDRB = 0xFF;
	DDRD = (1 << 0)|(1 << 1);
	PORTD = (1 << 3);
	sei();
	
    while (1) 
    {
		 for(i = 0; i < 100; i++)
		 {
			button();
		    ledout(i);
			_delay_ms(250);
			butstate=0;

		}
    }
}

