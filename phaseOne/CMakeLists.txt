add_executable(phaseOne main.cpp led.cpp analog.cpp)

target_link_libraries(phaseOne pico_stdlib pico_cyw43_arch_none hardware_adc hardware_pwm)
pico_enable_stdio_usb(phaseOne 1)
pico_enable_stdio_uart(phaseOne 0)

pico_add_extra_outputs(phaseOne)
