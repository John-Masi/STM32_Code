#ifndef LEDS_HPP
#define LEDS_HPP

#include <cstdint>
#include <array> 
#include "gpio_typedef.hpp"
#include "gpio.hpp"
#include "../../PIN/include/pin.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"
#include "../../syscfg-nvic-rcc/include/nvic.hpp"
#include "../../syscfg-nvic-rcc/include/syscfg.hpp"
#include "../../syscfg-nvic-rcc/include/exti.hpp"


template <uintptr_t ADDR1,uintptr_t ADDR2,uint8_t PINTAMT>
class LEDS{    
    public:

        LEDS() {
            initalize_pins();
            button_init();
        }

        void button_init(void) {
            RCC->APB2ENR |= (1 << SYSCFGEN);

            gpiob.set_mode(bttn_pin);

            SYSCFG->EXTICR4 |= (0x2 << 4);

            EXTI->IMR |= (1 << 13);
            EXTI->FTSR |= (1 << 13);

            NVIC->ISER0[1] |= (1 << 8);
        }

        void initalize_pins(uint8_t num1,uint8_t num2, uint8_t num3,uint8_t num4) {
            for(volatile int i = 0; i < PINTAMT; i++) {
                led_pins[i] = Pin(i,INPUT);
            }
        }

        void all_off(void) {
            for(volatile int i = 0; i < PINTAMT; i++) {
                gpioa.output_off(led_pins[i]);
            }
        }

        void all_on(void) {
            for(volatile int i = 0; i < PINTAMT; i++) {
                gpioa.output_on(led_pins[i]);
            }
        }

        void led_on(uint8_t pinNum) {
            gpioa.output_on(led_pins[pinNum]);
        }

        void led_off(uint8_t pinNum) {
            gpioa.output_off(led_pins[pinNum]);
        }

    private:
         GPIO<ADDR1,0> gpioa;
         GPIO<ADDR2,2> gpiob;
         Pin led_pins[PINTAMT];
         Pin bttn_pin(13,Mode::INPUT);
};

#endif 
