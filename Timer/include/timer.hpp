#include <stdint.h>
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP

 struct TIM_TypeDef {
    volatile uint32_t CR1;
	volatile uint32_t r[2];
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t r1[4];
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
};

#define TIM2 ((TIM_TypeDef *)0x40000000) 
#define NVIC_TIM2 28
#define START (1 << 0)
#define STOP ~(1 << 0)

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