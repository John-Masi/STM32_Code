#include <stdint.h>

#pragma once 

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t reserved[9];
    volatile uint32_t AHB1ENR;
    volatile uint32_t r[3];
    volatile uint32_t APB1ENR;
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)0X40023800)