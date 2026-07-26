#include "gpio.h"

void gpio_init(void) {
    RC->AHB1ENR |= (1 << GPIOAEN);
    RC->AHB1ENR |= (1 << GPIOCEN);

    GPIOC->PUPDR &= ~(0b11 << (PIN13 * 2));
    GPIOC->PUPDR |=  (0b01 << (PIN13 * 2));
    GPIOC->MODER &= ~(0b11 << (PIN13 * 2));
    GPIOA->MODER &= ~(0b11 << (PIN5 * 2));
    GPIOA->MODER |= (1 << (PIN5 * 2));
    GPIOA->ODR |= (1 << PIN5);
}

void read_button(void) {

	if(!(GPIOC->IDR & (1 << PIN13))) {
		flag ^= 1;
		if(flag) {
			GPIOA->ODR |= (1 << PIN5);
		}
		else {
			GPIOA->ODR &= ~(1 << PIN5);
		}

		while(!(GPIOC->IDR & (1 << PIN13))) {

		}
	}


}
