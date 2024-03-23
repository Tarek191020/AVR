/*
 * USART_private.h
 *
 * Created: 3/23/2024 1:04:33 AM
 *  Author: Tarek Alaa
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define USART_BAUDRATE_1200			(0x340)
#define USART_BAUDRATE_2400			(0x1A0)
#define USART_BAUDRATE_4800			(0xCF)
#define USART_BAUDRATE_9600			(0x67)
#define USART_BAUDRATE_19200		(0x51)
#define USART_BAUDRATE_115200		(0x8)


#define USART_5_BIT_DATA			(0<<UCSZ0)
#define USART_6_BIT_DATA			(1<<UCSZ0)
#define USART_7_BIT_DATA			(2<<UCSZ0)
#define USART_8_BIT_DATA			(3<<UCSZ0)

#define USART_1_STOP_BIT			(0<<USBS)
#define USART_2_STOP_BIT			(1<<USBS)

#define USART_EVEN_PARITY			(2<<UPM0)
#define USART_ODD_PARITY			(3<<UPM0)



#endif /* USART_PRIVATE_H_ */