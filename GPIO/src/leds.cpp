#include "../Include/leds.hpp"

template <uintptr_t ADDR1,uintptr_t ADDR2>
void LEDS<ADDR1,ADDR2>::button_init(void) {
    RCC->AHB1ENR |= (1 << GPIOBEN); 
    RCC->AHB1ENR |= (1 << GPIOCEN);
    RCC->APB2ENR |= (1 << SYSCFGEN);

    gpio_c->MODER &= BTTN_PIN;

    for(int i = 0; i < 3; i++) {
        gpio_b->MODER |= (1 << (i * 2));
    }

    SYSCFG->EXTICR4 |= (0x2 << 4);

    EXTI->IMR |= (1 << 13);
    EXTI->FTSR |= (1 << 13);

    NVIC->ISER0[1] |= (1 << 8);
}

template <uintptr_t ADDR1,uintptr_t ADDR2>
void LEDS<ADDR1,ADDR2>::turn_off(void) {
    for(int i = 0; i < 4; i++) {
        gpio_b->ODR &= ~(1 << i);
    }
}

template <uintptr_t ADDR1,uintptr_t ADDR2>
void LEDS<ADDR1,ADDR2>::turn_on(void) {
    for(int i = 0; i < 4; i++) {
        gpio_b->ODR |= (1 << i);
    }
}

template <uintptr_t ADDR1,uintptr_t ADDR2>
void LEDS<ADDR1,ADDR2>::led_on(uint8_t pin) {
    gpio_b->ODR &= (1 << pin);
    gpio_b->ODR |= (1 << pin);
}
