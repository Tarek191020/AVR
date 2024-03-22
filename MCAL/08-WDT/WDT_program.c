/*
 * WDT_program.c
 *
 * Created: 3/19/2024 10:29:06 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_register.h"

void WDT_voidEnable(WDT_Time_t copy_enumTime)
{
	//select time
	WDTCR_REG |= copy_enumTime;
	
	//enable WDT
	SET_BIT(WDTCR_REG, WDE);
}

void WDT_voidDisable()
{
	//Write logical one to WDTOE and WDE
	WDTCR_REG |= (1<<WDTOE) | (1<<WDE);
	//turn off WDT
	WDTCR_REG=0x00;
}