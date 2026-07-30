#include "../include/usart.hpp"

void USART::USART_init (void) {
    RCC->APB2ENR |= (1 << USART1EN);

    USART2->BRR = (104 << 4) | 3;
    USART2->CR1 |= (1 << CR1::RE);
    USART2->CR1 |= (1 << CR1::TE);
    USART2->CR1 &= ~(1 << CR1::M);
}

char USART::get_char(void) {
    while(!(USART2->SR & (1 << 5))) {

    }

    char c = USART2->DR;
    return c;
}

void USART::send_char(char c) {
    while(!(USART2->SR & (1 << SR::TXE))) {

    }

    USART2->DR = c;
}

void USART::send_str(std::string_view s) {
    for(auto n: s) {
        send_char(n);
    }
}

void USART::get_string(uint8_t maxSize) {
    uint8_t i = 0;
    while(i < maxSize - 1) {
        char c = get_char();
        send_char(c);
        if(c == '\r' || c == '\n') {
            send_char('\r');
            send_char('\n');
            break;
        }

        buffer[i] = c;
        i++;
    }
    
    buffer[i] = '\0';

} 

bool USART::isEqual(std::string_view s) {
    
}