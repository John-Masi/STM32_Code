#include "../include/htu31.hpp"

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
void HTU31<I2C_ADDR,GPIO_ADDR>::read_poll(void){

};

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
void HTU31<I2C_ADDR,GPIO_ADDR>::write_poll(void) {

}

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
uint16_t HTU31<I2C_ADDR,GPIO_ADDR>::temp(void) {
    return ((uint16_t)data[0] << 8) | data[1];
}

template <uintptr_t I2C_ADDR,uintptr_t GPIO_ADDR>
uint16_t HTU31<I2C_ADDR,GPIO_ADDR>::humid(void) {
    return ((uint16_t)data[3] << 8) | data[4];
}