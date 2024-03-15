/*
 * SPI_program.c
 *
 * Created: 3/5/2024 11:39:23 AM
 *  Author: Tarek Alaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_registers.h"

static void (*SPI_pvoidAction)(u8);

void SPI_voidInit(SPI_MODE_t copy_enumSpiType)
{
	/* Set data order to be LSB first */
	SET_BIT(SPI_REGS->SPCR_REG, DORD);
	/* Set clock polarity and phase */
	SET_BIT(SPI_REGS->SPCR_REG, CPOL);
	SET_BIT(SPI_REGS->SPCR_REG, CPHA);

	switch(copy_enumSpiType)
	{
		case SPI_MASTER:
			/* Set SPI to master mode */
			SET_BIT(SPI_REGS->SPCR_REG, MSTR);
			/* Set clock rate fosc/128 */
			CLR_BIT(SPI_REGS->SPCR_REG, SPR0);
			SET_BIT(SPI_REGS->SPCR_REG, SPR1);
			CLR_BIT(SPI_REGS->SPSR_REG, SPI2X);
			break;
		case SPI_SLAVE:
			/* Set SPI to slave mode */
			CLR_BIT(SPI_REGS->SPCR_REG, MSTR);
			break;
	}

	/* Enable SPI */
	SET_BIT(SPI_REGS->SPCR_REG, SPE);
}

void SPI_voidTransieve(u8 copy_u8TxData, u8* copy_pu8RxData)
{
	if (copy_pu8RxData != '\0')
	{
		/* Send data */
		SPI_REGS->SPDR_REG = copy_u8TxData;
		/* Wait for transmission to complete */
		while(GET_BIT(SPI_REGS->SPSR_REG, SPIF) == 0);
		/* Read received data */
		*copy_pu8RxData = SPI_REGS->SPDR_REG;
	}
}

void SPI_voidTransieveWithInterrupt(u8 copy_u8TxData, void(*copy_pvoidAction)(u8))
{
	/* Enable SPI interrupt */
	SET_BIT(SPI_REGS->SPCR_REG, SPIE);
	/* Set the callback function */
	SPI_pvoidAction = copy_pvoidAction;
	/* Send data */
	SPI_REGS->SPDR_REG = copy_u8TxData;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	/* Call the callback function with received data */
	SPI_pvoidAction(SPI_REGS->SPDR_REG);
}

