#include <stdint.h>
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#pragma once 

typedef struct {
    volatile uint32_t CR1;
	volatile uint32_t r[2];
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t r1[4];
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
} TIM2_TypeDef;

#define TIM2 ((TIM2_TypeDef *)0x40000000)

void timer_init(void) {
    RCC->APB1ENR |= (1 << 0);
    TIM2->PSC = 1024;
    TIM2->ARR = 15624;
    TIM2->CR1 |= (1 << 0);
    TIM2->DIER |= (1 << 0);

    NVIC->ISER0[0] |= (1 << 28);
}