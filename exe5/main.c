#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    bool last_btn_1_state = true;
    bool last_btn_2_state = true;

    while (true) {
        sleep_ms(20); 
        bool current_btn_1_state = gpio_get(BTN_PIN);
        bool current_btn_2_state = gpio_get(BTN_PIN_2);

        if (current_btn_1_state && !last_btn_1_state) {
            printf("Botao 1: %d\n", cnt_1++);
        }

        if (current_btn_2_state && !last_btn_2_state) {
            printf("Botao 2: %d\n", cnt_2++);
        }

        last_btn_1_state = current_btn_1_state;
        last_btn_2_state = current_btn_2_state;
    }
}
