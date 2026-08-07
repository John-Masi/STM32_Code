#include "../timer.hpp"

void Timer::start_timer(void) {
    TIM->CR1 |= START;
}

void Timer::stop_timer(void) {
    TIM->CR1 &= STOP;
}