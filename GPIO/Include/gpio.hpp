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
            RCC->AHB1ENR |= (1 << RCC_POS);
        };

        template<typename... Pins>
        inline void output_on(void) {
        	constexpr uint32_t mask = ((1U << Pins::num) | ...);
        	gpio->ODR = mask;
        }

        template<typename... Pins>
        void output_off() {
        	constexpr uint32_t mask = (~(1U << Pins::num) & ...);
        	gpio->ODR = mask;
        };

       template<typename... Pins>
       void output_toggle(void) {
    	   constexpr uint32_t mask = ((1U << Pins::num) | ...);
    	   gpio->ODR ^= mask;
       }

        template<typename pin>
        void open_drain() const {
            gpio->OTYPER |= (1U << pin::num);
        };

        template<typename pin>
        void pullup_en() const {
            gpio->PUPDR |= (0b01 << pin::MODERMSK);
        };

        template<typename pin>
        void set_mode(void) {
            gpio->MODER &= ~(3 << pin::MODERMSK);
            gpio->MODER |= (static_cast<uint8_t>(pin::moder) << pin::MODERMSK);

            if constexpr(pin::moder == Mode::ALTERNATE) {
                if constexpr(pin::num <= 6) {
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
        GPIO_Typedef* gpio = reinterpret_cast<GPIO_Typedef*>(ADDR);
};

#endif