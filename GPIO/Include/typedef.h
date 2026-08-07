#include <cstdint>

#pragma once 

struct GPIO_Typedef {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR_A;
    volatile uint32_t PUPDR_B;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
};

#define GPIOA ((GPIO_Typedef *)0x40020200)
#define GPIOB ((GPIO_Typedef *)0X40020400)
#define GPIOC ((GPIO_Typedef *)0X40020800)

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define SYSCFGEN 14
#define BTTN_PIN ~(3 << (13 * 2))