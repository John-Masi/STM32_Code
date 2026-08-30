#include <cstdint>

#ifndef SPI_TYPEDEF_HPP
#define SPI_TYPEDEF_HPP

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

#define BR 3
#define MSTR 2

#endif
