/*
 * I2C_interface.h
 *
 * Created: 3/23/2024 12:59:09 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


typedef enum
{
	_1_PRESCALER,
	_4_PRESCALER,
	_16_PRESCALER,
	_64_PRESCALER,
}I2C_PRESCALER_t;

typedef enum
{
	I2C_NACK,
	I2C_ACK
}I2C_ACK_t;

typedef struct  
{
	I2C_PRESCALER_t PRESCALER;
	I2C_ACK_t		ACK;
}I2C_CONFIG_t;

/* Initialize I2C module as master */
void I2C_voidMastrInit(u8 copy_u8Address);

/* Initialize I2C module as slave */
void I2C_voidSlaveInit(u8 copy_u8Address);

/* Generate start condition */
void I2C_voidStartCondition(void);

/* Generate stop condition */
void I2C_voidStopCondition(void);

/* Send address for write operation */
void I2C_voidSendAddressWrite(u8 copy_u8Address);

/* Send address for read operation */
void I2C_voidSendAddressRead(u8 copy_u8Address);

/* Send data byte */
void I2C_voidSendData(u8 copy_u8Byte);

/* Receive data byte */
void I2C_voidReceiveData(u8* copy_pu8Byte);

/* Get status of I2C communication */
void I2C_voidGetStatus(u8* copy_pu8Status);

/* Generate repeated start condition */
void I2C_voidRepeatedStartCondition(void);


#endif /* I2C_INTERFACE_H_ */