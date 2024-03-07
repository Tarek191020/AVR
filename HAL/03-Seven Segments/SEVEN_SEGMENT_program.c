/*
 * SEVENSEGMENT_interface.h
 *
 * Created: 1/3/2024 11:00:00 PM
 * Author: Tarek Alaa
 */ 

#define F_CPU 8000000UL
#include"DIO_interface.h"
#include <util/delay.h>
#include "SEVEN_SEGMENT_interface.h"
#include "SEVEN_SEGMENT_config.h"


void SEVENSEGMENT_voidInit()
{
	switch (SevenSegmentConfig.SEVENSEGMENT_MODE)
	{
		case SEVENSEGMENT_4BINS:
			for (u8 i=0;i<4;i++)
			{
				DIO_voidSetPinDirection(SevenSegmentConfig.SEVENSEGMENT_PORT,SevenSegmentConfig.SEVENSEGMENT_PINS[i],DIO_PIN_OUTPUT);
			}
			break;
		case SEVENSEGMENT_8BINS:
				DIO_voidSetPortDirection(SevenSegmentConfig.SEVENSEGMENT_PORT,DIO_PORT_OUTPUT);
			break;
		default:
			break;
	}
	DIO_voidSetPinValue(DISPLAY1_PORT,DISPLAY1_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DISPLAY2_PORT,DISPLAY2_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DISPLAY3_PORT,DISPLAY3_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DISPLAY4_PORT,DISPLAY4_PIN,DIO_PIN_OUTPUT);
}

void SEVENSEGMENT_voidDisplayNum(u16 copy_u16Number)
{
	u8 thousands = copy_u16Number/1000;
	u8 hundreds = (copy_u16Number / 100)%10;
	u8 tens = (copy_u16Number / 10)%10;
	u8 ones = copy_u16Number % 10;
	SEVENSEGMENT_voidDisplayDigit(ones, DISPLAY4_PORT, DISPLAY4_PIN);
	#if SEVENSEGMENT_MULTIPLEXING ==1
	
	SEVENSEGMENT_voidDisplayDigit(ones, DISPLAY4_PORT, DISPLAY4_PIN);
	//_delay_ms(50);
	SEVENSEGMENT_voidDisplayDigit(tens, DISPLAY3_PORT, DISPLAY3_PIN);
	//_delay_ms(50);
	SEVENSEGMENT_voidDisplayDigit(hundreds, DISPLAY2_PORT, DISPLAY2_PIN);
	//_delay_ms(50);
	SEVENSEGMENT_voidDisplayDigit(thousands, DISPLAY1_PORT, DISPLAY1_PIN);
	//_delay_ms(2);
	#else
	SEVENSEGMENT_voidDisplayDigit(ones, DISPLAY4_PORT, DISPLAY4_PIN);
	#endif
}
void SEVENSEGMENT_voidDisplayDigit(u16 copy_u16Digit, SEVENSEGMENT_DISPLAYPORT_t copy_enumDisplayPort,SEVENSEGMENT_DISPLAYPIN_t copy_enumDisplayPin)
{
	 u8 reminder=0;
	 u8 AnodeNumbers[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	 u8 CathodeNumbers[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	 switch(SevenSegmentConfig.SEVENSEGMENT_MODE)
	 {
		 case SEVENSEGMENT_4BINS:
		 for(u8 i=0;i<4;i++)
		 {
			 reminder=copy_u16Digit%2;
			 if (reminder==0)
			 {
				 DIO_voidSetPinValue(SevenSegmentConfig.SEVENSEGMENT_PORT, SevenSegmentConfig.SEVENSEGMENT_PINS[i], DIO_PIN_LOW);
			 }
			 else
			 {
				 DIO_voidSetPinValue(SevenSegmentConfig.SEVENSEGMENT_PORT, SevenSegmentConfig.SEVENSEGMENT_PINS[i], DIO_PIN_HIGH);
			 }
			 copy_u16Digit/=2;
		 }
		 break;
		 case SEVENSEGMENT_8BINS:
		 switch(SevenSegmentConfig.SEVENSEGMENT_TYPE)
		 {
			 case SEVENSEGMENT_COMMON_ANODE:
			 DIO_voidSetPortValue(SevenSegmentConfig.SEVENSEGMENT_PORT, AnodeNumbers[copy_u16Digit]);
			 break;
			 case SEVENSEGMENT_COMMON_CATHODE:
			 DIO_voidSetPortValue(SevenSegmentConfig.SEVENSEGMENT_PORT, CathodeNumbers[copy_u16Digit]);
			 break;
			 default:
			 break;
		 }
		 break;
		 default:
		 break;
	 }
	 #if SEVENSEGMENT_MULTIPLEXING == 1
	 switch(copy_enumDisplayPort)
	 {
		 case DISPLAY1_PORT:
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY1_PORT,SEVENSEGMENT_DISPLAY1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY2_PORT,SEVENSEGMENT_DISPLAY2_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY3_PORT,SEVENSEGMENT_DISPLAY3_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY4_PORT,SEVENSEGMENT_DISPLAY4_PIN,DIO_PIN_LOW);
			_delay_ms(20);
			break;
		case DISPLAY2_PORT:
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY1_PORT,SEVENSEGMENT_DISPLAY1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY2_PORT,SEVENSEGMENT_DISPLAY2_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY3_PORT,SEVENSEGMENT_DISPLAY3_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY4_PORT,SEVENSEGMENT_DISPLAY4_PIN,DIO_PIN_LOW);
			_delay_ms(20);
			break;
		case DISPLAY3_PORT:
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY1_PORT,SEVENSEGMENT_DISPLAY1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY2_PORT,SEVENSEGMENT_DISPLAY2_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY3_PORT,SEVENSEGMENT_DISPLAY3_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY4_PORT,SEVENSEGMENT_DISPLAY4_PIN,DIO_PIN_LOW);
			_delay_ms(20);
			break;
		case DISPLAY4_PORT:
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY1_PORT,SEVENSEGMENT_DISPLAY1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY2_PORT,SEVENSEGMENT_DISPLAY2_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY3_PORT,SEVENSEGMENT_DISPLAY3_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY4_PORT,SEVENSEGMENT_DISPLAY4_PIN,DIO_PIN_HIGH);
			_delay_ms(20);
			break;
		default:
			break;
	 }
	 #else
	 DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY1_PORT,SEVENSEGMENT_DISPLAY1_PIN,DIO_PIN_LOW);
	 DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY2_PORT,SEVENSEGMENT_DISPLAY2_PIN,DIO_PIN_LOW);
	 DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY3_PORT,SEVENSEGMENT_DISPLAY3_PIN,DIO_PIN_LOW);
	 DIO_voidSetPinValue(SEVENSEGMENT_DISPLAY4_PORT,SEVENSEGMENT_DISPLAY4_PIN,DIO_PIN_HIGH);
	 #endif
}