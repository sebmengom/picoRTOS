#ifndef ANALOG_H
#define ANALOG_H

#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <iostream>

void controlBrightness(int POT_PIN, int LED_PIN);
long map(long result, long in_min, long in_max, long out_min, long out_max);

#endif // !ANALOG_H
#define ANALOG_H
