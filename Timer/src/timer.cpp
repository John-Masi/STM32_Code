#include "../timer.hpp"

void Timer::start_timer(void) {
    tim->CR1 |= START;
}

void Timer::stop_timer(void) {
    tim->CR1 &= STOP;
}
