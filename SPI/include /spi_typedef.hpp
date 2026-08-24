#include <cstdint>

#ifndef SPI_HPP
#define SPI_HPP

struct SPI_Typedef {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
};

#define SPI1 0x40013000


#define SPI1_EN 12
#define SPI2_EN 14

// Macros for register values
#define BR 3
#define MSTR 2
#define SPIEN 6 

#endif 