#ifndef ADC_HPP
#define ADC_HPP

#include "adc_typedef.hpp"

template <uintptr_t ADDR,bool interEOC,uint8_t PIN>
class ADC {
    public:
        ADC() {
            if constexpr(interEOC) {
                // Turn on EOC interrupt
                adc->CR1 |= (1 << EOCINTR);

            }
            channel_pick();
            sample_pick();

            adc->CR2 |= (1 << ADON);

        }

        // Pin number determines what channel we use and then the channel will determine the conversation sequence 
        void channel_pick(uint8_t pin = 0) {
            

            if(pin <= 16 && pin >= 13) {
                // SQR1 
            }
            else if(pin <= 12 && pin >= 7) {
                // SQR2 
            }
            else {
                // SQR3 
            }
        }

        void sample_pick(uint8_t pin = 0) {
            if(pin >= 0 && pin <= 9) {
                // SMP1X
            }
            else {
                // SMP2X 
            }
        }

        void poll_adc(void) {
            adc->CR2 |= (1 << 30);
            while(!(adc->SR & (1 << EOC)));
            uint16_t value = adc->DR;
        }


    private:
        inline static auto adc = reinterpret_cast<ADC_Typedef*>(ADDR);
};

#endif 