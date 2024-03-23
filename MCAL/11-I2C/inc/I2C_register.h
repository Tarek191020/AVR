/*
 * I2C_register.h
 *
 * Created: 3/23/2024 12:59:24 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

//I2C Bit Rate Register–TWBR
#define TWBR_REG	(*(volatile u8*)(0x20))

//I2C Status Register
#define TWSR_REG	(*(volatile u8*)(0x21))
#define	TWSR_TWPS0	0
#define	TWSR_TWPS1	1

//I2C (Slave) Address
#define TWAR_REG	(*(volatile u8*)(0x22))
#define TWAR_TWGCE	0

//I2C Data Register
#define TWDR_REG	(*(volatile u8*)(0x23))

//I2C Control Register
#define TWCR_REG	(*(volatile u8*)(0x56))
#define TWCR_TWIE	0
#define TWCR_TWEN	2
#define TWCR_TWWC	3
#define TWCR_TWSTO	4
#define TWCR_TWSTA	5
#define TWCR_TWEA	6
#define TWCR_TWINT	7








#endif /* I2C_REGISTER_H_ */