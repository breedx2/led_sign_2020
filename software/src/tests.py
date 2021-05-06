from sign import Sign
from sign_hardware import SignHardware
from sign_printer import SignPrinter
from sign_updater import SignUpdater
from sign_memory import create_memory
mem = create_memory()
hw = SignHardware()
sign = Sign(mem)
p = SignPrinter(sign)
u = SignUpdater(hw, mem)
u.start()
sign.col(15, 0xff)
# p.right('hello world')


import time
for i in range(0, 145):
    sign.col(i, 0xff)
    time.sleep_ms(250)
    sign.col(i, 0x00)


from machine import Pin, SPI, SoftSPI, Timer
spi = SPI(1, baudrate=3000000, polarity=1, phase=0, bits=8, firstbit=SPI.LSB, sck=Pin(23), mosi=Pin(22), miso=Pin(34))
pp = Pin(14, Pin.OUT, value=0)
Pin(21, Pin.OUT, value=0).on()
rowbuff = bytearray(19)
rowbuff[12] = 0xff
rowbuff[14] = 0xff
rowbuff[16] = 0xff
spi.write(rowbuff)
pp.on()
