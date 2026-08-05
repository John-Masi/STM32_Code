#include "Timer/include/timer.hpp"
#include "GPIO/Include/gpio.hpp"

static volatile uint8_t ticks{};
static volatile uint8_t led_cnt{};
static volatile uint8_t max_led{4};
static volatile uint8_t count{};

static Timer timer(TIM2,1024,15624);

void EXTI15_10_IRQHandler(void) {
    if(timer.TIM->SR & (1 << 0)) {
        timer.TIM->SR &= ~(1 << 0);
        ticks++;
    }
};

void delay(int delay) {
    for(int i = 0; i <= delay; i++);
}

int main() {
    GPIO gpio;
    gpio.button_init();

    timer.start_timer();

    while(1) {
        if(ticks == 1) {
            gpio.led_on(led_cnt);
            led_cnt++;
            count++;
            ticks = 0;
            if(led_cnt == 4) {
                led_cnt = 0;
            }
        }

        if(count >= 11) {
            gpio.turn_on();
            delay(100000);
            timer.stop_timer();
            gpio.turn_off();
            count = 0;
        }
    }
}