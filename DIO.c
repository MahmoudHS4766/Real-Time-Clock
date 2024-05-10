/*
 * DIO.c
 * DIGITAL i/o driver
 * Created: 8/18/2023 10:24:08 PM
 *  Author: Mahmoud Hamdy
 */
#include <avr/io.h> 
#include "std_macros.h"

void DIO_setPINdir(unsigned char PORT,unsigned char pinnum,unsigned char direction)	
{
	switch (PORT)
	{
		case 'A':
		case 'a':
		if (direction == 1)
		{
			SET_BIT(DDRA,pinnum);
		}		
		else
		{
			CLR_BIT(DDRA,pinnum);
		}
		break;
		
		case 'B':
		case 'b':
		if (direction == 1)
		{
			SET_BIT(DDRB,pinnum);
		}		
		else
		{
			CLR_BIT(DDRB,pinnum);
		}
		break;

		case 'C':
		case 'c':
		if (direction == 1)
		{
			SET_BIT(DDRC,pinnum);
		}
		else
		{
			CLR_BIT(DDRC,pinnum);
		}
		break;
		
		case 'D':
		case 'd':
		if (direction == 1)
		{
			SET_BIT(DDRD,pinnum);
		}
		else
		{
			CLR_BIT(DDRD,pinnum);
		}
		break;
	}	
} 

void DIO_writePIN(unsigned char PORT,unsigned char pinnum,unsigned char outputvalue)
{	
	switch (PORT)
	{
		case 'A':
		case 'a':
		if (outputvalue == 1) 
		{
			SET_BIT(PORTA,pinnum);
		}
		else
		{
			CLR_BIT(PORTA,pinnum);
		}
		break;
		
		case 'B':
		case 'b':
		if (outputvalue == 1)
		{
			SET_BIT(PORTB,pinnum);
		}
		else
		{
			CLR_BIT(PORTB,pinnum);
		}
		break;

		case 'C':
		case 'c':
		if (outputvalue == 1)
		{
			SET_BIT(PORTC,pinnum);
		}
		else
		{
			CLR_BIT(PORTC,pinnum);
		}
		break;
		
		case 'D':
		case 'd':
		if (outputvalue == 1)
		{
			SET_BIT(PORTD,pinnum);
		}
		else
		{
			CLR_BIT(PORTD,pinnum);
		}
		break;
	}	
}

unsigned char DIO_u8read(unsigned char PORT,unsigned char pinnum)
{
	unsigned char return_value;
	
	switch (PORT)
	{
		case 'A':
		case 'a':
		return_value = READ_BIT(PINA,pinnum);
		break;
		
		case 'B':
		case 'b':
		return_value = READ_BIT(PINB,pinnum);
		break;

		case 'C':
		case 'c':
		return_value = READ_BIT(PINC,pinnum);
		break;
		
		case 'D':
		case 'd':
		return_value = READ_BIT(PIND,pinnum);
		break;
	}
	return return_value;
}

void DIO_togglePIN(unsigned char PORT,unsigned char pinnum)
{
	switch (PORT)
	{
		case 'A':
		case 'a':
		TOGGLE_BIT(PORTA,pinnum);
		break;
		
		case 'B':
		case 'b':
		TOGGLE_BIT(PORTB,pinnum);
		break;

		case 'C':
		case 'c':
		TOGGLE_BIT(PORTC,pinnum);
		break;
		
		case 'D':
		case 'd':
		TOGGLE_BIT(PORTD,pinnum);
		break;
	}	
}

void DIO_setPORTdir(unsigned char PORT,unsigned char direction_value)
{
	switch (PORT)
	{
		case 'A':
		case 'a':
		DDRA = direction_value;
		break;
		
		case 'B':
		case 'b':
		DDRB = direction_value;
		break;

		case 'C':
		case 'c':
		DDRC = direction_value;	
		break;
		
		case 'D':
		case 'd':
		DDRD = direction_value;	
		break;
	}
}

void DIO_writePORT(unsigned char PORT,unsigned char port_value)
{
	
	switch (PORT)
	{
		case 'A':
		case 'a':
		PORTA = port_value;
		break;
		
		case 'B':
		case 'b':
		PORTB = port_value;		
		break;

		case 'C':
		case 'c':
		PORTC = port_value;		
		break;
		
		case 'D':
		case 'd':
		PORTD = port_value;		
		break;
	}	
}

unsigned char DIO_readPORT(unsigned char PORT)
{
	unsigned char return_value;
	switch (PORT)
	{
		case 'A':
		case 'a':
		return_value = PINA;
		break;
		
		case 'B':
		case 'b':
		return_value = PINB;
		break;

		case 'C':
		case 'c':
		return_value = PINC;
		break;
		
		case 'D':
		case 'd':
		return_value = PIND;
		break;
	}	
	return return_value;
}

void DIO_togglePORT(unsigned char PORT)
{
	switch (PORT)
	{
		case 'A':
		case 'a':
		PORTA = ~PORTA;  /* PORTA = PORTA ^ 0xFF*/
		break;
		
		case 'B':
		case 'b':
		PORTB = ~PORTB;
		break;

		case 'C':
		case 'c':
		PORTC = ~PORTC;
		break;
		
		case 'D':
		case 'd':
		PORTD = ~PORTD;
		break;
	}	
}

void DIO_connectpullup(unsigned char PORT, unsigned char pinnum,unsigned char status)
{
	DIO_writePIN(PORT,pinnum,status);
}


void DIO_writeLOWnibble(unsigned char PORT,unsigned char value)
{
	value &= 0x0F;
	switch (PORT)
	{
		case 'A':
		case 'a':
		PORTA &= 0xF0;
		PORTA |= value;
		break;
		
		case 'B':
		case 'b':
		PORTB &= 0xF0;
		PORTB |= value;
		break;

		case 'C':
		case 'c':
		PORTC &= 0xF0;
		PORTC |= value;
		break;
		
		case 'D':
		case 'd':
		PORTD &= 0xF0;
		PORTD |= value;
		break;
	}
		
}

void DIO_writeHIGHnibble(unsigned char PORT,unsigned char value)
{
	value <<= 4;
//	value &= 0xF0;
	switch (PORT)
	{
		case 'A':
		case 'a':
		PORTA &= 0x0F;
		PORTA |= value;
		break;
		
		case 'B':
		case 'b':
		PORTB &= 0x0F;
		PORTB |= value;
		break;

		case 'C':
		case 'c':
		PORTC &= 0x0F;
		PORTC |= value;
		break;
		
		case 'D':
		case 'd':
		PORTD &= 0x0F;
		PORTD |= value;
		break;
	}
	
}