/*
 * LM35_config.h
 *
 * Created: 3/8/2024 5:15:45 PM
 *  Author: Tarek Alaa
 */ 


#ifndef LM35_CONFIG_H_
#define LM35_CONFIG_H_

#include "ADC_interface.h"

#define LM35_PORT   DIO_PORTA
#define LM35_PIN    DIO_PIN0

ADC_CONFIG_t LM35_strADCConfig={
	.enumVREF = ADC_INTERNALVREF,
	.enumChannelNum = ADC_CHANNEL1,
	.enumAdjustResult = ADC_ADJUSTRIGHT,
	.enumPrescaler = ADC_128_PRESCALER
};



#endif /* LM35_CONFIG_H_ */