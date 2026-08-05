#include <cstdint>
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"
#include "../syscfg-nvic-rcc/include/syscfg.hpp"
#include "../syscfg-nvic-rcc/include/exti.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

struct GPIO_Typedef {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR_A;
    volatile uint32_t PUPDR_B;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
};

#define GPIOA ((GPIO_Typedef *)0x40020200)
#define GPIOB ((GPIO_Typedef *)0X40020400)
#define GPIOC ((GPIO_Typedef *)0X40020800)

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define SYSCFGEN 14
#define BTTN_PIN ~(3 << (13 * 2))

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