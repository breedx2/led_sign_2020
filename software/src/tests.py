from sign import Sign
from sign_hardware import SignHardware
from sign_printer import SignPrinter
from sign_updater import SignUpdater
mem = bytearray(145)
hw = SignHardware()
sign = Sign(mem)
p = SignPrinter(sign)
u = SignUpdater(hw, mem)
p.right('hello world')
u.start()



from machine import Pin, SPI, SoftSPI, Timer
spi = SPI(1, baudrate=3000000, polarity=1, phase=0, bits=8, firstbit=SPI.LSB, sck=Pin(23), mosi=Pin(22), miso=Pin(34))
pp = Pin(14, Pin.OUT, value=0)
rowbuff = bytearray(19)
spi.write(rowbuff)
pp.on()
