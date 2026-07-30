#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <array>
#include <string_view>
#include "rcc.hpp"

#ifndef USART_HPP
#define USART_HPP

enum SR : uint8_t {
    PE,
    FE,
    NF,
    ORE,
    IDLE,
    RXNE,
    TC,
    TXE,
    LBD
};

enum  CR1 : uint8_t {
    RE = 2,
    TE = 3,
    M = 12,
    UE = 13
};

struct USART_Typedef {
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
};
#define USART2 ((USART_Typedef *)0x4004400)

class USART {
    public:
        USART() {
            USART_init();
        }

        void USART_init(void);
        char get_char(void);
        void send_str(std::string_view s);
        void send_char(char c);
        void get_string(uint8_t maxSize);
        void array_to_str(char * buff);
        bool isEqual(std::string_view s);

    private:
        std::array<uint8_t, 32> buffer;
};

#endif 