#include <stdint.h>
#include <stdlib.h> 
#include "stm32f446xx.h"

#ifndef GPIO_H
#define GPIO_H

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OYPER;
    volatile uint32_t OSPEEDER;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO; 

#define GPIOA ((GPIO *)0x40020000)
#define PIN5 5

void gpio_init(void);

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t r[9]; // reserved data
    volatile uint32_t AHB1ENR; 
} RCC; 

#define RC ((RCC *)0X40023800)
#define GPIOAEN 0

#endif

uint8_t flag = 0;
