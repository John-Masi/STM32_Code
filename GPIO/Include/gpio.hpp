#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>
#include "gpio_typedef.hpp"
#include "../../PIN/include/pin.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"


template<uintptr_t ADDR,uint8_t RCC_POS>
class GPIO {
    public:
        GPIO() {
            // All gpio ports are default AHB1ENR on target mmcu 
            RCC->AHB1ENR |= (1 << RCC_POS);
        };
        void output_on(const Pin& pin) const {
            gpio->ODR |= (1 << pin.num);
        }

        void output_off(const Pin& pin) const {
            gpio->ODR &= ~(1 << pin.num);
        };

        void open_drain(const Pin& pin) const {
            gpio->OTYPER |= (1 << pin.num);
        };

        void pullup_en(const Pin& pin) const {
            gpio->PUPDR |= (0b01 << pin.MODERMSK);
        };

        void set_mode(const Pin& pin) {
            gpio->MODER &= (3 << pin.MODERMSK)
            gpio->MODER |= (pin.mode << pin.MODERMSK);

            if constexpr(pin.mode == Mode::ALTERNATE) {
                if(pin.num >= 0 && pin.num <= 6) {
                    // AFRL 
                    gpio->AFRL &= ~(0xF << pin.AFRMSK);
                    gpio->AFRL |= (pin.AF << pin.AFRMSK);
                }
                else if(pin.num >= 7 && pin.num <= 15) {
                    gpio->AFRH &= ~(0xF << pin.AFRMSK);
                    gpio->AFRH |= (pin.AF << pin.AFRMSK);
                }
            }
        };


    private:
        inline static auto gpio = reinterpret_cast<GPIO_Typedef*>(ADDR);
};

#endif 