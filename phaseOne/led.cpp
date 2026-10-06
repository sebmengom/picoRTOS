#include "led.h"
#include <iostream>
#include <pico/stdlib.h>

void ledButton(const int LED_PIN, const int BUTTON_PIN) {

  bool last_status{1}; // Not Pressed
  bool led_status{0};

  gpio_init(LED_PIN);
  gpio_init(BUTTON_PIN);

  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_pull_up(BUTTON_PIN);

  while (true) {
    bool current_status = gpio_get(BUTTON_PIN);
    if (last_status == 1 && current_status == 0) {
      led_status = !led_status;
      std::cout << "LED: " << led_status << '\n';
      gpio_put(LED_PIN, led_status);
      sleep_ms(250); // debounce
    }

    last_status = current_status;
  }
}
void ledTimed(const int LED_PIN) {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  while (true) {

    gpio_put(LED_PIN, 1);
    sleep_ms(500);
    gpio_put(LED_PIN, 0);
    sleep_ms(500);
  }
}
