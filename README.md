
# led_sign_2020

This is a hardware refresh of [a project I started in 1999](https://noisybox.net/electronics/LED_sign).
It involved creating a custom hardware controller for a vintage (1980s) scrolling LED sign.

The previous hardware stack had a Microchip PIC controller with very little RAM.  It was 
hard-wired to a PC via RS232 cable and had zero brains on-device.  The pic allowed the PC
to address and write memory, and the memory was blittled to the sign.

A lot has changed in 20 years.  This is an update.
