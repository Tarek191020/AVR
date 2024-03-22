/*
 * GPT_interface.h
 *
 * Created: 3/16/2024 10:30:06 AM
 *  Author: Tarek Alaa
 */ 


#ifndef GPT_INTERFACE_H_
#define GPT_INTERFACE_H_

typedef enum
{
	_NO_CLOCK,
	_NO_PRESCALING,
	_8_PRESCALER,
	_64_PRESCALER,
	_256_PRESCALER,
	_1024_PRESCALER,
	_EXT_CLCK_FALLING,
	_EXT_CLCK_RISING
}TMR_PRESCALER_t;


						/***********************************TMR0**************************************/

void TMR0_voidInit(void);
void TMR0_voidStart(TMR_PRESCALER_t copy_enumPrescaler);
void TMR0_voidStop(void);
void TMR0_voidSetCallBack(void(*copy_pFunAction)(void));
void TMR0_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms);

					   /***********************************TMR1**************************************/

void TMR1_voidInit(void);
void TMR1_voidStart(TMR_PRESCALER_t copy_enumPrescaler);
void TMR1_voidStop(void);
void TMR1_voidSetDelay_ms_UsingCTC(u32 copy_u32Delay_ms);
void TMR1_voidSetCallBack(void(*copy_pFunAction)(void));

   					  /*****************************TMR1************************************/
void TMR2_voidInit(void);
void TMR2_voidStart(TMR_PRESCALER_t copy_enumPrescaler);
void TMR2_voidStop(void);
void TMR2_voidSetCallBack(void(*copy_pFunAction)(void));
void TMR2_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms);

#endif /* TIMERS_INTERFACE_H_ */