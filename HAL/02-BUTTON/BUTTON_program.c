/*
 * BUTTON_program.c
 *
 * Created: 3/7/2024 4:31:04 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "BUTTON_interface.h"

void BUTTON_voidInit()
{
	DIO_voidSetPinDirection(BUTTON_PORT, BUTTON_PIN, DIO_PIN_INPUT);
}
void BUTTON_voidGetValue(u8 *copy_pu8value)
{
	DIO_voidGetPinValue(BUTTON_PORT, BUTTON_PIN, copy_pu8value);
}
void BUTTON_voidActivePullUpResistance()
{
	DIO_voidActivePinPullUpResistance(BUTTON_PORT, BUTTON_PIN);
}