#include <cstdint>
#include <array> 
#include "typedef.h"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"
#include "../syscfg-nvic-rcc/include/syscfg.hpp"
#include "../syscfg-nvic-rcc/include/exti.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

class GPIO {
    public:
        GPIO() {
            //gpio_init();
        }
        void gpio_init(void);

        void button_init(void); // Init for cascading-leds

        void turn_off(void);
        void turn_on(void);
        void led_on(uint8_t pin);

    private:

};

#endif 