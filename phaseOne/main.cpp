#include "led.h"
#include <iostream>
#include <pico/stdio_usb.h>
#include <pico/time.h>
int main() {
  stdio_init_all();
  while (!stdio_usb_connected()) {
    sleep_ms(100);
  }
  std::cout << "Initialized" << '\n';
  // ledButton(1, 2); // Uncomment to use button.
  ledTimed(1);
  return 0;
}
