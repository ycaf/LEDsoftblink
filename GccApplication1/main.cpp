/*
 * GccApplication1.cpp
 *
 * Created: 20-Oct-17 12:21:04
 * Author : ycaf
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU =  16000000;

int main(void)
{
	DDRB |=  (1<<PB1);//set OC1A as output PORTB1 pin15
	// use 8-bit mode PWM by setting the WGM10 and the WGM12 bits
	TCCR1A |= (1<<COM1A1) | (1<<WGM10);
	TCCR1B |= (1<<WGM12) | (1<<CS11);         //set clock / 8 prescaler0b00001010;
	OCR1A = 0;
	uint8_t brightness;
	
	while(1)
	{
		for (brightness = 0; brightness < 255; ++brightness)
		{
			OCR1A = brightness;
			_delay_ms(10);
		}
		
		for (brightness = 255; brightness > 0; --brightness)
		{
			OCR1A = brightness;
			_delay_ms(10);
		}
	//	OCR1A++;
		// duty cylce of 50%
	//	_delay_ms(10);
	}

}
