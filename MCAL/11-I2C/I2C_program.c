/*
 * I2C_program.c
 *
 * Created: 3/23/2024 12:59:57 PM
 *  Author: Tarek Alaa
 */ 

#define F_CPU 16000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_register.h"
#include "I2C_config.h"
#include "I2C_private.h"

void I2C_voidMastrInit(u8 copy_u8Address)
{
	/* Configure I2C clock prescaler */
	TWSR_REG |= I2C_Cofig.PRESCALER;
	
	/* Calculate and set TWBR register value */
	TWBR_REG = (F_CPU - (16*SCL_FREQUENCY)) / (2 * SCL_FREQUENCY * (1 << (2 * I2C_Cofig.PRESCALER)));
	
	/*set master address*/
	TWAR_REG |=(copy_u8Address<<1);
}

void I2C_voidSlaveInit(u8 copy_u8Address)
{
	/*set slave address*/
	TWAR_REG |=(copy_u8Address<<1) ;
}

void I2C_voidStartCondition(void)
{
	/* Generate start condition */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN) | (I2C_Cofig.ACK<<TWCR_TWEA);
	
	// Wait until TWINT flag is set indicating the start condition has been transmitted
	while (!(TWCR_REG & (1<<TWCR_TWINT)));
}

void I2C_voidStopCondition(void)
{
	/* Generate stop condition */
	TWCR_REG = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
}

void I2C_voidSendAddressWrite(u8 copy_u8Address)
{
	/* Load address into TWI register */
	TWDR_REG = copy_u8Address<<1;
	
	/* Clear TWINT bit to start transmission of address */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (I2C_Cofig.ACK<<TWCR_TWEA);
	
	/* Wait until transmission is complete */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));
}

void I2C_voidSendAddressRead(u8 copy_u8Address)
{
	/* Load address into TWI register with read bit set */
	TWDR_REG = (copy_u8Address<<1) | 0x01;
	
	/* Clear TWINT bit to start transmission of address */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (I2C_Cofig.ACK<<TWCR_TWEA);
	
	/* Wait until transmission is complete */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));
}

void I2C_voidSendData(u8 copy_u8Byte)
{
	/* Load data into TWI register */
	TWDR_REG = copy_u8Byte;
	
	/* Clear TWINT bit to start transmission of data */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	
	/* Wait until transmission is complete */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));
}

void I2C_voidReceiveData(u8* copy_pu8Byte)
{
	/* Clear TWINT bit to start receiving data */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (I2C_Cofig.ACK<<TWCR_TWEA);
	
	/* Wait until data is received */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));
	
	/* Read received data from TWI register */
	*copy_pu8Byte = TWDR_REG;
}

void I2C_voidGetStatus(u8* copy_pu8Status)
{
	/* Read status register */
	*copy_pu8Status = (TWSR_REG & 0xF8);
}

void I2C_voidRepeatedStartCondition(void)
{
	/* Generate repeated start condition */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN) | (I2C_Cofig.ACK<<TWCR_TWEA);
	
	// Wait until TWINT flag is set indicating the repeated start condition has been transmitted
	while (!(TWCR_REG & (1<<TWCR_TWINT)));
}