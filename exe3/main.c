#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_VERMELHO = 28;
const int BTN_PIN_VERDE = 26;
const int LED_PIN_VERMELHO= 4;
const int LED_PIN_VERDE = 6;


int main() {
  stdio_init_all();
  gpio_init(BTN_PIN_VERMELHO);
  gpio_set_dir(BTN_PIN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_PIN_VERMELHO);

  gpio_init(BTN_PIN_VERDE);
  gpio_set_dir(BTN_PIN_VERDE, GPIO_IN);
  gpio_pull_up(BTN_PIN_VERDE);
  gpio_init(LED_PIN_VERMELHO);
  gpio_set_dir(LED_PIN_VERMELHO, GPIO_OUT);
  gpio_init(LED_PIN_VERDE);
  gpio_set_dir(LED_PIN_VERDE, GPIO_OUT);
  bool btn_vermelho_pressed = false;
  bool btn_verde_pressed = false;

  while (true) {
      if (!gpio_get(BTN_PIN_VERMELHO)) {
        printf("Botao Vermelho\n");
        gpio_put(LED_PIN_VERMELHO, 1);
        btn_vermelho_pressed = !btn_vermelho_pressed;
        while (!gpio_get(BTN_PIN_VERMELHO)) {
        };  
      }
      if (!gpio_get(BTN_PIN_VERDE)) {
        printf("Botao Verde\n");
        gpio_put(LED_PIN_VERDE, 1);
        btn_verde_pressed = !btn_verde_pressed;
        while (!gpio_get(BTN_PIN_VERDE)) {
        };
      } 
      if (!btn_vermelho_pressed) {
        gpio_put(LED_PIN_VERMELHO, 0);
      }
      if (!btn_verde_pressed) {
        gpio_put(LED_PIN_VERDE, 0);
      }
  }
  return 0;
}
