#include <cstdint>
#include "../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

struct GPIO_Typedef {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t r[4];
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t r1[2];
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