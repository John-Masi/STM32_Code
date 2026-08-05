#include <cstdint>

#ifndef I2C_HPP
#define I2C_HPP

struct I2C_Typedef {
    volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
};

#define I2C1 ((I2C_Typedef *)0X40005400)

class I2C {
    public:
        I2C(I2C_Typedef& i2c) {
            I2C_ptr = &i2c; 
            i2c_init();
        }

        ~I2C() = default;


    void i2c_init(void);

    private:
        I2C_Typedef* I2C_ptr{nullptr};

};


#endif


