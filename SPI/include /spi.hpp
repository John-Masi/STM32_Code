#include "spi_typedef.hpp"
#include "../../GPIO/Include/gpio_typedef.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef SPI_HPP
#define SPI_HPP

template <uintptr_t ADDR,uintptr_t ADDR2,uint8_t BRVAL>
class SPI {
    public:
	    SPI() {
		    gpio_config();
			RCC->APB2ENR |= (1 << SPI1_EN);
			spi1->CR1 |= (BRVAL << BR);
			spi1->CR1 |= (1 << MSTR);
		}

        uint8_t poll(uint8_t byte) {
			volatile uint8_t read;
			while(!(spi1->SR & (1 << 1)));

			spi1->DR = byte;

			while(!(spi1->SR & (1 << 0)));

			read = spi1->DR;

			return read;

		}

		void gpio_config(void) {
			RCC->AHB1ENR |= (1 << GPIOA_EN);

			gpio->MODER &= ~(3 << (4 * 2));
			gpio->MODER &= ~(3 << (5 * 2));
			gpio->MODER &= ~(3 << (6 * 2));
			gpio->MODER &= ~(3 << (7 * 2));

			gpio->MODER |= (2 << (4 * 2));
			gpio->MODER |= (2 << (5 * 2));
			gpio->MODER |= (2 << (6 * 2));
			gpio->MODER |= (2 << (7 * 2));

			gpio->AFRL &= ~(0xF << (4 * 4));
			gpio->AFRL &= ~(0xF << (5 * 4));
			gpio->AFRL &= ~(0xF << (6 * 4));
			gpio->AFRL &= ~(0xF << (7 * 4));

			gpio->AFRL |= (5 << (4 * 4));
			gpio->AFRL |= (5 << (5 * 4));
			gpio->AFRL |= (5 << (6 * 4));
			gpio->AFRL |= (5 << (7 * 4));
		}

	private:
		inline static auto spi1 = reinterpret_cast<SPI_Typedef*>(ADDR);
		inline static auto gpio = reinterpret_cast<GPIO_Typedef*>(ADDR2);

};

#endif 