/*
 * LDR_config.h
 *
 * Created: 3/8/2024 5:52:31 PM
 *  Author: Tarek Alaa
 */ 


#ifndef LDR_CONFIG_H_
#define LDR_CONFIG_H_

#include "ADC_interface.h"

#define LDR_PORT    DIO_PORTA
#define LDR_PIN     DIO_PIN0

ADC_CONFIG_t LDR_strADCConfig={
	.enumVREF = ADC_AVCC,
	.enumChannelNum = ADC_CHANNEL0,
	.enumAdjustResult = ADC_ADJUSTRIGHT,
	.enumPrescaler = ADC_128_PRESCALER
};



#endif /* LDR_CONFIG_H_ */