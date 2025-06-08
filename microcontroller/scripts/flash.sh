# Adjust the OpenOCD interface and target configuration files (stlink.cfg, stm32f1x.cfg) according to your specific hardware.


#!/bin/bash

# Flash the firmware to the STM32 microcontroller using OpenOCD
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program build/rc_car_firmware.elf verify reset exit"
