/*
 * BUZZER.h
 *
 * Created: 10/1/2023 5:15:11 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO.h"

/*Function description: Initialize a buzzer at given PORT and PIN number*/
void BUZZER_Init(port,pin);
/*Function description: turn ON a buzzer at given PORT and PIN number*/
void BUZZER_turnON(port,pinnum);
/*Function description: turn OFF a buzzer at given PORT and PIN number*/
void BUZZER_turnOFF(port,pinnum);



#endif /* BUZZER_H_ */