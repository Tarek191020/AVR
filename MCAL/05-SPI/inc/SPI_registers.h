/*
 * SPI_registers.h
 *
 * Created: 3/5/2024 11:36:46 AM
 *  Author: Tarek Alaa
 */ 


#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

typedef struct
{
	u8 SPCR_REG;
	u8 SPSR_REG;
	u8 SPDR_REG;
}SPI;

#define SPI_REGS  (( volatile SPI *)0x2D) 
/*
SPI_REGS->SPDR_REG
*/

//pins of SPI control register 
#define SPR0        0
#define SPR1        1
#define CPHA        2
#define CPOL        3
#define MSTR        4
#define DORD        5
#define SPE         6
#define SPIE        7

//pins of SPI status register
#define SPI2X       0
#define WCOL        6
#define SPIF        7


#endif /* SPI_REGISTERS_H_ */