#include <cstdint>
#include <memory>
#include "timer_typedef.hpp"
#include "../syscfg-nvic-rcc/include/rcc.hpp"
#include "../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP


template <uintptr_t BASE>
class Timer {
    public:

        Timer(uint8_t p, uint16_t a) {
            timer->PSC = p;
            timer->ARR = a;
        };

        void start_timer(void);
        void stop_timer(void);
        void enable_dma(void);

        template <uintptr_t BASE>
        static TIM_TypeDef func(const Timer<BASE>& t) {
            return t.timer;
        }

    private:
        static constexpr auto timer = reinterpret_cast<TIM_TypeDef*>(BASE);
};

#endif 
