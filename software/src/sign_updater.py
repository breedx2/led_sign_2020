from machine import Pin, SPI, Timer
import time
import utime
import sign_hardware as hw
import sign_memory

# Responsible for continuously refreshing the sign

# 25 fps = 40ms/frame => 40/7 => 5.xx ms
# ROW_SLEEP_MS = 5

_lock = None
_rownum = 0
_rowtimer = Timer(0)

def start(sign_buffer, lock):
    global _rowtimer
    global _sb
    global _lock
    _sb = sign_buffer
    _lock = lock
    hw.enable_output()
    _rowtimer.init(period=1, mode=Timer.PERIODIC, callback=_row_cb)

def stop():
    global _rowtimer
    _rowtimer.deinit()

@micropython.native
def _row_cb(timer):
    global _rownum
    # global _lock
    # if(_lock.locked()):
    #     return
    hw.row_off(_rownum)
    _rownum = 0 if _rownum == 6 else _rownum + 1
    hw.shift_row(_sb.cur_row(_rownum))
    hw.row_on(_rownum)
