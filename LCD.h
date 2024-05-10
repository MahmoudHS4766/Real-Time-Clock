/*
 * LCD.h
 *
 * Created: 9/11/2023 12:25:10 AM
 *  Author: mahmoud hamdy
 */ 


#ifndef LCD_H_
#define LCD_H_ 

#include "DIO.h"
#define F_CPU 8000000ul
#include <util/delay.h>

#define LCD_DATAPORT 'A'
#define LCD_CTRPORT 'A'
#define EN 0
#define RW 1
#define RS 2


#define four_bit_mode /*eight  for 8_bit mode/ four for 4_bit mode*/

#if defined eight_bit_mode
#define FUNCTION_SET 0x38
#elif defined four_bit_mode
#define FUNCTION_SET 0x28 
#endif
#define DISPLAY_ON_OFF 0x0E
#define CLEAR_DISP 0x01
#define RETURN_HOME 0x02
#define ENTRY 0x06




static void enable(void);
void LCD_sendChar(char data);
void LCD_sendCMD(char command);
void LCD_Init (void);
void LCD_clear_screen(void);
void LCD_send_string(char *data);
void LCD_savedChar(void);

/*row 1:2 / column 1:16*/
void LCD_move_cursor(char row, char column);


#endif /* LCD_H_ */