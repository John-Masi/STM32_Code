#include <cstdint>
#include "i2c_typedef.hpp"

#ifndef I2C_HPP
#define I2C_HPP

template <uintptr_t BASE,uint8_t CCR, uint8_t CR2, uint8_t TRISE>
class I2C {
    public:
        I2C() {
            i2c->TRISE = TRISE;
            i2c->CCR = CCR;
            i2c->CR2 =  CR2;
        };

    void i2c_start(void) {
        i2c->CR1 |= (1 << 0);
    }

    void validate_address(void);

    private:
        static constexpr auto i2c = reinterpret_cast<I2C_Typedef*>(BASE);

};


#endif


