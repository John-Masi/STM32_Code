#include <cstdint>

#pragma once 

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
#define USART2EN 17