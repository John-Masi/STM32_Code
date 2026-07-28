#include "include/timer.h"
#include "include/gpio.h"

volatile uint32_t ticks;

void TIM2_IRQHandler(void) {
    if(TIM2->SR & (1 << 0)) {
        TIM2->SR &= ~(1 << 0);
        ticks++;
    }
}

int main() {
    gpio_init();
    timer_init();
    while(1) {
        if(ticks == 60) {
            led_on();
            ticks = 0;
        }
        else {
            led_off();
        }
    }
}