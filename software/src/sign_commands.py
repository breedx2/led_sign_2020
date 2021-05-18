import time
from sign import COLS
from sign_memory import clear_row
from sign_printer import SignPrinter

class SignCommands:
    def __init__(self, sign):
        self.sign = sign
        self.printer = SignPrinter(sign)

    # wipe screen clear from left at speed
    def clwipe(self, speed):
        sign = self.sign
        for i in range(0,COLS):
            sign.col(i, 0x00)
            time.sleep_ms(speed)

    # wipe screen clear from right at speed
    def crwipe(self, speed):
        sign = self.sign
        for i in range(COLS-1, -1, -1):
            sign.col(i, 0x00)
            time.sleep_ms(speed)

    # column-wise roll in down. clears sign first.
    def crid(self, str, speed):
        self._cri_x(str, speed,
            lambda: range(0, 7),
            lambda x: x << 1,
            lambda x: x + 1
        )

    # column-wise roll in up. clears sign first.
    def criu(self, str, speed):
        self._cri_x(str, speed,
            lambda: range(6, -1, -1),
            lambda x: x >> 1,
            lambda x: x + 0x40
        )

    # column-wise roll in, handles either direction. clears sign first.
    def _cri_x(self, str, speed, ranger, shifter, modifier):
        sign = self.sign
        sign.clear()
        msg_bytes = SignPrinter.to_byte_array(str)
        offset = int((COLS - len(msg_bytes))/2)
        for i,msgcol in enumerate(msg_bytes):
            col = offset + i
            inb = msg_bytes[i]
            if inb == 0:
                continue
            curb = 0
            for row in ranger():
                curb = shifter(curb)
                if inb & (1 << (6-row)):
                    curb = modifier(curb)
                sign.col(col, curb)
                time.sleep_ms(speed)

    def mwoo(self, speed):
        sign = self.sign
        half = int(COLS/2)+1
        for i in range(0, half):
            sign.col(half-i, 0)
            sign.col(half+i, 0)
            time.sleep_ms(speed)

    def mwoi(self, speed):
        sign = self.sign
        half = int(COLS/2)+1
        for i in range(0, half):
            sign.col(i, 0)
            sign.col(COLS-i, 0)
            time.sleep_ms(speed)

    # shift sign right num cols
    def sr(self, num, speed = 0):
        sign = self.sign
        for i in range(0, num):
            sign.shift_right()
            time.sleep_ms(speed)

    # shift sign left num cols
    def sl(self, num, speed = 0):
        sign = self.sign
        for i in range(0, num):
            sign.shift_left()
            time.sleep_ms(speed)

    # roll off down
    def rod(self, speed = 50):
        SignCommands._all_rows(lambda row: self.sign.roll_down(clear_row), speed)

    # roll off down
    def rou(self, speed = 50):
        SignCommands._all_rows(lambda row: self.sign.roll_up(clear_row), speed);

    # TODO: should take a full size col array here instead of string or ?
    def rid(self, str, speed = 50):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        for row in range(0, 7):
            sign.roll_down(clear_row)
            mask = 1 << (6 - row)
            for col in range(0, COLS-2):
                # print('col %d' % (col))
                if col < len(msg_bytes) and (msg_bytes[col] & mask):
                    sign.on(col+2, 0)
                else:
                    sign.off(col+2, 0)
            time.sleep_ms(speed)

    def _all_rows(fn, speed):
        for i in range(0, 7):
            fn(i)
            time.sleep_ms(speed)

    # counter - count up to num with speed
    def ctr(self, num, speed = 0):
        p = self.printer
        self.sign.clear()
        for i in range(0,num):
            p.center(str(i))
            time.sleep_ms(speed)
