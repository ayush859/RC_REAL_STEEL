#include "wifi_module.h"
#include "uart_module.h"

int main(void) {
    uart_init();
    wifi_init();

    while (1) {
        char command = wifi_receive_command();
        uart_send_command(command);
    }

    return 0;
}
