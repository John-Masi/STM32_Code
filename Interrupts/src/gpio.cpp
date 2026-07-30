#include "../include/gpio.hpp"

void GPIO::gpio_init(GPIO_Typedef* gpio) {
    RCC->AHB1ENR |= (1 << GPIOAEN) | (1 << GPIOCEN);
    RCC->APB2ENR |= (1 << 14);
    gpio->MODER |= (2 << (13 * 2));
    
    
}