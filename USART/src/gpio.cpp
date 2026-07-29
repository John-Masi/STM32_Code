#include "../include/gpio.hpp"

void GPIO::gpio_init(void) {
    RCC->AHB1ENR |= (1 << GPIOAEN) | (1 << GPIOCEN);
    GPIOA->MODER |= (2 << (9 * 2));
    GPIOA->AFRL |= (7 << 4);
}