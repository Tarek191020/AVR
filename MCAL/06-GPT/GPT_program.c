/*
 * GPT_program.c
 *
 * Created: 3/16/2024 10:31:22 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPT_interface.h"
#include "GPT_config.h"
#include "GPT_private.h"
#include "GPT_register.h"

#define F_CPU 16000000UL

					/*****************************TMR0************************************/
static u32 PRV_u32ctcCounter = TMR0_OC_COUNTER;

static void (*PRV_pFunCallBackOVF)()='\0';
static void (*PRV_pFunCallBackCTC)()='\0';

void TMR0_voidInit(void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
		//select normal mode
		CLR_BIT(TCCR0_REG, WGM00);
		CLR_BIT(TCCR0_REG, WGM01);
		//init timer with preload value
		TCNT0_REG = TMR0_PRELOAD_VALUE;
		//enable overflow interrupt
		SET_BIT(TIMSK_REG, TOIE0);
	#elif TMR0_MODE == TMR0_CTC_MODE
		//select ctc mode
		CLR_BIT(TCCR0_REG, WGM00);
		SET_BIT(TCCR0_REG, WGM01);
		//set top value
		OCR0_REG = TMR0_COMPARE_VALUE;
		//enable compare match interrupt
		SET_BIT(TIMSK_REG, OCIE0); 
	#endif
}
void TMR0_voidStart(TMR_PRESCALER_t copy_enumPrescaler)
{
	TCCR0_REG |= copy_enumPrescaler;
}
void TMR0_voidStop(void)
{
	//select no clock
	TCCR0_REG |= 0;
}

void TMR0_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms)
{
	
	u16 ticks_per_ms = 0;
	u32 ticks_needed = 0;
	
	// Determine the prescaler value and tick time based on the selected prescaler
	#if TMR0_PRESCALER == TMR0_1_PRESCALER
	ticks_per_ms = 16000;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR0_PRESCALER == TMR0_8_PRESCALER
	ticks_per_ms = 2000;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR0_PRESCALER == TMR0_64_PRESCALER
	ticks_per_ms = 250;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR0_PRESCALER == TMR0_256_PRESCALER
	ticks_per_ms = 62;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR0_PRESCALER == TMR0_1024_PRESCALER
	ticks_per_ms = 16;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#endif
	
	//u16 ticks_per_ms = F_CPU /(1000* prescaler);
	//u32 ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	
	OCR0_REG = 249;
	
	PRV_u32ctcCounter = (ticks_needed/(OCR0_REG+1));
	
	
}

