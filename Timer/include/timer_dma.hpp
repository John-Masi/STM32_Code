#include <cstdint>
#include "../../syscfg-nvic-rcc/include/rcc.hpp"
#include "../../syscfg-nvic-rcc/include/dma.hpp"
#include "../../syscfg-nvic-rcc/include/nvic.hpp"
#include "timer_typedef.hpp"

#ifndef TIMER_DMA_HPP
#define TIMER_DMA_HPP

// RCC indexes 
// Hardcoding RCC indexes for now
#define TIM2_EN (1 << 0)
#define DMA1_EN (1 << 21)

#define START (1 << 0)
#define STOP ~(1 << 0)

// Update DMA request 
#define UDE 8


template<uintptr_t ADDR1,uintptr_t ADDR2,uint8_t PSC,uint16_t ARR> 
class Timer_DMA {
    public:
        Timer_DMA() {
            RCC->APB1ENR |= TIM2_EN; 
            RCC->AHB1ENR |= DMA1_EN;
            timer->PSC = PSC;
            timer->ARR = ARR;
        }

        void start(void);
        void stop(void);
    private:
        constexpr static auto timer = reinterpret_cast<TIM_TypeDef*>(ADDR1);
        constexpr static auto dma = reinterpret_cast<DMA_Typedef*>(ADDR2);
};

#endif