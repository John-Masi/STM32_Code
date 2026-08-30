#include "spi_typedef.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"
#include "../../GPIO/Include/gpio_typedef.hpp"

#ifndef SPI_HPP
#define SPI_HPP

template <uintptr_t ADDR,uintptr_t ADDR2,uint8_t BRVAL>
class SPI {
	public:

		SPI() {
			gpio_config();
			spi1->CR1 = 0;
			spi1->CR1 &= ~((1 << 0) | (1 << 1));
			spi1->CR1 &= ~(0x7 << 3);
			spi1->CR1 |= (BRVAL << BR);
			spi1->CR1 |= (1 << MSTR);

			spi1->CR1 |= (1 << 9);
			spi1->CR1 |= (1 << 8);
			spi1->CR1 &= ~(1 << 11);

			spi1->CR1 |= (1 << 6);
		}

		void write(uint8_t byte,uint8_t val) {
			gpio->BSSR |= (1 << (4 + 16));

			while(!(spi1->SR & (1 << 1)));

			spi1->DR = (byte << 1) & 0x7E;

			while(!(spi1->SR & (1 << 0)));
			(void)spi1->DR;

			while(!(spi1->SR & (1 << 1)));
			spi1->DR = val;
			while(!(spi1->SR & (1 << 0)));
			(void)spi1->DR;
			while (spi1->SR & (1 << 7));
			gpio->BSSR |= (1 << 4);

		}

		uint8_t read(uint8_t byte) {
			uint8_t val;

			gpio->BSSR |= (1 << (4 + 16));

			while(!(spi1->SR & (1 << 1)));
			spi1->DR = ((byte << 1) & 0x7E) | 0x80;
			while(!(spi1->SR & (1 << 0)));
			(void)spi1->DR;

			while(!(spi1->SR & (1 << 1)));
			spi1->DR = 0x00;
			while(!(spi1->SR & (1 << 0)));
			val = spi1->DR;
			while (spi1->SR & (1 << 7));
			gpio->BSSR |= (1 << 4);
			return val;
		}

		void led_on(void) {
			gpio->ODR |= (1 << 9);
		}

		void led_off(void) {
			gpio->ODR &= ~(1 << 9);
		}


		void gpio_config(void) {
			RCC->AHB1ENR |= (1 << 2);
			RCC->AHB1ENR |= (1 << GPIOA_EN);
			RCC->APB2ENR |= (1 << SPI1_EN);


			gpio->MODER &= ~(3 << (4 * 2));
			gpio->MODER &= ~(3 << (5 * 2));
			gpio->MODER &= ~(3 << (6 * 2));
			gpio->MODER &= ~(3 << (7 * 2));
			gpio->MODER &= ~(3 << (9 * 2));

			gpio->MODER |= (1 << (4 * 2));
			gpio->MODER |= (1 << (9 * 2));
			gpio->MODER |= (2 << (5 * 2));
			gpio->MODER |= (2 << (6 * 2));
			gpio->MODER |= (2 << (7 * 2));

			gpio->AFRL &= ~(0xF << (5 * 4));
			gpio->AFRL &= ~(0xF << (6 * 4));
			gpio->AFRL &= ~(0xF << (7 * 4));

			gpio->AFRL |= (5 << (5 * 4));
			gpio->AFRL |= (5 << (6 * 4));
			gpio->AFRL |= (5 << (7 * 4));
			gpio->BSSR = (1 << 4);
		}

	private:
		SPI_Typedef* spi1 = reinterpret_cast<SPI_Typedef*>(ADDR);
		GPIO_Typedef* gpio = reinterpret_cast<GPIO_Typedef*>(ADDR2);
		inline static auto gpioc = reinterpret_cast<GPIO_Typedef*>(0x40020800);
};


#endif