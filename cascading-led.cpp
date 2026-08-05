#include "GPIO/Include/gpio.hpp"

// How the program works
// Using PA13 (The GPIOA pin for USER button)
// After every falling edge turn on an led Bulb and turn off the previous
// Reset led count to 0 once we reach the max amount of led's wired 

static volatile uint8_t bp{};
static volatile uint8_t max_led{4};
static volatile uint8_t led_cnt{}; 

void EXTI15_10_IRQHandler() {
    bp = 1;
    EXTI->PR |= (1 << 13);

}

int main() {
    while(1) {
        if(bp) {
            led_cnt++;
            bp = 0;
            if(led_cnt == max_led) {
                led_cnt = 0;
            }
        }
    }
}   