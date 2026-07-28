#include <stdint>

#pragma once 

typedef struct {
    volatile uint32_t ISER[7];
} NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef *)0xE000E100)