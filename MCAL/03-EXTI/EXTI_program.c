/*
 * EXTI_program.c
 *
 * Created: 3/3/2024 12:28:44 PM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"

void EXTI_voidEnable (EXTI_source_t copy_enumInterruptSource, EXTI_senseControl_t copy_enumSenceContrl)
{
	switch(copy_enumInterruptSource)
	{
		case EXTI_INT0:
		switch(copy_enumSenceContrl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
		}
		SET_BIT(GICR_REG, INT0);
		break;
		case EXTI_INT1:
		switch(copy_enumSenceContrl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
		}
		SET_BIT(GICR_REG, INT1);
		break;
		case EXTI_INT2:
		switch(copy_enumSenceContrl)
		{
			case EXTI_RISING_EDGE:
				SET_BIT(MCUCSR_REG, ISC2);
				break;
			case EXTI_FALLING_EDGE:
				CLR_BIT(MCUCSR_REG, ISC2);
				break;
		}
		SET_BIT(GICR_REG, INT2);
		break;
	}
	
}
void EXTI_voidDisable (EXTI_source_t copy_enumInterruptSource)
{
	switch(copy_enumInterruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR_REG, INT0);
		break;
		case EXTI_INT1:
		CLR_BIT(GICR_REG, INT1);
		break;
		case EXTI_INT2:
		CLR_BIT(GICR_REG, INT2);
		break;
	}
}


void EXTI0_voidCallBack(void (*copy_pvoidAction)(void))
{
	EXTI0_pvoidActionG=copy_pvoidAction;
}

void EXTI1_voidCallBack(void (*copy_pvoidAction)(void))
{
	EXTI1_pvoidActionG=copy_pvoidAction;
}

void EXTI2_voidCallBack(void (*copy_pvoidAction)(void))
{
	EXTI2_pvoidActionG=copy_pvoidAction;
}


void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	EXTI0_pvoidActionG();
}

void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	EXTI1_pvoidActionG();
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	EXTI2_pvoidActionG();
}