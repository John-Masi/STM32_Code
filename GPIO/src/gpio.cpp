#include "../Include/gpio.hpp"

void GPIO<GPIOB>::button_init(void) {
    RCC->AHB1ENR |= (1 << GPIOBEN); 
    RCC->AHB1ENR |= (1 << GPIOCEN);
    RCC->APB2ENR |= (1 << SYSCFGEN);

    GPIOC->MODER &= BTTN_PIN;

    for(int i = 0; i < 3; i++) {
        gpio->MODER |= (1 << (i * 2));
    }

    SYSCFG->EXTICR4 |= (0x2 << 4);

    EXTI->IMR |= (1 << 13);
    EXTI->FTSR |= (1 << 13);

    NVIC->ISER0[1] |= (1 << 8);
}

void GPIO<GPIOB>::turn_off(void) {
    for(int i = 0; i < 4; i++) {
        gpio->ODR &= ~(1 << i);
    }
}

void GPIO<GPIOB>::turn_on(void) {
    for(int i = 0; i < 4; i++) {
        gpio->ODR |= (1 << i);
    }
}
void GPIO<GPIOB>::led_on(uint8_t pin) {
    gpio->ODR &= (1 << pin);
    gpio->ODR |= (1 << pin);
}
