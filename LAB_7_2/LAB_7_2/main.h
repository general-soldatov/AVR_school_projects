/*
 * main.h
 *
 * Created: 24.01.2025 20:04:45
 *  Author: GS
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "PWM.h"

#endif /* MAIN_H_ */

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

