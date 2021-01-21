
# led_sign_2020

This is a hardware refresh of [a project I started in 1999](https://noisybox.net/electronics/LED_sign).
It involved creating a custom hardware controller for a vintage (1980s) scrolling LED sign.

The previous hardware stack had a Microchip PIC controller with very little RAM.  It was 
hard-wired to a PC via RS232 cable and had zero brains on-device.  The pic allowed the PC
to address and write memory, and the memory was blittled to the sign.

A lot has changed in 20 years.  This is an update.


# update goals

Why update? Because.

* serial port RS232 cable in 2020? Meh.
* Let's try getting on wifi!
* Move more display logic to the device
* eliminate the need for a PC
* make external/remote/iot interfaces easier/fancier.

# hardware

The design is based on an ESP32-DevKitC (generic/ripoff with ipex antenna connector).  It uses 
4 2-channel high current (4A) MAXIM drivers for the rows. Wifi is achieved with a panel mount antenna
(because the case is steel). A high-current 5V power supply powers the sign and the ESP32 devkit.

<img src="https://raw.githubusercontent.com/breedx2/led_sign_2020/main/doc/board_front_20210120.png" alt="pcb"/>

# bom

tbd

# notes

tbd
