#include "include/usart.hpp"
#include "include/gpio.hpp"
#include "include/nvic.hpp"

static USART* irq_ptr{nullptr};
extern "C" void UART2_IRQHandler(void) 
{
    if(irq_ptr->getPerph()->CR1 & (1 << SR::RXNE)) {
        char c = irq_ptr->getPerph()->DR;
        irq_ptr->getPerph()->DR = c;
        
    }
}

int main() {

    nvic_init();
    USART usart(USART2);
    GPIO gpio;
    irq_ptr = {&usart};

    while(1) {
        usart.get_string(32);


        if(usart.parse_string("hello") == 0) {
            usart.send_str("hey");
        }
    }
}