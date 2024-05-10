/*
 * RealTimeClock.c
 *
 * Created: 10/1/2023 10:59:21 AM
 *  Author: Mahmoud Hamdy
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "Timer.h"
#include "Keybad_driver.h"
#include "seven_segments.h"
#include "DIO.h"
#include "BUZZER.h"
#define SEVEN_SEG_PORT 'D'
#define SEVEN_SEG_EN_PORT 'C'
#define NOT_SET 255


volatile unsigned char seconds_counter;
unsigned char minutes_counter,hours_counter;
unsigned char key_val;
unsigned char alarm_hour=NOT_SET,alarm_minutes=NOT_SET;
int main(void)
{
	TIMER2_OVERFLOW_Init_interrupt();
	LCD_Init();
	Keybad_Init();
	BUZZER_Init('A',3);
	seven_segments_Init(SEVEN_SEG_PORT);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,0,1);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,1,1);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,2,1);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,3,1);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,4,1);
	DIO_setPINdir(SEVEN_SEG_EN_PORT,5,1);
	
	LCD_send_string("1 : set Time");
	LCD_move_cursor(2,1);
	LCD_send_string("2 : create Alarm");

    while(1)
    {
		key_val = Keybad_getKey();
		if (key_val == '1')
		{
			DIO_writePORT(SEVEN_SEG_EN_PORT,0x00);
			DIO_writePORT(SEVEN_SEG_PORT,0x40);		
			LCD_clear_screen();
			LCD_send_string("    Set Time");
			LCD_move_cursor(2,5);
			LCD_send_string("--:--:--");
			while(Keybad_getKey()!=NOT_PRESSED);
			
			/*set hours*/
			LCD_move_cursor(2,5);
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			hours_counter = (key_val-48)*10;
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			hours_counter += (key_val-48); 
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			/*set minutes*/
			LCD_move_cursor(2,8);
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			minutes_counter = (key_val-48)*10;
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			minutes_counter += (key_val-48);
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);					
			
			/*set seconds*/
			LCD_move_cursor(2,11);
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			seconds_counter = (key_val-48)*10;
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			seconds_counter += (key_val-48);
			LCD_sendChar(key_val);
			LCD_clear_screen();
			LCD_send_string("1 : set Time");
			LCD_move_cursor(2,1);
			LCD_send_string("2 : create Alarm");
			
		}
		else if(key_val=='2')
		{
			DIO_writePORT(SEVEN_SEG_EN_PORT,0x00);
			DIO_writePORT(SEVEN_SEG_PORT,0x40);
			LCD_clear_screen();
			LCD_send_string("  create Alarm");
			LCD_move_cursor(2,3);
			LCD_send_string("--:-- HH:MM");
			while(Keybad_getKey()!=NOT_PRESSED);
			LCD_move_cursor(2,3);
			/*set hours*/
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			alarm_hour = (key_val-48)*10;
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			alarm_hour += (key_val-48);
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			/*set minutes*/
			LCD_move_cursor(2,6);
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			alarm_minutes = (key_val-48)*10;
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);
			
			do
			{
				key_val = Keybad_getKey();

			} while (key_val==NOT_PRESSED);
			alarm_minutes += (key_val-48);
			LCD_sendChar(key_val);
			while(Keybad_getKey()!=NOT_PRESSED);	
			LCD_clear_screen();
			LCD_send_string("1 : set Time");
			LCD_move_cursor(2,1);
			LCD_send_string("2 : create Alarm");		
		}

         DIO_writePIN(SEVEN_SEG_EN_PORT,0,0);
		 DIO_writePIN(SEVEN_SEG_EN_PORT,1,1);
		 DIO_writePIN(SEVEN_SEG_EN_PORT,2,1);
		 DIO_writePIN(SEVEN_SEG_EN_PORT,3,1);
		 DIO_writePIN(SEVEN_SEG_EN_PORT,4,1);
		 DIO_writePIN(SEVEN_SEG_EN_PORT,5,1);
		 seven_segments_write(SEVEN_SEG_PORT,seconds_counter%10);
		 _delay_ms(5);
         DIO_writePIN(SEVEN_SEG_EN_PORT,0,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,1,0);
         DIO_writePIN(SEVEN_SEG_EN_PORT,2,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,3,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,4,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,5,1);
         seven_segments_write(SEVEN_SEG_PORT,seconds_counter/10);
		 _delay_ms(5);
         DIO_writePIN(SEVEN_SEG_EN_PORT,0,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,1,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,2,0);
         DIO_writePIN(SEVEN_SEG_EN_PORT,3,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,4,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,5,1);
         seven_segments_write(SEVEN_SEG_PORT,minutes_counter%10);
		 _delay_ms(5);
         DIO_writePIN(SEVEN_SEG_EN_PORT,0,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,1,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,2,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,3,0);
         DIO_writePIN(SEVEN_SEG_EN_PORT,4,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,5,1);
         seven_segments_write(SEVEN_SEG_PORT,minutes_counter/10);
		 _delay_ms(5);
         DIO_writePIN(SEVEN_SEG_EN_PORT,0,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,1,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,2,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,3,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,4,0);
         DIO_writePIN(SEVEN_SEG_EN_PORT,5,1);
         seven_segments_write(SEVEN_SEG_PORT,hours_counter%10);
         _delay_ms(5);
         DIO_writePIN(SEVEN_SEG_EN_PORT,0,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,1,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,2,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,3,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,4,1);
         DIO_writePIN(SEVEN_SEG_EN_PORT,5,0);
         seven_segments_write(SEVEN_SEG_PORT,hours_counter/10);
         _delay_ms(5);
		 if (hours_counter==alarm_hour && minutes_counter==alarm_minutes)
		 {
			 BUZZER_turnON('A',3);
		 }
		 else
		 {
			 BUZZER_turnOFF('A',3);
		 }
		 if (seconds_counter>=60)
		 {
			 seconds_counter=0;
			 minutes_counter++;
		 }
		 if (minutes_counter>=60)
		 {
			 minutes_counter=0;
			 hours_counter++;
		 }
         if (hours_counter>=24)
         {
	         hours_counter=0;
         }
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}