
from machine import Pin, SPI, SoftSPI, Timer
import time
import utime

# Responsible for continuously refreshing the sign

# 25 fps = 40ms/frame => 40/7 => 5.xx ms
# ROW_SLEEP_MS = 5

class SignUpdater:

    def __init__(self, hw, memory):
        self.hw = hw
        self.mem = memory
        self.rownum = 0
        self.rowtimer = 0

    def start(self):
        self.hw.enable_output()
        self.rowtimer = Timer(0);
        self.rowtimer.init(period=1, mode=Timer.PERIODIC, callback=self.row_cb)

    def stop(self):
        self.rowtimer.deinit()

    @micropython.native
    def row_cb(self, timer):
        hw = self.hw
        hw.row_off(self.rownum)
        self.rownum = 0 if self.rownum == 6 else self.rownum + 1
        hw.shift_row(self.rownum, self.mem)
        hw.row_on(self.rownum)
