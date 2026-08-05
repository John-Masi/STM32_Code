#include "../include/usart.hpp"

void USART::USART_init (void) {
    RCC->APB1ENR |= (1 << USART2EN);

    usart->BRR = 138;
    usart->CR1 |= (1 << CR1::RE);
    usart->CR1 |= (1 << CR1::TE);
    usart->CR1 |= (1 << CR1::UE);
}

char USART::get_char(void) {
    char c = usart->DR;
    return c;
}

void USART::send_char(char c) {
    tx_buffer[tx_head++] = c;
    if(tx_head >= 32) {
        tx_head = 0;
    }

    usart->CR1 |= (1 << 7);
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

void USART::enable_interrupt(USART_Typedef* usart) {
    if(!(usart->CR1 & (1 << 7) && (usart->CR1 & (1 << 8)))) {
        usart->CR1 |= (1 << 7);
        usart->CR1 |= (1 << 8);
    }
    else {
        usart->CR1 &= ~(1 << 7);
        usart->CR1 &= ~(1 << 8);
    }
}

bool USART::parse_string(std::string_view string) {
    if(!(string == std::string_view(buffer.data()))) {
        return 1;
    }

    return 0;
}