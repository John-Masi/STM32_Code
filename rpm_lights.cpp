#include "ADC/include/adc.hpp"
#include "PIN/include/pin.hpp"
#include "GPIO/Include/gpio.hpp"

void delay(uint32_t ms) {
	for(volatile uint32_t i = 0; i < ms; i++);
}

namespace RPM_LIGHTS {
	uint16_t maxThreshold = 3800;
	uint16_t greenThreshold = 700;
	uint16_t yellowThreshold = 1900;
	uint16_t redThreshold = 3500;

    using g_pin1 = Pin<1,Mode::OUTPUT>;
    using g_pin2 = Pin<7,Mode::OUTPUT>;
    using y_pin1 = Pin<4,Mode::OUTPUT>;
    using y_pin2 = Pin<8,Mode::OUTPUT>;
    using r_pin1 = Pin<0,Mode::OUTPUT>;
    using r_pin2 = Pin<1,Mode::OUTPUT>;

    using adc_pin = Pin<0,Mode::ANALOG>;

    GPIO<GPIOA,GPIOAEN> gpioa;
    GPIO<GPIOC,GPIOCEN> gpioc;
    ADC<ADC1,0> adc1;

    template<typename... Pins>
    inline void init_a(void) {
        (gpioa.set_mode<Pins>(), ...);
    }

    template<typename... Pins>
    inline void init_c(void) {
    	(gpioc.set_mode<Pins>(), ...);
     }

    void green_toggle(void) {
        gpioa.output_toggle<g_pin1,g_pin2>();
    }

    void yellow_toggle(void) {
        gpioa.output_toggle<y_pin1,y_pin2>();
    }

    void red_toggle(void) {
        gpioc.output_toggle<r_pin1,r_pin2>();
    }

    void all_toggle(void) {
    	gpioa.output_toggle<g_pin1,g_pin2,y_pin1,y_pin2>();
    	gpioc.output_toggle<r_pin1,r_pin2>();
    	delay(50000);
    }

    void all_off(void) {
    	gpioa.output_off<g_pin1,g_pin2,y_pin1,y_pin2>();
    	gpioc.output_off<r_pin1,r_pin2>();
    }

    void pin_init(void) {
        init_a<g_pin1,g_pin2,y_pin1,y_pin2,adc_pin>();
        init_c<r_pin1,r_pin2>();
    }

    void handle_rpm(volatile uint16_t rpm) {
    	if(rpm < greenThreshold) {
    		all_off();
    	}
    	else if(rpm >= greenThreshold && rpm < yellowThreshold) {
    		green_toggle();
    	}
    	else if(rpm >= yellowThreshold && rpm < redThreshold) {
    		yellow_toggle();
    	}
    	else if(rpm >= redThreshold && rpm < maxThreshold) {
    		red_toggle();
    	}
    	else {
    		all_toggle();
    	}
    }
}


volatile uint16_t value = 0;
extern "C" void ADC_IRQHandler(void) {
		if(RPM_LIGHTS::adc1.get_EOC()) {
			value = RPM_LIGHTS::adc1.get_data();
			RPM_LIGHTS::adc1.start_conversation();
		}
}

void cppmain(void) {
	RPM_LIGHTS::pin_init();
	while(1) {
		RPM_LIGHTS::handle_rpm(value);
	}

}