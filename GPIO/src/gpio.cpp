#include "../Include/gpio.hpp"

void GPIO::gpio_init(void) {
    RCC->AHB1ENR |= (1 << GPIOAEN) | (1 << GPIOCEN);
    GPIOA->MODER |= (2 << (9 * 2));
    GPIOA->AFRL |= (7 << 4);
}

void GPIO::button_init(void) {
    RCC->AHB1ENR |= (1 << GPIOBEN); 
    RCC->AHB1ENR |= (1 << GPIOCEN);
    RCC->APB2ENR |= (1 << SYSCFGEN);

    GPIOC->MODER &= BTTN_PIN;

    for(int i = 0; i < 3; i++) {
        GPIOB->MODER |= (1 << (i * 2));
    }

    SYSCFG->EXTICR4 |= (0x2 << 4);

    EXTI->IMR |= (1 << 13);
    EXTI->FTSR |= (1 << 13);

    NVIC->ISER0[1] |= (1 << 8);
}

// Turn off all gpiob pins
void GPIO::turn_off(void) {
    for(int i = 0; i < 4; i++) {
        GPIOB->ODR &= ~(1 << i);
    }
}

// Turn on all 4 gpiob pins 
void GPIO::turn_on(void) {
    for(int i = 0; i < 4; i++) {
        GPIOB->ODR |= (1 << i);
    }
}

void GPIO::led_on(uint8_t pin) {
    GPIOB->ODR &= (1 << pin);
    GPIOB->ODR |= (1 << pin);
}