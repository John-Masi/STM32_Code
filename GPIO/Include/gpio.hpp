#include <cstdint>
#include <array> 
#include "gpio_typedef.hpp"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"
#include "../syscfg-nvic-rcc/include/syscfg.hpp"
#include "../syscfg-nvic-rcc/include/exti.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

template<uintptr_t BASE>
class GPIO {
    public:
        GPIO() = default;
    private:
        static constepxr auto gpio = reinterpret_cast<GPIO_Typedef*>(BASE);
};

// 
class GPIO<GPIOB> {    
    public:
        void button_init(void); // Init for cascading-leds
        void turn_off(void);
        void turn_on(void);
        void led_on(uint8_t pin);

    private:
         GPIO_Typedef* gpio = reinterpret_cast<GPIO_Typedef*>(GPIOB);
};

#endif 
