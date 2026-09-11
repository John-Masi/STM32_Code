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
            RCC->AHB1ENR |= (1U << RCC_POS);
        };

        template<typename... Pins>
        void output_on(void) const {
            gpio->BSSR = (Pins::num | ...);
        }

        template<typename pin>
        void output_off(void) const {
            gpio->ODR &= ~(1U << pin::num);
        };

        template<typename pin>
        void open_drain(void) const {
            gpio->OTYPER |= (1U << pin::num);
        };

        template<typename pin>
        void pullup_en(void) const {
            gpio->PUPDR |= (0b01 << pin::MODERMSK);
        };

        template<typename pin>
        static void set_mode() {
            gpio->MODER &= (3U << pin::MODERMSK)
            gpio->MODER |= (pin::mode << pin::MODERMSK);

            if constexpr(pin::mode == Mode::ALTERNATE) {
                if constexpr (pin::num <= 6) {
                    // AFRL 
                    gpio->AFRL &= ~(0xFU << pin::AFRMSK);
                    gpio->AFRL |= (pin::AF << pin::AFRMSK);
                }
                else {
                    gpio->AFRH &= ~(0xFU << pin::AFRMSK);
                    gpio->AFRH |= (pin::AF << pin::AFRMSK);
                }
            }
        };


    private:
        inline static auto gpio = reinterpret_cast<GPIO_Typedef*>(ADDR);
};

#endif 