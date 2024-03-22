/*
 * GPT_config.h
 *
 * Created: 3/16/2024 10:30:23 AM
 *  Author: Tarek Alaa
 */ 


#ifndef GPT_CONFIG_H_
#define GPT_CONFIG_H_


				/*****************************TMR0CONFIG**************************************/
/* Options for timer0 mode
1- TMR0_NORMAl_MODE
2- TMR0_CTC_MODE
3- TMR0_FAST_PWM_MODE
*/
#define TMR0_MODE           TMR0_CTC_MODE

/* Options for TMR Prescaler
1- TMR0_1_PRESCALER
2- TMR0_8_PRESCALER
3- TMR0_64_PRESCALER
4- TMR0_256_PRESCALER
5- TMR0_1024_PRESCALER
*/
//select prescaler of timer0 for delay using ctc mode 
#define TMR0_PRESCALER      TMR0_1024_PRESCALER

//put preload value for normal mode
#define TMR0_PRELOAD_VALUE  113
#define TMR0_OVF_COUNTER    977

//put compare value for ctc mode 
#define TMR0_COMPARE_VALUE	249
#define TMR0_OC_COUNTER     1500


					/*****************************TMR1CONFIG************************************/
/* Options for timer1 mode
1- TMR1_NORMAl_MODE
2- TMR1_CTC_MODE_OCR1A
*/
#define TMR1_MODE           TMR1_CTC_MODE_OCR1A

//put preload value for normal mode
#define TMR1_PRELOAD_VALUE  50000
#define TMR1_OVF_COUNTER    1

//put compare value for ctc mode
#define TMR1_COMPA_VALUE	15625
#define TMR1_OCA_COUNTER    1

/* Options for TMR Prescaler
1- TMR1_1_PRESCALER
2- TMR1_8_PRESCALER
3- TMR1_64_PRESCALER
4- TMR1_256_PRESCALER
5- TMR1_1024_PRESCALER
*/
//select prescaler of timer0 for delay using ctc mode
#define TMR1_PRESCALER      TMR1_1_PRESCALER


					/*****************************TMR2CONFIG************************************/
/* Options for timer2 mode
1- TMR0_NORMAl_MODE
2- TMR0_CTC_MODE
*/
#define TMR2_MODE           TMR2_NORMAL_MODE

/* Options for TMR Prescaler
1- TMR2_1_PRESCALER
2- TMR2_8_PRESCALER
3- TMR2_64_PRESCALER
4- TMR2_256_PRESCALER
5- TMR2_1024_PRESCALER
*/
//select prescaler of timer0 for delay using ctc mode
#define TMR2_PRESCALER      TMR2_1024_PRESCALER

//put preload value for normal mode
#define TMR2_PRELOAD_VALUE  113
#define TMR2_OVF_COUNTER    977

//put compare value for ctc mode
#define TMR2_COMPARE_VALUE	249
#define TMR2_OC_COUNTER     1500


#endif /* TIMERS_CONFIG_H_ */