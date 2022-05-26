#!/bin/bash

# drwxr-xr-x  2 root root    0 Jan 12 01:00 ./
# drwxr-xr-x 91 root root    0 Jan 12 00:54 ../
# --w--w----  1 root gpio 4096 Jan 12 00:36 export
# lrwxrwxrwx  1 root root    0 Jan 12 00:36 gpiochip0 -> ../../devices/3180000.i2c/i2c-2/2-0060/gpio/gpiochip0/
# lrwxrwxrwx  1 root root    0 Jan 12 00:36 gpiochip240 -> ../../devices/bpmp_i2c/i2c-4/4-003c/max77620-gpio/gpio/gpiochip240/
# lrwxrwxrwx  1 root root    0 Jan 12 00:36 gpiochip248 -> ../../devices/c2f0000.gpio/gpio/gpiochip248/
# lrwxrwxrwx  1 root root    0 Jan 12 00:36 gpiochip288 -> ../../devices/2200000.gpio/gpio/gpiochip288/
# lrwxrwxrwx  1 root root    0 Jan 12 00:36 gpiochip8 -> ../../devices/3180000.i2c/i2c-2/2-0061/gpio/gpiochip8/
# --w--w----  1 root gpio 4096 Jan 12 00:36 unexport
# 

echo    440 > /sys/class/gpio/export    # gpio pin 0
#echo   443 > /sys/class/gpio/export    # gpio pin 1
#echo   444 > /sys/class/gpio/export    # gpio pin 2
#echo   417 > /sys/class/gpio/export    # gpio pin 3

echo    1   > /sys/class/gpio/gpio440/value    # set pin0 to 1


i2cdetect -y -r 0  # detect all the i2c address from 0 to 0x7F
i2cdetect -y -r 0 80 80 # detect all the i2c address 0x50 ( dec 80 )
