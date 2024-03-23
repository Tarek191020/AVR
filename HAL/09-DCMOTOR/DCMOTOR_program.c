/*
 * DCMOTOR_program.c
 *
 * Created: 3/17/2024 7:06:13 PM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PWM_interface.h"

#include "DCMOTOR_interface.h"

void DCMOTOR_voidInit(void)
{
	//set directon of enable pin for motor
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	//set direction of pin direction
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	//set direction of pwm pin
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	
}
void DCMOTOR_voidOn(MOTOR_DIRECTIO_t copy_enumMotorDirection)
{
	DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_HIGH);
	switch(copy_enumMotorDirection)
	{
		case MOTOR_CW:
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
			break;
		case MOTOR_CCW:
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
			break;
		default:
			break;
	}
}
void DCMOTOR_voidOff(void)
{
	// Stop PWM signal
	PWM_voidStop_PWM_Channel_0();
	
	// Disable motor by setting enable pin and PWM pin low
	DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);

}

void DCMOTOR_voidSpeed(u8 copy_u8Speed, MOTOR_DIRECTIO_t copy_enumMotorDirection)
{
	switch(copy_enumMotorDirection)
	{
		case MOTOR_CW:
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
		break;
		case MOTOR_CCW:
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
		break;
		default:
		break;
	}
	PWM_voidInitChannel_0();
	PWM_voidGenerate_PWM_Channel_0(copy_u8Speed,_64_PRESCALER);
	
}