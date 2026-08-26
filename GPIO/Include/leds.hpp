#include <cstdint>
#include <array> 
#include "gpio_typedef.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"
#include "../../syscfg-nvic-rcc/include/nvic.hpp"
#include "../../syscfg-nvic-rcc/include/syscfg.hpp"
#include "../../syscfg-nvic-rcc/include/exti.hpp"

#ifndef LEDS_HPP
#define LEDS_HPP

template <uintptr_t ADDR1,uintptr_t ADDR2>
class LEDS{    
    public:
        void button_init(void); // Init for cascading-leds
        void turn_off(void);
        void turn_on(void);
        void led_on(uint8_t pin);
        void led_off(uint8_t pin);

    private:
         inline static auto gpio_b = reinterpret_cast<GPIO_Typedef*>(ADDR1);
         inline static auto gpio_c = reinterpret_cast<GPIO_Typedef*>(ADDR2);
};

#endif 
