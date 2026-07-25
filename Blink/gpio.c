#include "gpio.h"

void gpio_init(void) {
    RC->AHB1ENR |= (GPIOAEN);
    
    GPIOA->MODER &= ~(3 << (PIN5 * 2));
    GPIOA->MODER |= (3 << (PIN5 * 2));
    GPIOA->ODR |= (1 << PIN5);
}

