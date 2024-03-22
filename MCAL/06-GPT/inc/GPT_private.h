/*
 * GPT_private.h
 *
 * Created: 3/16/2024 10:31:05 AM
 *  Author: Tarek Alaa
 */ 


#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_


					/*****************************TMR0************************************/
//Prescaler for TMR
#define TMR0_1_PRESCALER		1
#define TMR0_8_PRESCALER		8
#define TMR0_64_PRESCALER		64
#define TMR0_256_PRESCALER		256
#define TMR0_1024_PRESCALER		1024

//modes for TMR0
#define TMR0_NORMAL_MODE		1
#define TMR0_CTC_MODE			2


					/*****************************TMR1************************************/
//Prescaler for TMR
#define TMR1_1_PRESCALER		1
#define TMR1_8_PRESCALER		8
#define TMR1_64_PRESCALER		64
#define TMR1_256_PRESCALER		256
#define TMR1_1024_PRESCALER		1024

//modes for TMR0
#define TMR1_NORMAL_MODE		1
#define TMR1_CTC_MODE_OCR1A		2

					/*****************************TMR2************************************/
//Prescaler for TMR
#define TMR2_1_PRESCALER		1
#define TMR2_8_PRESCALER		8
#define TMR2_64_PRESCALER		64
#define TMR2_256_PRESCALER		256
#define TMR2_1024_PRESCALER		1024

//modes for TMR0
#define TMR2_NORMAL_MODE		1
#define TMR2_CTC_MODE			2

#endif /* TIMERS_PRIVATE_H_ */