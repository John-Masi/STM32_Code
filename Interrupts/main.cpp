#include "include/gpio.hpp"
#include "include/nvic.hpp"

void EXTI15_10_IRQHandler(void) {
    if(!(EXTI->PR & (1 << 13))) {
        EXTI->PR |= (1 << 13);
    }
}

int main() {
    GPIO gp(GPIOC);
    irq_init();

    while(1) {

    }
}