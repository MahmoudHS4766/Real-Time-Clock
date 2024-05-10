/*
 * DIO.h
 *
 * Created: 8/18/2023 10:24:23 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef DIO_H_
#define DIO_H_


/*
Function Description : Set the direction of the given pin in the
given port (direction 0 = input : 1 = output)
*/
void DIO_setPINdir(unsigned char PORT,unsigned char pinnum,unsigned char direction);


/*
Function Description : Set the value of the given pin
in the given port (outputvalue 0 = low : 1 = high)
*/
void DIO_writePIN(unsigned char PORT,unsigned char pinnum,unsigned char outputvalue);


/*
Function Description : Returns 1 if the value of the given pin is high and zero if the value
is low
*/
unsigned char DIO_u8read(unsigned char PORT,unsigned char pinnum);


/*
Function Description : Reverse the value of the given pin in the given port.
*/					
void DIO_togglePIN(unsigned char PORT,unsigned char pinnum);


/*
Function Description : set the direction of whole port (direction 0x00 = input : 0xFF = output)  .
*/
void DIO_setPORTdir(unsigned char PORT, unsigned char direction_value);


/*
Function Description : Write the value to all port pins, port_value in hex.
*/
void DIO_writePORT(unsigned char PORT,unsigned char port_value);	


/*
Function Description : read the value of the port .
*/	
unsigned char DIO_readPORT(unsigned char PORT);


/*
Function Description : Reverse the value of the given port.
*/
void DIO_togglePORT(unsigned char PORT);


/*
Function Description : connect a pull up to the given port (status = 1 : pullup on ; status = 0 : pullup off)
*/
void DIO_connectpullup(unsigned char PORT, unsigned char pinnum,unsigned char status);


/*
Function Description : Write the value(in decimal) to the LOW nibble of port in BCD.  
*/
void DIO_writeLOWnibble(unsigned char PORT,unsigned char value);


/*
Function Description : Write the value(in decimal) to the HIGH nibble of port in BCD.
*/
void DIO_writeHIGHnibble(unsigned char PORT,unsigned char value);


#endif /* DIO_H_ */