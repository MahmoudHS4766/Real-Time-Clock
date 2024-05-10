/*
 * Keybad_driver.c
 *
 * Created: 9/15/2023 2:42:44 AM
 *  Author: Mamoud Hamdy
 */ 
#include "Keybad_driver.h"

void Keybad_Init(void)
{
	DIO_setPORTdir(KEYBAD_PORT,0x0F); //LOW nibble/row : output, High nibble/column : input 
	#if defined INTERNAL_PULLUP_ON
	{
		DIO_connectpullup(KEYBAD_PORT,4,1);
		DIO_connectpullup(KEYBAD_PORT,5,1);
		DIO_connectpullup(KEYBAD_PORT,6,1);
		DIO_connectpullup(KEYBAD_PORT,7,1);
	}
	#endif
}

unsigned char Keybad_getKey(void)
{
	
	unsigned char arr[4][4]={
							{'7','8','9','/'},
							{'4','5','6','*'},
							{'1','2','3','-'},
							{'c','0','=','+'} };
	unsigned char row,column;
	unsigned char return_value = 0xFF;
	
	for(row=0 ; row<4 ; row++)
	{
		DIO_writePIN(KEYBAD_PORT,0,1);
		DIO_writePIN(KEYBAD_PORT,1,1);
		DIO_writePIN(KEYBAD_PORT,2,1);
		DIO_writePIN(KEYBAD_PORT,3,1);
		DIO_writePIN(KEYBAD_PORT,row,0);
		
		for(column=0 ; column<4 ; column++)
		{
			if(DIO_u8read(KEYBAD_PORT,column+4)==0)//+4 is because the column is in the HIGH nibble >3
			{
				return_value = arr[row][column];
				break;
			}
		}
		if(return_value != NOT_PRESSED)
		{
			
			break;
		}
	}	
	return return_value;
}

