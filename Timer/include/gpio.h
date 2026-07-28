#include <stdint.h>
#include "rcc.h"

#pragma once

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OYPER;
    volatile uint32_t OSPEEDER;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIOA_TypeDef;

#define GPIOA ((GPIOA_TypeDef *)0x40020000)
#define PIN5 5

void gpio_init(void) {
    RCC->AHB1ENR |= (1 << 0);
    GPIOA->MODER &= ~(0b11 << (PIN5 * 2));
    GPIOA->MODER |= (1 << (PIN5 * 2));
}

void led_on(void) {
    GPIOA->ODR |= (1 << PIN5);
}

void led_off(void) {
    GPIOA->ODR &= ~(1 << PIN5);
}