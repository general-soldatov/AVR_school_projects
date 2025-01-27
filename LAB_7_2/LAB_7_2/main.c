/*
 * LAB_7_2.c
 *
 * Created: 24.01.2025 19:19:42
 * Author : GS
 */ 

#include "main.h"

void port_ini(void)
{
	PORTB = 0x00;
	DDRB = 0x08;
}


int main(void)
{
    unsigned char pwm_state = 0;
	port_ini();
	init_PWM_timer();
	OCR2 = 0;
    while (1) 
    {
		
		if (pwm_state == 0)
		{
			OCR2++;
			if (OCR2 > 254)
				pwm_state = 1;
		}
		
		else if (pwm_state == 1)
		{
			OCR2--;
			if (OCR2 < 1)
				pwm_state = 0;
		}
		_delay_ms(30);
		
    }
}

