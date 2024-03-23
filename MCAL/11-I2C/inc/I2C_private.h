/*
 * I2C_private.h
 *
 * Created: 3/23/2024 8:43:22 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define I2C_START					0x08
#define I2C_REPEATED_START			0x10
#define I2C_ARBITRATION				0x38

/*Status Codes for Master Transmitter Mode*/
#define I2C_SLA_W_ACK				0x18
#define I2C__SLA_W_NACK				0x20
#define I2C_DATA_TRANS_ACK			0x28
#define I2C_DATA_TRANS_NACK			0x30
#define I2C_ARBITRATION				0x38



/*Status Codes for Master Receiver Mode*/
#define I2C_SLA_R_ACK				0x40
#define I2C__SLA_R_NACK				0x48
#define I2C_DATA_RECEIVE_ACK		0x50
#define I2C_DATA_RECEIVE_NACK		0x58



#endif /* I2C_PRIVATE_H_ */