/*
 * LCD.c
 *
 * Created: 9/11/2023 12:24:58 AM
 *  Author: mahmoud hamdy
 */ 
#include "LCD.h"

static void enable(void)
{
	DIO_writePIN(LCD_CTRPORT,EN,1);
	_delay_ms(2);
	DIO_writePIN(LCD_CTRPORT,EN,0);
	_delay_ms(2);
}


void LCD_sendChar(char data)
{
	#if defined eight_bit_mode	
	DIO_writePIN(LCD_CTRPORT,RS,1);
	DIO_writePIN(LCD_CTRPORT,RW,0);
	DIO_writePORT(LCD_DATAPORT,data);
	enable();
		
	#elif defined four_bit_mode
	DIO_writePIN(LCD_CTRPORT,RS,1);
	DIO_writePIN(LCD_CTRPORT,RW,0);
	/*the high nibble of the data is sent first followed by the low nibble both sent through high data port nibble*/
	DIO_writeHIGHnibble(LCD_DATAPORT,data>>4);
	enable();
	DIO_writeHIGHnibble(LCD_DATAPORT,data);
	enable();
	#endif
	_delay_ms(1);	
}

void LCD_sendCMD(char command)											
{
	#if defined eight_bit_mode
	DIO_writePIN(LCD_CTRPORT,RS,0);
	DIO_writePIN(LCD_CTRPORT,RW,0);
	DIO_writePORT(LCD_DATAPORT,command);
	enable();
	
	#elif defined four_bit_mode
	DIO_writePIN(LCD_CTRPORT,RS,0);
	DIO_writePIN(LCD_CTRPORT,RW,0);
	DIO_writeHIGHnibble(LCD_DATAPORT,command>>4);
	enable();
	DIO_writeHIGHnibble(LCD_DATAPORT,command);
	enable();
	#endif
	_delay_ms(1);
}

void LCD_Init (void)
{
	_delay_ms(200);
	#if defined eight_bit_mode
	DIO_setPORTdir(LCD_DATAPORT,0xFF);
	DIO_setPINdir(LCD_CTRPORT,RS,1);
	DIO_setPINdir(LCD_CTRPORT,RW,1);
	DIO_setPINdir(LCD_CTRPORT,EN,1);
		
	LCD_sendCMD(FUNCTION_SET);
	_delay_ms(1);
	LCD_sendCMD(DISPLAY_ON_OFF);
	_delay_ms(1);
	LCD_sendCMD(CLEAR_DISP);
	_delay_ms(2);
	LCD_sendCMD(ENTRY);
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_setPINdir(LCD_DATAPORT,4,1); /*choose any sequential 4 bits*/
	DIO_setPINdir(LCD_DATAPORT,5,1);
	DIO_setPINdir(LCD_DATAPORT,6,1);
	DIO_setPINdir(LCD_DATAPORT,7,1);
	DIO_setPINdir(LCD_CTRPORT,RS,1);
	DIO_setPINdir(LCD_CTRPORT,RW,1);
	DIO_setPINdir(LCD_CTRPORT,EN,1);

	LCD_sendCMD(RETURN_HOME);
	_delay_ms(2);	
	LCD_sendCMD(FUNCTION_SET);
	_delay_ms(1);
	LCD_sendCMD(DISPLAY_ON_OFF);
	_delay_ms(1);
	LCD_sendCMD(CLEAR_DISP);
	_delay_ms(2);
	LCD_sendCMD(ENTRY);
	_delay_ms(1);
	#endif
}

void LCD_clear_screen(void)
{
	LCD_sendCMD(CLEAR_DISP);
	_delay_ms(2);
}

void LCD_send_string(char *data)
{
	while(*data != 0)
	{
		LCD_sendChar(*data); 
		data++;
	}
}

void LCD_move_cursor(char row, char column)
{
	char position;
	if (row<1 || row>2 || column<1 || column>16)
	{
	position = 0x80;
	}
	else if (row == 1)
	{
		position = 0x80 + column - 1;
	}
	else if (row == 2)
	{
		position = 0xC0 + column - 1;
	}
	LCD_sendCMD(position);
	_delay_ms(1);
}

void LCD_savedChar(void)
{
		LCD_sendCMD(0x40);
		
		LCD_sendChar(0B00000);// m in arabic
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00010);
		LCD_sendChar(0B00101);
		LCD_sendChar(0B11101);
		LCD_sendChar(0B00110);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00000);
		
		LCD_sendChar(0B11000);//?
		LCD_sendChar(0B00100);
		LCD_sendChar(0B00010);
		LCD_sendChar(0B11111);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00000);
		
		LCD_sendChar(0B00000);//,
		LCD_sendChar(0B00100);
		LCD_sendChar(0B01010);
		LCD_sendChar(0B01110);
		LCD_sendChar(0B00010);
		LCD_sendChar(0B00100);
		LCD_sendChar(0B11000);
		LCD_sendChar(0B00000);
		
		LCD_sendChar(0B00000);//?
		LCD_sendChar(0B00000);
		LCD_sendChar(0B01100);
		LCD_sendChar(0B00010);
		LCD_sendChar(0B00010);
		LCD_sendChar(0B01110);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B00000);
		
		LCD_sendChar(0B00111);//?
		LCD_sendChar(0B00101);
		LCD_sendChar(0B10100);
		LCD_sendChar(0B10010);
		LCD_sendChar(0B11110);
		LCD_sendChar(0B00000);
		LCD_sendChar(0B01100);
		LCD_sendChar(0B00000);
}