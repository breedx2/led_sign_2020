from machine import Pin, SPI, SoftSPI, Timer
import time

# pin mappings
_EN    = const(21)
_CDATA = const(22)
_CCLK  = const(23)
_BS_IN = const(34)
_C1    = const(12)
_C2    = const(13)
_C3    = const(14)
_C4    = const(15)
_C5    = const(16)
_C6    = const(17)
_C7    = const(18)

_spi = SPI(1, baudrate=3000000, polarity=1, phase=0, bits=8, firstbit=SPI.LSB, sck=Pin(_CCLK), mosi=Pin(_CDATA))
_en = Pin(_EN, Pin.OUT, value=0)
_rows = [
    Pin(_C1, Pin.OUT, value=0),
    Pin(_C2, Pin.OUT, value=0),
    Pin(_C3, Pin.OUT, value=0),
    Pin(_C4, Pin.OUT, value=0),
    Pin(_C5, Pin.OUT, value=0),
    Pin(_C6, Pin.OUT, value=0),
    Pin(_C7, Pin.OUT, value=0)
]

def enable_output():
    global _en
    _en.on()

def disable_output():
    global _en
    _en.off()

@micropython.native
def row_on(num):
    global _rows
    _rows[num].on()

@micropython.native
def row_off(num):
    global _rows
    _rows[num].off()

def all_rows_off():
    global _rows
    for row in _rows:
        row.off()

@micropython.native
def shift_row(rownum, memory):
    global _spi
    _spi.write(memory[rownum])
