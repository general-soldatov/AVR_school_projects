/*
 * LAB_7.c
 *
 * Created: 21.01.2025 16:40:13
 * Author : GS
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include "digit.h"
#define DIGIT 10

unsigned char i;

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


void timer_ini(void)
{
	TCCR1B |= (1 << WGM12);
	TIMSK |= (1 << OCIE1A);
	OCR1AH = 0b01111010;
	OCR1AL = 0b00010010;
	TCCR1B |= (1<<CS12);
}

ISR (TIMER1_COMPA_vect)
{
	if (i > 9) i = 0;
	PORTB = digit_out(i);
	i++;
}

int main(void)
{
    timer_ini();
	DDRD = 0x00;
	PORTD = (1 << 0);
	DDRB = 0xFF;
	i = 0;
	sei();
    while (1) 
    {
    }
}

