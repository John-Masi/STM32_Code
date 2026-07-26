#include "gpio.h"

int main() {
    gpio_init();
    while(1) {
        read_button();
    }
}
