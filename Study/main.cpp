#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "bits.h"

volatile static unsigned char av = 0;

unsigned char get_adc() {
	ADCSRA |= (1 << ADSC);
	while (!(ADCSRA & (1 << ADIF)));
	return ADCH;
}

ISR(ADC_vect) {
	cli();
	av = ADCH;
	sei();
}

/*int main(void)
{
	TCCR0A = (1 << COM0A1) | (1 << WGM00);	
	TCCR0B = (1 << CS02) | (1 << CS00);
	while (1)
	{
		char i;
		for (i = 0; i <= 255; ++i) {
			OCR0A = i;
			_delay_ms(10);
		}
	}
}*/

/*int main(void)
{
	ADMUX = (1 << REFS0) | (1 << ADLAR);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	DIDR0 = (1 << ADC0D);
	TCCR0A = (1 << COM0A1) | (1 << WGM00);
	TCCR0B = (1 << CS02) | (1 << CS00);
	while (1)
	{
		OCR0A = get_adc();
	}
}*/

int main(void)
{
	ADMUX = (1 << REFS0) | (1 << ADLAR);
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	DIDR0 = (1 << ADC0D);
	TCCR0A = (1 << COM0A1) | (1 << WGM00);
	TCCR0B = (1 << CS02) | (1 << CS00);
	sei();
	while (1)
	{
		OCR0A = av;
	}
}

/*int main(void)
{
	DDRA = 0x01;
	while (1)
	{
		bit(PORTA,0,1)
		_delay_ms(500);
		bit(PORTA,0,0)
		_delay_ms(500);
	}
}*/