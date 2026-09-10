#ifndef ADC_TYPEDEF_HPP
#define ADC_TYPEDEF_HPP

#include <cstdint>

struct ADC_Typedef {
    volatile uint32_t SR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMPR1;
	volatile uint32_t SMPR2;
	volatile uint32_t JOFR1;
	volatile uint32_t r1[3];
	volatile uint32_t HTR;
	volatile uint32_t LTR;
	volatile uint32_t SQR1;
	volatile uint32_t SQR2;
	volatile uint32_t SQR3;
	volatile uint32_t JSQR;
	volatile uint32_t JDR1;
	volatile uint32_t r2[3];
	volatile uint32_t DR;
	volatile uint32_t CSR;
	volatile uint32_t CCR;
	volatile uint32_t CDR;
};

#define ADC1ADDR 0x40012000

#define EOCINTR 5
#define ADON 0
#define STARTCONV 30
#define EOC 1 

#endif 