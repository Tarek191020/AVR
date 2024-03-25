/*
 * I2C_config.h
 *
 * Created: 3/23/2024 8:43:04 PM
 *  Author: Tarek Alaa
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

/*select prescaler
1- I2C_1_PRESCALER	
2- I2C_4_PRESCALER	
3- I2C_16_PRESCALER
4- I2C_64_PRESCALER
*/
#define I2C_PRESCALER       I2C_1_PRESCALER
/*Select SCLOCK Frequency*/
#define SCL_FREQUENCY		400000UL


#endif /* I2C_CONFIG_H_ */