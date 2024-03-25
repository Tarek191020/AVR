/*
 * EEPROM_program.c
 *
 * Created: 3/24/2024 11:59:20 AM
 *  Author: Tarek Alaa
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"

void EEPROM_voidInit(void)
{
	I2C_voidInitMaster(0);
}
void EEPROM_voidWriteByte(u16 copy_u16WordAddress, u8 copy_u8Data)
{
	u8 local_u8DeviceAddress = (copy_u16WordAddress>>8) | EEPROM_FIXED_ADDRESS;
	I2C_voidSendStartCondition();
	
	I2C_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
	
	I2C_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
	
	I2C_voidTransmitMasterDataByte(copy_u8Data);
	
	I2C_voidSendStopCondition();
	_delay_ms(5);
}

void EEPROM_voidReadByte(u16 copy_u16WordAddress, u8* copy_pu8Data)
{
	if (copy_pu8Data!=NULL)
	{
		u8 local_u8DeviceAddress = (copy_u16WordAddress>>8) | EEPROM_FIXED_ADDRESS;
		
		I2C_voidSendStartCondition();
		
		I2C_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		
		I2C_voidTransmitMasterDataByte((u8)copy_u16WordAddress);
		
		I2C_voidSendRepeatedStartCondition();
		
		I2C_voidSendSlaveAddWithRead(local_u8DeviceAddress);
		
		I2C_voidReceiveMasterDataByteWithNack(copy_pu8Data);
		
		I2C_voidSendStopCondition();
		_delay_ms(5);
	}
	else
	{	
		//error
	}
	
}

void EEPROM_voidWritePage(u16 copy_u16BaseAddress, u8* copy_pu8Data, u8 copy_u8DataSize)
{
	if ((copy_pu8Data!=NULL)&&(copy_u8DataSize<=16))
	{
		u8 local_u8DeviceAddress = (copy_u16BaseAddress>>8) | EEPROM_FIXED_ADDRESS;
		I2C_voidSendStartCondition();
		I2C_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		
		I2C_voidTransmitMasterDataByte((u8)copy_u16BaseAddress);
		
		for (u8 i=0;i<copy_u8DataSize;i++)
		{
			I2C_voidTransmitMasterDataByte(copy_pu8Data[i]);
		}
		I2C_voidSendStopCondition();
		_delay_ms(5);
	}
	else
	{
		//error
	}
		
}

void EEPROM_voidReadPage(u16 copy_u16BaseAddress, u8 *copy_pu8Data, u8 copy_u8DataSize)
{
	if (copy_pu8Data!=NULL)
	{
		u8 local_u8DeviceAddress = (copy_u16BaseAddress>>8) | EEPROM_FIXED_ADDRESS;
		
		I2C_voidSendStartCondition();
		
		I2C_voidSendSlaveAddWithWrite(local_u8DeviceAddress);
		
		I2C_voidTransmitMasterDataByte((u8)copy_u16BaseAddress);
		
		I2C_voidSendRepeatedStartCondition();
		
		I2C_voidSendSlaveAddWithRead(local_u8DeviceAddress);
		u8 i;
		for (i=0;i<copy_u8DataSize-1;i++)
		{
			I2C_voidReceiveMasterDataByteWithAck(&copy_pu8Data[i]);
		}
		I2C_voidReceiveMasterDataByteWithNack(&copy_pu8Data[i]);
		I2C_voidSendStopCondition();
		_delay_ms(5);
	}
	else
	{
		//error
	}
		
}