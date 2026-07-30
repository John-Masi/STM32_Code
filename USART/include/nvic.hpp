#include <cstdint>

#ifndef NVIC_HPP
#define NVIC_HPP

struct NVIC_Typedef {
    volatile uint32_t ISER0[7];
};

#define NVIC ((NVIC_Typedef *)0xE000E100)

void nvic_init(void) {
    NVIC->ISER0[4] |= (1 << 38);
}

#endif 