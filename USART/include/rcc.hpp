#include <stdint.h>

#ifndef RCC_HPP
#define RCC_HPP

struct RCC_Typedef {
    volatile uint32_t r[16];
    volatile uint32_t APB2ENR;
}; 

#define RCC ((RCC_Typedef *)0x40023800)
#define USART1EN 4

#endif 