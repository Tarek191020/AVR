/*
 * I2C_config.h
 *
 * Created: 3/23/2024 8:43:04 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

/*Select SCLOCK Frequency*/
#define SCL_FREQUENCY		400000UL

/*select prescaler*/
I2C_CONFIG_t I2C_Cofig = {
	.PRESCALER = _1_PRESCALER,
	.ACK = I2C_NACK
	};


#endif /* I2C_CONFIG_H_ */