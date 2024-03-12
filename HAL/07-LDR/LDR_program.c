/*
 * LDR_program.c
 *
 * Created: 3/8/2024 5:51:52 PM
 *  Author: Tarek Alaa
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LDR_interface.h"
#include "LDR_config.h"

void LDR_voidInit()
{
	DIO_voidSetPinDirection(LDR_PORT, LDR_PIN, DIO_PIN_INPUT);
	ADC_voidInit(LDR_strADCConfig);
}
void LDR_voidGetLightIntinsity(u16 *copy_pf32LightIntinsity)
{
	u16 digital;
	ADC_voidGetDigitalValue(LDR_strADCConfig.enumChannelNum, &digital);
	*copy_pf32LightIntinsity=((f32)digital/1023.0f)*100.0f;
}