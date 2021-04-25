from machine import Pin
import time

# pin mappings
EN    = const(21)
CDATA = const(22)
CCLK  = const(23)
C1    = const(12)
C2    = const(13)
C3    = const(14)
C4    = const(15)
C5    = const(16)
C6    = const(17)
C7    = const(18)

COLS = const(145)

class SignHardware:
    """Sign hardware abstraction"""

    def __init__(self):
        self.en    = Pin(EN,    Pin.OUT, value=0)
        self.cdata = Pin(CDATA, Pin.OUT, value=0)
        self.cclk  = Pin(CCLK,  Pin.OUT, value=0)
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

    def all_rows_off(self):
        for row in self.rows:
            row.off()

    def data_out(self, value):
        self.cdata.value(0 if value == 0 else 1)

    def clk_pulse(self):
        self.cclk.on()
        # time.sleep_us(1)
        self.cclk.off()

    # memory should be of size COLS
    @micropython.native
    def shift_row(self, rownum, memory):
        cdata = self.cdata
        cclk = self.cclk
        mask = (1<<rownum)
        col = 0
        while col < COLS:
            v = 1 if (memory[col] & mask) else 0
            cdata.value(v)
            cclk.on()
            cclk.off()
            # self.cdata.value(v)
            # self.clk_pulse()
            col = col + 1
