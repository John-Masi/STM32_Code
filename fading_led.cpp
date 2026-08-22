#include <cstdint> 
#include "Timer/include/pwm_timer.hpp"

volatile uint16_t duty = 2000;
volatile uint16_t count{0};

template <uintptr_t ADDR,uintptr_t ADDR2,uint8_t PIN>
static TIM_TypeDef* func(const PWM_Timer<ADDR,ADDR2,PIN>& pwm) {
    return pwm.timer
}

int main(void) {
    PWM_Timer<TIM2,GPIOA,0> timer(30,2000);

    while(1) {
        if(func(timer)->SR |= (1 << 0)) {
            func(timer)->SR &= ~(1 << 0);

            count++;
            if(count > 0) {
                count = 0;
                duty--;
                timer.set_duty(duty);
                if(duty <= 0) {
                    duty = 2000;
                }
            }
        }
    }

};