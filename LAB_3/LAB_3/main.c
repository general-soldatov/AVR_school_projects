/*
 * LAB_3.c
 *
 * Created: 17.01.2025 20:52:38
 * Author : GS
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "BCD.h"

int main(void)
{
    DDRB = 0xFF;
	int arr[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    while (1) 
    {
		for (int i = 0; i < 10; i++)
		{
			PORTB = arr[i];
			_delay_ms(1000);
		}
    }
}

