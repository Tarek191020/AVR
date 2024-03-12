/*
 * LM35_program.c
 *
 * Created: 3/8/2024 4:55:01 PM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_config.h"
#include "LM35_interface.h"

void LM35_voidInit()
{
	DIO_voidSetPinDirection(LM35_PORT, LM35_PIN, DIO_PIN_INPUT);
	ADC_voidInit(LM35_strADCConfig);
}
void LM35_voidGetTemprature_degree(u16 *copy_ptrtemprature)
{
	u16 digital;
	u16 analog;
	ADC_voidGetDigitalValue(LM35_strADCConfig.enumChannelNum, &digital);
	switch(LM35_strADCConfig.enumVREF)
	{
		case ADC_INTERNALVREF:
			analog=((u32)digital*2560)/1024;
			break;
		case ADC_AVCC:
			analog=((u32)digital*5000)/1024;
			break;
		case ADC_AREF:
			analog=((u32)digital*5000)/1024;
			break;
	}
	*copy_ptrtemprature=analog/10;	
}