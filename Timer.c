/*
 * Timer.c
 *
 * Created: 9/25/2023 10:08:50 PM
 *  Author: Mahmoud Hamdy
 */ 
#include "Timer.h"

void TIMER0_CTC_Init_interrupt(void)
{
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM01);
	
	//set OCR0 Value
	OCR0 = 80;
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//Enable interrupt 
	sei();
	SET_BIT(TIMSK,OCIE0);
	 
}

void TIMER0_wave_nonPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM01);
	
	//configure OCn
	SET_BIT(TCCR0,COM00);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;
}

void TIMER0_wave_fastPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//configure OCn, clear on compare match, set at bottom(OVF)
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;	
}

void TIMER0_wave_phasecorrectPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM00);
	
	//configure OCn, clear on compare match up-counting, set at compare match down-counting
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;	
}

void TIMER2_OVERFLOW_Init_interrupt(void)
{
	//configure input clock, external oscillator 32.768kHz crystal
	SET_BIT(ASSR,AS2);
	
	//Configure prescaler
	SET_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS20);
	
	//Enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
}