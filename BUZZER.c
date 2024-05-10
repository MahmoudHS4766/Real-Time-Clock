/*
 * BUZZER.c
 *
 * Created: 10/1/2023 5:14:53 PM
 *  Author: Mahmoud Hamdy
 */ 

#include "BUZZER.h"

void BUZZER_Init(port,pinnum)
{
	DIO_setPINdir(port,pinnum,1);
}

void BUZZER_turnON(port,pinnum)
{
	DIO_writePIN(port,pinnum,1);
}

void BUZZER_turnOFF(port,pinnum)
{
	DIO_writePIN(port,pinnum,0);
}