/*
 * Timer.h
 *
 * Created: 9/25/2023 10:09:00 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"
/*Function description: Enables Timer in CTC mode*/
void TIMER0_CTC_Init_interrupt(void);

/*Function description: Generates non-PWM wave on OC0*/
void TIMER0_wave_nonPWM(void);

/*Function description: Generates fast-PWM wave on OC0*/
void TIMER0_wave_fastPWM(void);

/*Function description: Generates phase-correct-PWM wave on OC0*/
void TIMER0_wave_phasecorrectPWM(void);

/*Function description: Enable timer2 overflow interrupt*/
void TIMER2_OVERFLOW_Init_interrupt(void);




#endif /* TIMER_H_ */