#include "include/usart.hpp"

int main() {
    USART usart;

    while(1) {
        usart.get_string(32);
        usart.send_str("Hey");
    }
}