#include <cstdint>
#include "../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

struct GPIO_Typedef {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR_A;
    volatile uint32_t PUPDR_B;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
};

#define GPIOA ((GPIO_Typedef *)0x40020200)
#define GPIOAEN 0

class GPIO {
    public:
        GPIO() {
            gpio_init();
        }
        void gpio_init(void);

    private:

};

#endif 