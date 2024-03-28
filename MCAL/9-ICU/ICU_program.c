/*
 * ICU_program.c
 *
 * Created: 3/23/2024 11:44:06 PM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ICU_interface.h"
#include "ICU_register.h"
#include "ICU_config.h"
#include "ICU_private.h"

static void (*PRV_pFunCallBackICU)(void) = NULL;

void ICU_voidInit(void)
{
	//Deinitialize the ICU
	ICU_voidDeInit();
	
	// Configure Timer1 mode (normal mode)
	TCCR1A_REG = 0;
	
	// Enable input capture interrupt
	SET_BIT(TIMSK_REG, TICIE1);
	SET_BIT(TIMSK_REG, TOIE1);
	
	/* Select the required edge*/
	TCCR1B_REG |= (1<<6);
}

void ICU_voidStartCapture(void)
{
	// Start capturing input signals with the configured prescaler	
	TCCR1B_REG |= ICU_PRESCALER;
}

void ICU_voidEdgeSel(ICU_EDGE_t copy_u8EdgeSEL)
{
	/* Select the required edge*/
	switch(copy_u8EdgeSEL)
	{
		case ICU_FALLING_EDGE:
		CLR_BIT(TCCR1B_REG, ICES1);
		break;
		case ICU_RISEING_EDGE:
		SET_BIT(TCCR1B_REG, ICES1);
		break;
	}
}

void ICU_voidGetCapturedTime(u32* copy_u32CapturedValue)
{
	// Read captured value from input capture register
	*copy_u32CapturedValue = ICR1_REG;
}

void ICU_voidClearTimerValue(void)
{
	// Clear both the timer and input capture registers
	TCNT1_REG = 0;
	ICR1_REG = 0;
}
void ICU_voidStopCapture(void)
{
	// Stop the timer by clearing the timer control register bits
	TCCR1B_REG &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
}

void ICU_voidSetCallBack(void (*copy_pFunActionICU)(void))
{
	// Set the callback function for ICU interrupt
	if (copy_pFunActionICU != NULL)
	{
		PRV_pFunCallBackICU=copy_pFunActionICU;
	}	
}

void ICU_voidDeInit(void)
{
	PRV_pFunCallBackICU = NULL;
	/* Disable the ICU interrupt*/
	CLR_BIT(TIMSK_REG,TICIE1);
	
	/* Reset/Clear TCCR1A register*/
	TCCR1A_REG = 0;
	
	/* Reset/Clear TCCR1B register*/
	TCCR1B_REG = 0;
	
	/* Clear timer register value*/
	TCNT1_REG = 0;
	
	/* Clear ICU register value*/
	ICR1_REG = 0;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(PRV_pFunCallBackICU != NULL)
	{
		PRV_pFunCallBackICU();
	}

}

