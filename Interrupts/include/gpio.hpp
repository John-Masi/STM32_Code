#include <cstdint>
#include "rcc.hpp"

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
};

#define GPIOA ((GPIO_Typedef *)0x40020000)
#define GPIOC ((GPIO_Typedef *)0x40020800)

class GPIO {
    public:
        GPIO(GPIO_Typedef* gpio) {
            gpio_init(gpio);
        }
        void gpio_init(GPIO_Typedef* gpio);
        void set(void);
        void clear(void);
        void toggle(void);

    private:

};

#endif 