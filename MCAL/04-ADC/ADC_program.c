/*
 * ADC_program.c
 *
 * Created: 3/4/2024 11:33:25 AM
 *  Author: Tarek Alaa
 */ 
#include "ADC_register.h"
#include "ADC_interface.h"

void ADC_voidInit(VREF_t copy_enumVref)
{
	//first disable adc
	CLR_BIT(ADCSRA_REG, ADEN);
	//choose Vref
	switch(copy_enumVref)
	{
		case AREF:
			CLR_BIT(ADMUX_REG, REFS0);
			CLR_BIT(ADMUX_REG, REFS1);
			break;
		case AVCC:
			SET_BIT(ADMUX_REG, REFS0);
			CLR_BIT(ADMUX_REG, REFS1);
			break;
		case INTERNALVREF:
			SET_BIT(ADMUX_REG, REFS0);
			SET_BIT(ADMUX_REG, REFS1);
			break;
	}
	CLR_BIT(ADMUX_REG, ADLAR); //Right_Adj
	/*prescaler 128*/
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);
	//disable Interrupt
	CLR_BIT(ADCSRA_REG, ADIE);
	//Disable autotrigger
	CLR_BIT(ADCSRA_REG, ADATE);
	//ADC Enable
	SET_BIT(ADCSRA_REG, ADEN);
}

void ADC_voidGetDigitalValue(ADC_CHANNEL_t copy_enumChannelNum, u16 *copy_pu16Value)
{
	//choose channel
	if ((copy_pu16Value!='\0')&&(copy_enumChannelNum<32))
	{
		//clear prev channel
		ADMUX_REG &= 0xE0;//0b11100000;
		//set ch
		ADMUX_REG|=copy_enumChannelNum;
		//start conversion
		SET_BIT(ADCSRA_REG, ADSC);
		//Busy wait until flag =1
		while(!(GET_BIT(ADCSRA_REG, ADIF)));
		//clr flag
		SET_BIT(ADCSRA_REG, ADIF);
		//Read data
		*copy_pu16Value = ADC_REG;
	} 
	else
	{
	}
	
}
