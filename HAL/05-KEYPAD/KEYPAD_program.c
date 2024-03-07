/*
 * KEYPAD_program.c
 *
 * Created: 3/3/2024 7:00:00 PM
 * Author: Tarek Alaa
 */ 
#define F_CPU 8000000
/*include libraries*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*include MCAL*/
#include"DIO_interface.h"

/*include headers*/
#include"KEYPAD_interface.h"
#include"KEYPAD_config.h"

u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};

void KEYPAD_voidInit()
{
	for (u8 i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[i], DIO_PIN_OUTPUT);
	}
	for (u8 i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(keypadConfig.COLSPORT, keypadConfig.COLPINS[i], DIO_PIN_INPUT);
		DIO_voidActivePinPullUpResistance(keypadConfig.COLSPORT, keypadConfig.COLPINS[i]);
	}
}
void KEYPAD_voidGetbutton(u8 *copy_u8press)
{
	*copy_u8press = NOTPRESSED;
	for (u8 row = 0; row < 4; row++) 
	{
		for (u8 i = 0; i < 4; i++) 
		{
			if (row==i)
			{
				DIO_voidSetPinValue(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[i], DIO_PIN_LOW);
			}
			else
			{
				DIO_voidSetPinValue(keypadConfig.ROWS_PORT, keypadConfig.ROWPINS[i], DIO_PIN_HIGH);
			}
		}
		for(u8 col = 0; col < 4; col++)
		{
			u8 pinState=DIO_PIN_HIGH;
			DIO_voidGetPinValue(keypadConfig.COLSPORT, keypadConfig.COLPINS[col], &pinState);
			_delay_ms(20);
			if(pinState == DIO_PIN_LOW) 
			{
				*copy_u8press = arr[row][col];
				break;
			}
		}
	}
}
