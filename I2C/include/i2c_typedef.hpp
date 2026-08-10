#include <cstdint>

#ifndef I2C_TYPEDEF_HPP
#define I2C_TYPEDEF_HPP


struct I2C_Typedef {
    volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
};

#define I2C1 0X40005400

#endif 
