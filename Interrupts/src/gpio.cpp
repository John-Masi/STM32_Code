#include "../include/gpio.hpp"

void GPIO::set_gpio(GPIO_Typedef* gp) {
    gpio = gp;
}

void GPIO::gpio_init(void) {
    RCC->AHB1ENR |= (1 << GPIOAEN) | (1 << GPIOCEN);
    RCC->APB2ENR |= (1 << 14);
    gpio->MODER &= ~(0b11 << (13 * 2));
    
    
}

void GPIO::set_pin(uint8_t pin) {
    gpio->ODR |= (1 << pin);
}

void GPIO::clear_pin(uint8_t pin) {
    gpio->ODR &= ~(1 << pin);
}

void GPIO::toggle_pin(uint8_t pin) {
    gpio->ODR ^= (1 << pin);
}