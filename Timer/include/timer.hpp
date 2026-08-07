#include <stdint.h>
#include "typedef.h"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP

class Timer {
    public:
        Timer(const TIM_TypeDef* tim,uint8_t psc, uint16_t arr) {
            *TIM = *tim;
            tim = nullptr;

            RCC->APB1ENR |= (1 << 0);
            TIM->PSC = psc;
            TIM->ARR = arr;
            NVIC->ISER0[0] |= (1 << NVIC_TIM2);

        };

        void start_timer(void);
        void stop_timer(void);
        

        TIM_TypeDef* TIM{nullptr};
    private:
};

#endif 