/*
 * ADC_register.h
 *
 * Created: 3/4/2024 11:32:24 AM
 *  Author: Tarek Alaa
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX_REG		 *((volatile u8*)0x27)
#define MUX0			 0
#define MUX1			 1
#define MUX2			 2
#define MUX3			 3
#define MUX4			 4
#define ADLAR			 5
#define REFS0			 6
#define REFS1			 7

#define ADCSRA_REG		 *((volatile u8*)0x26)
#define ADPS0			 0
#define ADPS1			 1
#define ADPS2			 2
#define ADIE			 3
#define ADIF			 4
#define ADATE			 5
#define ADSC			 6
#define ADEN			 7

#define ADC_REG			 *((volatile u16*)0x24)

#define SFIOR_REG        *((volatile u8*)0x50)
#define PSR10            0
#define PSR2             1
#define PUD				 2
#define ACME			 3

#define ADTS0			 5
#define ADTS1			 6
#define ADTS2			 7

#endif /* ADC_REGISTER_H_ */