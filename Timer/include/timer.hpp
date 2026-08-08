#include <cstdint>
#include <memory>
#include "typedef.hpp"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP

class Timer {
    public:
        Timer(const TIM_TypeDef* t,uint8_t p, uint16_t a) :  
        tim(std::make_unique<TIM_TypeDef>(t)),psc(p), arr(a) {};

        void timer_init(TIMNPOS pos);
        void start_timer(void);
        void stop_timer(void);
        
        // Prescaler value 
        uint16_t psc{};

        // Max upcount value
        uint16_t arr{};

        // Ptr to the desired timer
        std::unique_ptr<TIM_TypeDef> tim;

    private:
};

#endif 
