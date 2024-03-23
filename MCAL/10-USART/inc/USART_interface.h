/*
 * USART_interface.h
 *
 * Created: 3/22/2024 10:43:04 AM
 *  Author: Tarek Alaa
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "USART_config.h"


void USART_voidInit(u16 copy_u16BaudRate);
void USART_voidTransmitData(u8 copy_u8TXData);
void USART_voidReceiveData(u8 *copy_pu8RXData);
void USART_voidTransmitData_ASYNC(u8 copy_u8TXData);
void USART_voidReceiveData_ASYNC(u8 *copy_pu8RXData);
BOOL USART_isMSG_Received(void);
u8* USART_pu8ReceiveString_ASYNC(void);
void USART_voidTransmitString_ASYNC(u8 *copy_pu8TXString);



#endif /* USART_INTERFACE_H_ */