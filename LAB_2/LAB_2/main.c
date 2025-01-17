#include <avr/io.h>
#define  F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	DDRB = 0b11111111;
	while (1)
	{
		
		PORTB = (1<<0); _delay_ms(250);
		PORTB = (1<<7); _delay_ms(250);
		PORTB = (1<<1); _delay_ms(250);
		PORTB = (1<<6); _delay_ms(250);
		PORTB = (1<<2); _delay_ms(250);
		PORTB = (1<<5); _delay_ms(250);
		PORTB = (1<<3); _delay_ms(250);
		PORTB = (1<<4); _delay_ms(250);
	}
}
