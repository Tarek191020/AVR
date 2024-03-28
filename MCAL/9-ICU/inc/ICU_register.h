/*
 * ICU_register.h
 *
 * Created: 3/24/2024 1:46:33 AM
 *  Author: Tarek Alaa
 */ 


#ifndef ICU_REGISTER_H_
#define ICU_REGISTER_H_


			/**************************************Timer 1 Registers*****************************************************/
//Timer/Counter1 Control Register A
#define TCCR1A_REG  *((volatile u8*)0x4F)
//Timer/Counter1 Control Register A Bits
#define WGM10		0
#define WGM11		1
#define FOC1B		2
#define FOC1A		3
#define COM1B0		4
#define COM1B1		5
#define COM1A0		6
#define COM1A1		7

//Timer/Counter1 Control Register B
#define TCCR1B_REG  *((volatile u8*)0x4E)
// Timer/Control1 Register B Bits
#define CS10		0
#define CS11        1
#define CS12        2
#define WGM12       3
#define WGM13		4
#define ICES1		6
#define ICNC1		7
     
//Timer/Counter1 Register
#define TCNT1_REG   *((volatile u16*)0x4C)

//Input Capture Register1
#define ICR1_REG    *((volatile u16*)0x46)

//Timer/Counter Interrupt Mask Register
#define TIMSK_REG   *((volatile u8*)0x59)
//Timer/Counter Interrupt Mask RegisterBits
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5

//Timer/Counter Interrupt Flag Register
#define TIFR_REG    *((volatile u8*)0x58)
//Timer/Counter Interrupt Flag Register Bits
#define TOV1		2
#define OCF1B		3
#define OCF1A		4
#define ICF1		5



#endif /* ICU_REGISTER_H_ */