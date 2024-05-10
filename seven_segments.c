/*
 * seven_segments.c
 *
 * Created: 8/25/2023 12:22:05 AM
 *  Author: Mahmoud Hamdy
 */ 


#include "DIO.h"

void seven_segments_Init(unsigned char port)
{
	DIO_setPORTdir(port,0xFF);
}


/* for common cathode seven segments, for a common anode (~) each variable on the array*/
void seven_segments_write(unsigned char port, unsigned char number) 
{
	unsigned char arr[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	DIO_writePORT(port,arr[number]);
}