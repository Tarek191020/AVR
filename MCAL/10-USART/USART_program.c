/*
 * USART_program.c
 *
 * Created: 3/22/2024 10:42:46 AM
 *  Author: Tarek Alaa
 */ 

#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"

volatile u8 TX_Buffer[TX_BUFFER_SIZE];
volatile u8 TX_index = 0;

volatile u8 RX_Buffer[RX_BUFFER_SIZE];
volatile u8 RX_index = 0;

static BOOL MSG_received=FALSE;

void USART_voidInit(u16 copy_u16BaudRate)
{
	/* Set baud rate */
	UBRRH_REG = (u8)(copy_u16BaudRate>>8);
	UBRRL_REG = (u8)copy_u16BaudRate;
	
	/* Enable receiver and transmitter */
	UCSRB_REG = (1<<RXEN)|(1<<TXEN);
	
	/* Set frame format: 8data, 1stop bit */
	UCSRC_REG = (1<<URSEL) | USART_DATA_BITS_NUM;
	
	// Enable transmit complete interrupt
	SET_BIT(UCSRB_REG, TXCIE);
	
	// Enable receive complete interrupt
	SET_BIT(UCSRB_REG, RXCIE);
}
void USART_voidTransmitData(u8 copy_u8TXData)
{
	/* Wait for empty transmit buffer */
	while (!GET_BIT(UCSRA_REG, UDRE));
	
	/* Put data into buffer, sends the data */
	UDR_REG = copy_u8TXData;
}
void USART_voidReceiveData(u8 *copy_pu8RXData)
{
	/* Wait for data to be received */
	while (!GET_BIT(UCSRA_REG, RXC));
	
	/* Get and return received data from buffer */
	*copy_pu8RXData = UDR_REG;
}
void USART_voidTransmitData_ASYNC(u8 copy_u8TXData)
{
	UDR_REG = copy_u8TXData;
}
void USART_voidReceiveData_ASYNC(u8 *copy_pu8RXData)
{
	*copy_pu8RXData = UDR_REG;
}


void USART_voidTransmitString_ASYNC(u8 *copy_pu8TXString)
{
	// Copy the string to the TX buffer
	for (u8 i=0;copy_pu8TXString[i]!='\0';i++)
	{
		TX_Buffer[i]=copy_pu8TXString[i];
	}
	
	// Start transmission by triggering the interrupt
	USART_voidTransmitData_ASYNC(copy_pu8TXString[0]);
}

BOOL USART_isMSG_Received(void)
{
	if (MSG_received==TRUE)
	{
		MSG_received=FALSE;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
u8* USART_pu8ReceiveString_ASYNC(void)
{
	 return (&RX_Buffer);
}
ISR(USART_TXC_vect)
{
	TX_index++;
	if (TX_Buffer[TX_index]!='\0')
	{
		USART_voidTransmitData_ASYNC(TX_Buffer[TX_index]);
	}
	else
	{
		// Reset TX index when transmission is complete
		TX_index=0;
		//stop
	}
}

ISR(USART_RXC_vect)
{
	USART_voidReceiveData_ASYNC(&RX_Buffer[RX_index]);
	if (RX_Buffer[RX_index]=='\r')
	{
		RX_Buffer[RX_index]='\0';
		RX_index=0;
		MSG_received=TRUE;
	}
	else
	{
		RX_index++;
	}
}