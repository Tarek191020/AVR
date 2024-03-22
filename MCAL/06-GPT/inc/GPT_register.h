/*
 * GPT_register.h
 *
 * Created: 3/16/2024 10:30:43 AM
 *  Author: Tarek Alaa
 */ 


#ifndef GPT_REGISTER_H_
#define GPT_REGISTER_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"


						/***********************************TMR0REGS**************************************/
// Timer/Counter0 Control Register
#define TCCR0_REG			(*(volatile u8*)0x53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

// Timer/Counter0 Register
#define TCNT0_REG           (*(volatile u8*)0x52)

// Output Compare Register0
#define OCR0_REG            (*(volatile u8*)0x5C)


						/***********************************TMR1REGS**************************************/
// Timer/Counter1 Control RegisterA
#define TCCR1A_REG			(*(volatile u8*)0x4F)
#define WGM10               0
#define WGM11               1
#define FOC1B               2
#define FOC1A				3
#define COM1B0				4
#define COM1B1				5
#define COM1A0				6
#define COM1A1				7

// Timer/Counter1 Control RegisterB
#define TCCR1B_REG			(*(volatile u8*)0x4E)
#define CS10				0
#define CS11				1
#define CS12				2
#define WGM12				3
#define WGM13				4
#define ICES1				6
#define ICNC1				7

// Timer/Counter1 Register
#define TCNT1_REG			(*(volatile u16*)0x4C)

// Output Compare Register1A
#define OCR1A_REG			(*(volatile u16*)0x4A)

// Output Compare Register1B
#define OCR1B_REG			(*(volatile u16*)0x48)

// Input Capture Register1
#define ICR1_REG			(*(volatile u16*)0x46)


						/***********************************TMR2REGS**************************************/
// Timer/Counter2 Control Register
#define TCCR2_REG			(*(volatile u8*)0x45)
#define CS20                0
#define CS21                1
#define CS22                2
#define WGM21               3
#define COM20               4
#define COM21               5
#define WGM20               6
#define FOC0                7

// Timer/Counter2 Register
#define TCNT2_REG           (*(volatile u8*)0x44)

// Output Compare Register2
#define OCR2_REG            (*(volatile u8*)0x43)


// Timer/Counter Interrupt Mask Register
#define TIMSK_REG           (*(volatile u8*)0x59)
#define TOIE0               0
#define OCIE0               1
#define TOIE1				2
#define OCIE1B				3
#define OCIE1A				4
#define TICIE1				5
#define TOIE2				6
#define OCIE2				7

// Timer/Counter Interrupt Flag Register
#define TIFR_REG            (*(volatile u8*)0x58)
#define TOV0                0
#define OCF0                1
#define TOV1				2
#define OCF1B				3
#define OCF1A				4
#define ICF1				5
#define TOV2				6
#define OCF2				7



#endif /* TIMERS_REGISTER_H_ */