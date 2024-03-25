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

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_register.h"
#include "I2C_config.h"


void I2C_voidInitMaster(u8 copy_u8MasterAddress)
{
	/* Configure I2C clock prescaler */
	TWSR_REG = I2C_PRESCALER;
	
	/* Calculate and set TWBR register value */
	TWBR_REG = (F_CPU - (16*SCL_FREQUENCY)) / (2 * SCL_FREQUENCY * (1 << (2 * I2C_PRESCALER)));
	
	// Set Prescaller = 1 >> Set Freq. = 400KHZ
	//TWBR_REG = 12;
	
	// Enable TWI Peripheral
	SET_BIT(TWCR_REG, TWCR_TWEN);
	
	/*set master address*/
	TWAR_REG |=(copy_u8MasterAddress<<1);
}


void I2C_voidSendStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWCR_TWSTA);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
	
	// Check ACK = SC ACK
	while(I2C_STATUS_VALUE != I2C_START_CONDITION_ACK);
}


void I2C_voidSendRepeatedStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWCR_TWSTA);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
	
	// Check ACK = Repeated SC ACK
	while(I2C_STATUS_VALUE != I2C_REP_START_CONDITION_ACK);
}


void I2C_voidSendStopCondition(void)
{
	// Request Stop Condition
	SET_BIT(TWCR_REG, TWCR_TWSTO);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);
}


void I2C_voidSendSlaveAddWithWrite(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd<128)
	{
		TWDR_REG = (copy_u8SlaveAdd<<1);
		
		// Select write operation
		CLR_BIT(TWDR_REG, 0);
		
		// Clear start condition bit
		CLR_BIT(TWCR_REG, TWCR_TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWCR_TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
		
		// Check ACK = Master transmit ( slave address + Write request )
		while(I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_WRITE_ACK);
	}
	else
	{
		// return Error State
	}
}


void I2C_voidSendSlaveAddWithRead(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd<128)
	{
		TWDR_REG = (copy_u8SlaveAdd<<1);
		
		// Select read operation
		SET_BIT(TWDR_REG, 0);
		
		// Clear start condition bit
		CLR_BIT(TWCR_REG, TWCR_TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWCR_TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
		
		// Check ACK = Master transmit ( slave address + read request )
		while(I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_READ_ACK);
	}
	else
	{
		// return Error State
	}
}


void I2C_voidTransmitMasterDataByte(u8 copy_u8TxData)
{
	// Write Data into data register
	TWDR_REG = copy_u8TxData;
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
	
	// Check ACK = Master transmit data ACK
	while(I2C_STATUS_VALUE != I2C_MASTER_DATA_TRANSMIT_ACK);
}


void I2C_voidReceiveMasterDataByteWithAck(u8* copy_pu8RxData)
{
	if(copy_pu8RxData!=NULL)
	{
		// Enable ACK
		SET_BIT(TWCR_REG, TWCR_TWEA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWCR_TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
		
		// Check ACK = Master received data with ACK
		while(I2C_STATUS_VALUE != I2C_MASTER_DATA_RECIEVE_ACK);
		
		*copy_pu8RxData = TWDR_REG;
		
		// Disable ACK
		CLR_BIT(TWCR_REG, TWCR_TWEA);
	}
	else
	{
		// return Error State
	}
}


void I2C_voidReceiveMasterDataByteWithNack(u8* copy_pu8RxData)
{
	if(copy_pu8RxData!=NULL)
	{
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWCR_TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWCR_TWINT));
		
		// Check ACK = Master received data with NACK
		while(I2C_STATUS_VALUE != I2C_MASTER_DATA_RECIEVE_NACK);
		
		*copy_pu8RxData = TWDR_REG;
	}
	else
	{
		// return Error State
	}
}

void I2C_voidInitSlave(u8 copy_u8SlaveAddress)
{
	// Set the slave address
	TWAR_REG = (copy_u8SlaveAddress << 1);

	// Enable TWI Peripheral
	SET_BIT(TWCR_REG, TWCR_TWEN);
}
void I2C_voidTransmitSlaveDataByte(u8  copy_u8TxData)
{
	// Wait until address received with read request
	while (I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_RECEIVE_READ);
	
	// Load data into the data register
	TWDR_REG = copy_u8TxData;

	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Busy wait for the flag
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT));

	// Check ACK = Slave transmit data ACK
	while (I2C_STATUS_VALUE != I2C_SLAVE_DATA_TRANSMIT_ACK);
}
void I2C_voidReceiveSlaveDataByteWithAck  (u8* copy_pu8RxData)
{
	// Wait until address received with write request
	while (I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_RECEIVE_WRITE);
	
	// Enable ACK
	SET_BIT(TWCR_REG, TWCR_TWEA);

	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Busy wait for the flag
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT));

	// Check ACK = Slave received data with ACK
	while (I2C_STATUS_VALUE != I2C_SLAVE_DATA_RECEIVE_ACK);

	// Read received data from TWI register
	*copy_pu8RxData = TWDR_REG;

	// Disable ACK
	CLR_BIT(TWCR_REG, TWCR_TWEA);
}
void I2C_voidReceiveSlaveDataByteWithNack (u8* copy_pu8RxData)
{
	// Wait until address received with write request
	while (I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_RECEIVE_WRITE);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	// Busy wait for the flag
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT));

	// Check ACK = Slave received data with NACK
	while (I2C_STATUS_VALUE != I2C_SLAVE_DATA_RECEIVE_NACK);

	// Read received data from TWI register
	*copy_pu8RxData = TWDR_REG;
}