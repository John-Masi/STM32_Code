#include <cstdint>
#include "i2c_typedef.hpp"

#ifndef I2C_HPP
#define I2C_HPP

template <uintptr_t BASE>
class I2C {
    public:
        I2C() = default;

        ~I2C() = default;


    void i2c_init(void);

    private:
        static constexpr auto i2c = reinterpret_cast<I2C_Typedef*>(BASE);

};


#endif


