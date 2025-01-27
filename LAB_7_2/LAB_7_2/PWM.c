/*
 * PWM.c
 *
 * Created: 24.01.2025 20:03:24
 *  Author: GS
 */ 

#include "PWM.h"

void init_PWM_timer(void)
{
	ASSR = 0x00;
	TCCR2 = 0b01101110;
	TCNT2 = 0x00;
	OCR2 = 0x00;
	TIMSK |= 0x00;
}