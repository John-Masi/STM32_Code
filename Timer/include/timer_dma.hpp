#include <cstdint>
#include "timer_typedef.hpp"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/dma.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_DMA_HPP
#define TIMER_DMA_HPP

#define START (1 << 0)
#define STOP ~(1 << 0)

// Update DMA request 
#define UDE 8


template<uintptr_t BASE,uint8_t PSC,uint16_t ARR> 
class Timer_DMA {
    public:
        Timer_DMA() {
            timer->PSC = PSC;
            timer->ARR = ARR;
        }

        void start(void);
        void stop(void);
        
    private:
        constexpr static auto timer = reinterpret_cast<TIM_TypeDef*>(BASE);
};

#endif