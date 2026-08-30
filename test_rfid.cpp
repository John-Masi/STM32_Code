#include "SPI/Include/spi.hpp"

void delay(uint32_t x) {
	for(volatile uint32_t i = 0; i < x; i++);
}

int main(void) {
	SPI<SPI1,GPIOA,0b111> spi;
	while(1) {

		volatile uint8_t testRead = spi.read(0x14);
		spi.write(0x14, testRead | 0x03);

		delay(150000);
	}
}
