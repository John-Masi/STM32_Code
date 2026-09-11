#ifndef PIN_HPP
#define PIN_HPP

#include <cstdint>

enum class Mode : uint8_t {
    INPUT,
    OUTPUT,
    ALTERNATE,
    ANALOG
};

template <uint8_t num,Mode moder,uint8_t af = 0>
struct Pin {
    static constexpr uint8_t num{num};
    static constexpr Mode moder{moder};
    static constexpr uint8_t AF{af};

    static constexpr uint8_t MODERMSK{num * 2};
    static constexpr uint8_t AFRMSK{num * 4};
};

#endif 