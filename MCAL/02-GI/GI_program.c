/*
 * GI_program.c
 *
 * Created: 3/3/2024 1:58:13 PM
 *  Author: Tarek Alaa
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GI_register.h"
#include "GI_interface.h"

#include <avr/interrupt.h>

void GI_voidEnable(void)
{
	SET_BIT(SREG_REG,I);
	//sei();
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG_REG,I);
	//cli();
}