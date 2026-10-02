cmake_minimum_required(VERSION 3.17)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(pico_rtos)
pico_sdk_init()

add_compile_options(-fno-exceptions -fno-rtti)

add_subdirectory(phaseOne)

add_custom_target(flash COMMAND cp -x $<TARGET_FILE_DIR:phaseOne>/phaseOne.uf2 /Volumes/RPI-RP2/ DEPENDS phaseOne COMMENT "Flashing phaseOne")


