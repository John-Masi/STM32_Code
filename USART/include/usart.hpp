#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array>
#include <string_view>
#include "typedef.h"
#include "../syscfg-nvic-rcc/include/rcc.hpp"

#ifndef USART_HPP
#define USART_HPP

class USART {
    public:
        USART(USART_Typedef* usart_param) {
            usart = usart_param;
            USART_init();
        }

        std::array<char, 32> buffer;
        std::array<char ,32> tx_buffer;

        uint8_t tx_head;
        uint8_t tx_tail;

        uint8_t rx_head;
        uint8_t rx_tail;

        void USART_init(void);
        char get_char(void);
        void send_str(std::string_view s);
        void send_char(char c);
        void get_string(uint8_t maxSize);
        void array_to_str(char * buff);
        void enable_interrupt(USART_Typedef* usart);
        bool parse_string(std::string_view string);
        USART_Typedef* getPerph() { return usart; }

    private:
        USART_Typedef* usart{nullptr};
};

#endif 