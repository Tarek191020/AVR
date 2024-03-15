/*
 * SPI_interface.h
 *
 * Created: 3/5/2024 11:36:06 AM
 *  Author: Tarek Alaa
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_registers.h"

typedef enum
{
	SPI_MASTER,
	SPI_SLAVE
} SPI_MODE_t;



void SPI_voidInit(SPI_MODE_t copy_enumSpiType);
void SPI_voidTransieve(u8 copy_u8TxData, u8* copy_pu8RxData);
void SPI_voidTransieveWithInterrupt(u8 copy_u8TxData, void(*copy_pvoidAction)(u8));

#endif /* SPI_INTERFACE_H_ */