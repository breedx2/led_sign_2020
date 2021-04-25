from machine import Pin
import time

# pin mappings
EN    = 21
CDATA = 22
CCLK  = 23
C1    = 12
C2    = 13
C3    = 14
C4    = 15
C5    = 16
C6    = 17
C7    = 18

class SignHardware:
    """Sign hardware abstraction"""

    COLS = 145

    def __init__(self):
        self.en =    Pin(CLK,   Pin.OUT, value=0)
        self.cdata = Pin(CDATA, Pin.OUT, value=0)
        self.clk =   Pin(CDATA, Pin.OUT, value=0)
        self.rows = [
            Pin(C1, Pin.OUT, value=0),
            Pin(C2, Pin.OUT, value=0),
            Pin(C3, Pin.OUT, value=0),
            Pin(C4, Pin.OUT, value=0),
            Pin(C5, Pin.OUT, value=0),
            Pin(C6, Pin.OUT, value=0),
            Pin(C7, Pin.OUT, value=0)
        ]

    def enable_output(self):
        self.en.on()

    def disable_output(self):
        self.en.off()

    def row_on(self, num):
        self.rows[num].on()

    def row_off(self, num):
        self.rows[num].off()
