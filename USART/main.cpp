#include "include/usart.hpp"
#include "include/gpio.hpp"

int main() {
    USART usart;
    GPIO gpio;

    while(1) {
        usart.get_string(32);
        usart.send_str("Hey");
    }
}