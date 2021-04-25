
from machine import Timer
import time

# Responsible for continuously refreshing the sign

# 25 fps = 40ms/frame => 40/7 => 5.xx ms
# ROW_SLEEP_MS = 5

class SignUpdater:

    def __init__(self, hw, memory):
        self.hw = hw
        self.mem = memory
        self.rownum = 0
        self.rowtimer = 0

    def xstart(self):
        self.hw.enable_output()
        self.rowtimer = Timer(0);
        self.rowtimer.init(period=5, mode=Timer.PERIODIC, callback=self.row_cb)

    @micropython.native
    def start(self):
        hw = self.hw
        mem = self.mem
        rownum = 0
        hw.enable_output()
        hw.all_rows_off()
        while(True):
            hw.shift_row(rownum, mem)
            hw.row_on(rownum)
            time.sleep_ms(5)
            hw.row_off(rownum)
            rownum = 0 if rownum == 6 else rownum + 1

    def stop(self):
        self.rowtimer.deinit()

    def row_cb(self, timer):
        self.hw.all_rows_off()
        self.hw.shift_row(self.rownum, self.mem)

        self.hw.row_on(self.rownum)
        # EEK might need to do another timer here?
        # time.sleep_ms(100)
        # self.hw.row_off(self.rownum)
        self.rownum = 0 if self.rownum == 6 else self.rownum + 1
