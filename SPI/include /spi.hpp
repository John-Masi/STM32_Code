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
            spi1->CR1 |= (1 << SPIEN);
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

            // Turning on AF for PA4-PA7 
            for(int i = 4; i <= 7; i++) {
                gpio->MODER &= ~(3 << (i * 2));
                gpio->MODER |= (2 << (i * 2));
                gpio->AFRL &= ~(0xF << (i * 4));
                gpio->AFRL |= (5 << (i * 4));
            }
		}

	private:
		inline static auto spi1 = reinterpret_cast<SPI_Typedef*>(ADDR);
		inline static auto gpio = reinterpret_cast<GPIO_Typedef*>(ADDR2);

};

#endif 