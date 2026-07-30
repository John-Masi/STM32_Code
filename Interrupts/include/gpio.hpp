#include <cstdint>
#include <array>
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
        GPIO(GPIO_Typedef* gp) {
            set_gpio(gp);
            gpio_init();
        }
        void gpio_init(void);
        void set_gpio(GPIO_Typedef* gpio);
        void set_pin(uint8_t pin);
        void clear_pin(uint8_t pin);
        void toggle_pin(uint8_t pin);

    private:    
        mutable GPIO_Typedef* gpio{nullptr};
};

#endif 