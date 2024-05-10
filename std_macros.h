/*
 * std_macros.h
 *
 * Created: 8/17/2023 12:27:17 AM
 *  Author: mahmoud
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) (reg&(1<<bit))>>bit
#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))
#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))

#endif /* STD_MACROS_H_ */