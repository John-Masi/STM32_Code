#include <cstdint>
#include "../I2C/include/i2c.hpp"
#include "../GPIO/Include/gpio.hpp"
#include "../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef HTU31_HPP
#define HTU31_HPP

#define PIN9 9
#define PIN9MOD_CLR ~(3 << (PIN9 * 2)) 
#define PIN9ALT_SET (2 << (PIN9 * 2))
#define PIN9AF_INDEX (PIN9 - 8)

#define PIN8 8
#define PIN8MOD_CLR ~(3 << (PIN8 * 2)) 
#define PIN8ALT_SET (2 << (PIN8 * 2))
#define PIN8AF_INDEX (PIN8 - 8)


template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
class HTU31 {
    public:
        HTU31() {
            gpio->MODER &= PIN9MOD_CLR;
            gpio->MODER &= PIN8MOD_CLR;

            gpio->MODER |= PIN9ALT_SET;
            gpio->MODER |= PIN8ALT_SET;

            gpio->AFRH &= ~(0xF << (4 * PIN9AF_INDEX));
            gpio->AFRH &= ~(0xF << (4 * PIN8AF_INDEX));

            gpio->AFRH |= (4 << (4 * PIN9AF_INDEX));
            gpio->AFRH |= (4 << (4 * PIN8AF_INDEX));

            gpio->OTYPER |= (1 << PIN8) | (1 << PIN9);
            gpio->PUPDR |= (1 << (PIN8 * 2)) | (1 << (PIN9 * 2));

            i2c->CR1 &= ~(1 << 0);
	        i2c->CR1 = 0;
	        i2c->CR2 = 16;
	        i2c->CCR = 80;
	        i2c->TRISE = 17;
	        i2c->CR1 |= (1 << 0);
        };

        void read_poll(void);
        void write_poll(void);
        uint16_t temp(void);
        uint16_t humid(void);

    private:
        static constexpr auto i2c = reinterpret_cast<I2C_Typedef*>(I2C_ADDR);
        static constexpr auto gpio = reinterpret_cast<GPIO_Typedef*>(GPIO_ADDR);
        uint8_t data[6];

};

#endif 