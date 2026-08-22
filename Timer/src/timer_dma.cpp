#include "../include/timer_dma.hpp"

template<uintptr_t ADDR1,uintptr_t ADDR2,uint8_t PSC,uint16_t ARR> 
void Timer_DMA<ADDR1,ADDR2,PSC,ARR>::start(void) {
    timer->CR1 |= (1 << 0);
}

template<uintptr_t ADDR1,uintptr_t ADDR2,uint8_t PSC,uint16_t ARR> 
void Timer_DMA<ADDR1,ADDR2,PSC,ARR>::stop(void) {
    timer->CR1 &= ~(1 << 0);
}

template<uintptr_t ADDR1,uintptr_t ADDR2,uint8_t PSC,uint16_t ARR> 
void Timer_DMA<ADDR1,ADDR2,PSC,ARR>::dma_copy(void) {
    dma->S1CR &= ~(1 << 0);

    while(dma->S1CR & (1 << 0));
    

}