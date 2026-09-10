#ifndef PIN_HPP
#define PIN_HPP

#include <cstdint>

enum class Mode : uint8_t {
    INPUT,
    OUTPUT,
    ALTERNATE,
    ANALOG
};

struct Pin {
    uint8_t num{};
    Mode moder{};
    uint8_t AF{};

    uint8_t MODERMSK{};
    uint8_t AFRMSK{};

     Pin(uint8_t n,Mode mode,uint8_t af = 0) : num(n), moder(mode), AF(af) {
        MODERMSK = (num * 2);
        AFRMSK = (num * 4);
    }
};

#endif 