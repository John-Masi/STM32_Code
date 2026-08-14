#include "../include/htu31.hpp"

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
void HTU31<I2C_ADDR,GPIO_ADDR>::read_poll(const uint8_t readADDR){
    i2c->CR1 |= START;

    while(!(i2c->SR1 & START_WAIT));

    (void)i2c->SR1;
    i2c->DR = (readADDR << 1);
    while(!(i2c->SR1 & ADDR_WAIT));

    (void)i2c->SR1;
    (void)i2c->SR2;

    i2c->DR = readADDR;

    while(!(i2c->SR1 & DR_EMPTY));

    i2c->CR1 |= STOP;
};

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
void HTU31<I2C_ADDR,GPIO_ADDR>::write_poll(const uint8_t readADDR,const uint8_t writeCMD) {
    i2c->CR1 |= ACK_EN;
    i2c->CR1 |= START;

    while(!(i2c->SR1 & START_WAIT));

    i2c->DR = (readADDR << 1);
    while(!(i2c->SR1 & ADDR_WAIT));

    (void)i2c->SR1;
    (void)i2c->SR2;

    i2c->DR = writeCMD;

    while(!(i2c->SR1 & DR_EMPTY));

    i2c->DR = (readADDR << 1) | 1;
    while(!(i2c->SR1 & ADDR_WAIT));

    (void)i2c->SR1;
    (void)i2c->SR2;

    for(volatile int i = 0; i < 5; i++) {
        while(!(i2c->SR1 & DR_NOTEMPTY);
        data[i] = i2c->DR;
    }

    i2c->CR1 &= ~(ACK_EN);
     while (!(i2c->SR1 & DR_NOTEMPTY));
    data[5] = i2c->DR;
    i2c->CR1 |= STOP;
	i2c->CR1 |= ACK_EN;

}

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
uint16_t HTU31<I2C_ADDR,GPIO_ADDR>::temp(void) {
    return ((uint16_t)data[0] << 8) | data[1];
}

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
uint16_t HTU31<I2C_ADDR,GPIO_ADDR>::humid(void) {
    return ((uint16_t)data[3] << 8) | data[4];
}