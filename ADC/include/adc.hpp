#ifndef ADC_HPP
#define ADC_HPP

#include "adc_typedef.hpp"

template <uintptr_t ADDR,uint8_t PIN>
class ADC {
    public:
        ADC() {

            RCC->APB2ENR |= (1 << 8);
            adc->CR1 &= ~(3 << 24);
            adc->SQR1 = 0;
            adc->SQR3 = 0;
            adc->SMPR2 |= (7 << 0);
            adc->CR1 |= (1 << 5);
            adc->CR2 |= (1 << 0);
            adc->CR2 |= (1 << 0);
            adc->CR2 |= (1 << 30);

            NVIC->ISER0[0] |= (1 << 18);

        }

        auto get_EOC(void) {
        	return (adc->SR & (1U << 1));
        }

        auto get_data(void) {
        	return adc->DR;
        }

        void start_conversation(void) {
        	adc->CR2 |= (1U << 30);
        }

        void poll_adc(uint16_t val) {
            adc->CR2 |= (1U << 30);
            while(!(adc->SR & (1U << EOC)));
            val = adc->DR;
        }

    private:
        inline static auto adc = reinterpret_cast<ADC_Typedef*>(ADDR);
};

#endif 