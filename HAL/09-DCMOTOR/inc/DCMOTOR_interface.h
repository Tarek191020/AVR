/*
 * DCMOTOR_interface.h
 *
 * Created: 3/17/2024 7:04:32 PM
 *  Author: Tarek Alaa
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


typedef enum
{
	MOTOR_CW,
	MOTOR_CCW
}MOTOR_DIRECTIO_t;


void DCMOTOR_voidInit(void);
void DCMOTOR_voidOn(MOTOR_DIRECTIO_t copy_enumMotorDirection);
void DCMOTOR_voidOff(void);
void DCMOTOR_voidSpeed(u8 copy_u8Speed, MOTOR_DIRECTIO_t copy_enumMotorDirection);


#endif /* DCMOTOR_INTERFACE_H_ */