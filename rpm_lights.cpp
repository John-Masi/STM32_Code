#include "ADC/include/adc.hpp"
#include "PIN/include/pin.hpp"
#include "GPIO/Include/gpio.hpp"

namespace RPM_LIGHTS {
    using g_pin1 = Pin<1,Mode::OUTPUT>;
    using g_pin2 = Pin<1,Mode::OUTPUT>;
    using y_pin1 = Pin<1,Mode::OUTPUT>;
    using y_pin2 = Pin<1,Mode::OUTPUT>;
    using r_pin1 = Pin<1,Mode::OUTPUT>;
    using r_pin2 = Pin<1,Mode::OUTPUT>;


    using adc_pin = Pin<1,Mode::ALTERNATE>;

    GPIO<GPIOA,GPIOAEN> gpioa;
    GPIO<GPIOC,GPIOCEN> gpioc;

    template<typename... Pins>
    inline void init_all() {
        (gpioa.set_mode<Pins>(), ...);
    }

    void green_on(void) {
        gpioa.output_on<g_pin1,g_pin2>();
    }
    void yellow_on(void) {
        gpioa.output_on<y_pin1,y_pin2>();
    }
    void red_on(void) {
        gpioa.output_on<r_pin1,r_pin2>();
    }

    void pin_init() {
        init_all<g_pin1,g_pin2,y_pin1,y_pin2,r_pin1,r_pin2,adc_pin>();
    }
}

int main() {
    RPM_LIGHTS::pin_init();
    while(1) {

    }
}