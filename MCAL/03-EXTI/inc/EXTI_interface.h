/*
 * EXTI_interface.h
 *
 * Created: 3/3/2024 12:29:15 PM
 *  Author: Tarek Alaa
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "EXTI_register.h"

void (*EXTI0_pvoidActionG)(void);
void (*EXTI1_pvoidActionG)(void);
void (*EXTI2_pvoidActionG)(void);

typedef enum
{
	EXTI_INT0=0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_source_t;

typedef enum
{
	EXTI_RISING_EDGE=0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_senseControl_t;

//enable external interrupt
void EXTI_voidEnable (EXTI_source_t copy_enumInterruptSource, EXTI_senseControl_t copy_enumSenceContrl);
//disable external interrupt
void EXTI_voidDisable (EXTI_source_t copy_enumInterruptSource);
//callback functions for ISR action
void EXTI0_voidCallBack(void (*copy_pvoidAction)(void));
void EXTI1_voidCallBack(void (*copy_pvoidAction)(void));
void EXTI2_voidCallBack(void (*copy_pvoidAction)(void));

#endif /* EXTI_INTERFACE_H_ */