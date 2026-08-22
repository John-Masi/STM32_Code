#include "timer_typedef.hpp"
#include "../../GPIO/Include/gpio_typedef.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef PWM_TIMER_HPP
#define PWM_TIMER_HPP

template<uintptr_t ADDR,uintptr_t ADDR2,uint8_t PIN>
class PWM_Timer {
    public:

        PWM_Timer(uint8_t psc,uint16_t arr) {   
            RCC->AHB1ENR = (1 << 0);
            RCC->APB1ENR = (1 << 0);

            gpio->MODER &= ~(3 << PIN);
            gpio->MODER |= (2 << PIN);

            gpio->AFRL &= ~(0xF << (PIN * 4));
            gpio->AFRL |= (2 << (PIN * 4));

            timer->PSC = psc;
            timer->ARR = arr;
            timer->CCRM1 |= (0b110 << 12);
            timer->CCER |= (1 << 4);

            
        }

        void start(void) {
            timer->CR1 |= (1 << 0);
        }

        void stop(void) {
            timer->CR1 &= ~(1 << 0);
        }

        void set_duty(uint16_t duty) {
            timer->CCR2 = duty;
        }


    private:
        constexpr static auto timer = reinterpret_cast<TIM_TypeDef*>(ADDR);
        constexpr static auto gpio = reinterpret_cast<GPIO_Typedef*>(ADDR2);
};

#endif 