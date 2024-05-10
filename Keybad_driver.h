/*
 * Keybad_driver.h
 *
 * Created: 9/15/2023 2:42:59 AM
 *  Author: Mamoud Hamdy
 */ 


#ifndef KEYBAD_DRIVER_H_
#define KEYBAD_DRIVER_H_

#define F_CPU 8000000ul
#include <avr/delay.h>
#include "DIO.h"

#define KEYBAD_PORT 'B'
#define NOT_PRESSED 0xFF

#define INTERNAL_PULLUP_ON // if there is external pullup undef

void Keybad_Init(void);
unsigned char Keybad_getKey(void);

#endif /* KEYBAD_DRIVER_H_ */