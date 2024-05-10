/*
 * seven_segments.h
 *
 * Created: 8/25/2023 12:22:27 AM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_


/*
Function Description : Initialize a seven segments to a given Port, First 7 pins are assigned in port.
*/
void seven_segments_Init(unsigned char port);


/*
Function Description : Write a number on the seven segments.
*/
void seven_segments_write(unsigned char port, unsigned char number);



#endif /* SEVEN_SEGMENTS_H_ */