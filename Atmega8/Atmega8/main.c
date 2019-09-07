#define  F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	TCCR2 = (1 << COM21) | (1 << WGM20) | (1 << CS22) | (1 << CS20);
	while (1)
	{
		OCR2 = 0;
		_delay_ms(1000);
		OCR2 = 127;
		_delay_ms(1000);
		OCR2 = 255;
		_delay_ms(1000);	
	}
}

