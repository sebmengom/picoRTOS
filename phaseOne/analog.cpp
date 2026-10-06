#include "analog.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <cstdint>
#include <iostream>
#include <sys/_intsup.h>

long map(long result, long in_min, long in_max, long out_min, long out_max) {
  return ((result - in_min) * (out_max - out_min) / (in_max - in_min) +
          out_min);
}
void controlBrightness(int POT_PIN, int LED_PIN) {
  stdio_init_all();
  adc_init();
  adc_gpio_init(POT_PIN);
  adc_select_input(0);

  std::cout << "ADC Measuring..." << '\n';

  gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
  unsigned int slice_num{pwm_gpio_to_slice_num(LED_PIN)};
  pwm_set_wrap(slice_num, 255);
  pwm_set_enabled(slice_num, true);

  std::cout << "PWM Working";

  while (true) {

    uint16_t result{adc_read()};
    long pwm_value = map(result, 0, 4095, 0, 255);

    std::cout << "Raw: " << result << "PWM: " << pwm_value << '\n';

    pwm_set_gpio_level(LED_PIN, pwm_value);
    sleep_ms(50);
  }
}