void TMR0_voidSetCallBack(void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!='\0')
	{
		#if TMR0_MODE == TMR0_NORMAL_MODE
				PRV_pFunCallBackOVF=copy_pFunAction;
		#elif TMR0_MODE == TMR0_CTC_MODE
				PRV_pFunCallBackCTC=copy_pFunAction;
		#endif
	}
	else
	{
		//return error state
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	if (TMR0_OVF_COUNTER == local_u16OVFCounter)
	{
		//init timer with preload value
		TCNT0_REG = TMR0_PRELOAD_VALUE;
		//clear counter
		local_u16OVFCounter = 0;
		//call Action
		PRV_pFunCallBackOVF();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 local_u16CTCCounter = 0;
	local_u16CTCCounter++;
	if (PRV_u32ctcCounter == local_u16CTCCounter)
	{
		//clear counter
		local_u16CTCCounter = 0;
		//call Action
		if (PRV_pFunCallBackCTC!='\0')
		{
			PRV_pFunCallBackCTC();
		}
	}
}


					/*****************************TMR1************************************/
static u32 PRV_u32ctcCounter1 = TMR1_OCA_COUNTER;

static void (*PRV_pFunCallBackOVF1)()='\0';
static void (*PRV_pFunCallBackOCR1A)()='\0';

void TMR1_voidInit(void)
{
	#if TMR1_MODE == TMR1_NORMAL_MODE
	//select normal mode
	CLR_BIT(TCCR1A_REG, WGM10);
	CLR_BIT(TCCR1A_REG, WGM11);
	CLR_BIT(TCCR1B_REG, WGM12);
	CLR_BIT(TCCR1B_REG, WGM13);
	//init timer with preload value
	TCNT1_REG = TMR1_PRELOAD_VALUE;
	//enable overflow interrupt
	SET_BIT(TIMSK_REG, TOIE1);
	#elif TMR1_MODE == TMR1_CTC_MODE_OCR1A
	//select ctc mode using OCR1A Register
	CLR_BIT(TCCR1A_REG, WGM10);
	CLR_BIT(TCCR1A_REG, WGM11);
	SET_BIT(TCCR1B_REG, WGM12);
	CLR_BIT(TCCR1B_REG, WGM13);
	//set top value
	OCR1A_REG = TMR1_COMPA_VALUE;
	//enable compare match interrupt
	SET_BIT(TIMSK_REG, OCIE1A);
	#endif
}
void TMR1_voidStart(TMR_PRESCALER_t copy_enumPrescaler)
{
	//select prescaler
	TCCR1B_REG |= copy_enumPrescaler;
}
void TMR1_voidStop(void)
{
	//select no clock
	TCCR1B_REG |= 0;
}
void TMR1_voidSetDelay_ms_UsingCTC(u32 copy_u32Delay_ms)
{
	 u32 ticks_needed = 0;

	 // Determine the prescaler value and tick time based on the selected prescaler
	 #if TMR1_PRESCALER == TMR1_1_PRESCALER
	 OCR1A_REG = 15999;
	 ticks_needed = copy_u32Delay_ms * 16000;  // Timer1 operates at 1 MHz
	 #elif TMR1_PRESCALER == TMR1_8_PRESCALER
	 OCR1A_REG = 1999;
	 ticks_needed = copy_u32Delay_ms * 2000;   // Timer1 operates at 125 kHz
	 #elif TMR1_PRESCALER == TMR1_64_PRESCALER
	 OCR1A_REG = 249;
	 ticks_needed = copy_u32Delay_ms * 250;    // Timer1 operates at 16 kHz
	 #elif TMR1_PRESCALER == TMR1_256_PRESCALER
	 OCR1A_REG = 62;
	 ticks_needed = copy_u32Delay_ms * 63;     // Timer1 operates at 4 kHz
	 #elif TMR1_PRESCALER == TMR1_1024_PRESCALER
	 OCR1A_REG = 15;
	 ticks_needed = copy_u32Delay_ms*16;         // Timer1 operates at 1 kHz
	 #endif
	 
	 // Calculate the number of cycles needed for the delay
	 PRV_u32ctcCounter1 = ticks_needed / (OCR1A_REG + 1);
	
}

void TMR1_voidSetCallBack(void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!='\0')
	{
		#if TMR1_MODE == TMR1_NORMAL_MODE
		PRV_pFunCallBackOVF1=copy_pFunAction;
		#elif TMR1_MODE == TMR1_CTC_MODE_OCR1A
		PRV_pFunCallBackOCR1A=copy_pFunAction;
		#endif
	}
	else
	{
		//return error state
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	if (TMR1_OVF_COUNTER == local_u16OVFCounter)
	{
		//init timer with preload value
		TCNT1_REG = TMR1_PRELOAD_VALUE;
		//clear counter
		local_u16OVFCounter = 0;
		//call Action
		PRV_pFunCallBackOVF1();
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u32 local_u16CTCCounter = 0;
	local_u16CTCCounter++;
	if (PRV_u32ctcCounter1 == local_u16CTCCounter)
	{
		//clear counter
		local_u16CTCCounter = 0;
		//call Action
		if (PRV_pFunCallBackOCR1A!='\0')
		{
			PRV_pFunCallBackOCR1A();
		}
	}
}


					/*****************************TMR2************************************/
static u32 PRV_u32ctcCounter2 = TMR2_OC_COUNTER;
static void (*PRV_pFunCallBackOVF2)()='\0';
static void (*PRV_pFunCallBackCTC2)()='\0';


void TMR2_voidInit(void)
{
	#if TMR2_MODE == TMR2_NORMAL_MODE
	//select normal mode
	CLR_BIT(TCCR2_REG, WGM20);
	CLR_BIT(TCCR2_REG, WGM21);
	//init timer with preload value
	TCNT2_REG = TMR2_PRELOAD_VALUE;
	//enable overflow interrupt
	SET_BIT(TIMSK_REG, TOIE2);
	#elif TMR2_MODE == TMR2_CTC_MODE
	//select ctc mode
	CLR_BIT(TCCR2_REG, WGM20);
	SET_BIT(TCCR2_REG, WGM21);
	//set top value
	OCR2_REG = TMR2_COMPARE_VALUE;
	//enable compare match interrupt
	SET_BIT(TIMSK_REG, OCIE2);
	#endif
}
void TMR2_voidStart(TMR_PRESCALER_t copy_enumPrescaler)
{
	TCCR2_REG |= copy_enumPrescaler;
}
void TMR2_voidStop(void)
{
	//select no clock
	TCCR2_REG |= 0;
}
void TMR2_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms)
{
	
	u16 ticks_per_ms = 0;
	u32 ticks_needed = 0;
	
	// Determine the prescaler value and tick time based on the selected prescaler
	#if TMR2_PRESCALER == TMR2_1_PRESCALER
	ticks_per_ms = 16000;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR2_PRESCALER == TMR2_8_PRESCALER
	ticks_per_ms = 2000;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR2_PRESCALER == TMR2_64_PRESCALER
	ticks_per_ms = 250;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR2_PRESCALER == TMR2_256_PRESCALER
	ticks_per_ms = 62;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#elif TMR2_PRESCALER == TMR2_1024_PRESCALER
	ticks_per_ms = 16;
	ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	#endif
	
	//u16 ticks_per_ms = F_CPU /(1000* prescaler);
	//u32 ticks_needed = (u32)copy_u16Delay_ms * ticks_per_ms;
	
	OCR2_REG = 249;
	
	PRV_u32ctcCounter2 = (ticks_needed/(OCR0_REG+1));
	
	
}

void TMR2_voidSetCallBack(void(*copy_pFunAction)(void))
{
	if (copy_pFunAction!='\0')
	{
		#if TMR2_MODE == TMR2_NORMAL_MODE
		PRV_pFunCallBackOVF2=copy_pFunAction;
		#elif TMR2_MODE == TMR2_CTC_MODE
		PRV_pFunCallBackCTC2=copy_pFunAction;
		#endif
	}
	else
	{
		//return error state
	}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	if (TMR2_OVF_COUNTER == local_u16OVFCounter)
	{
		//init timer with preload value
		TCNT2_REG = TMR2_PRELOAD_VALUE;
		//clear counter
		local_u16OVFCounter = 0;
		//call Action
		PRV_pFunCallBackOVF2();
	}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u32 local_u16CTCCounter = 0;
	local_u16CTCCounter++;
	if (PRV_u32ctcCounter2 == local_u16CTCCounter)
	{
		//clear counter
		local_u16CTCCounter = 0;
		//call Action
		if (PRV_pFunCallBackCTC2!='\0')
		{
			PRV_pFunCallBackCTC2();
		}
	}
}
