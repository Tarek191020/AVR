/*
 * ADC_interface.h
 *
 * Created: 3/4/2024 11:31:08 AM
 *  Author: Tarek Alaa
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef enum
{
	AREF,
	AVCC,
	INTERNALVREF //2.56v
}VREF_t;

typedef enum
{
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7
}ADC_CHANNEL_t;

void ADC_voidInit(VREF_t copy_enumVref);
void ADC_voidGetDigitalValue(ADC_CHANNEL_t copy_enumChannelNum, u16 *copy_pu16Value);


#endif /* ADC_INTERFACE_H_ */