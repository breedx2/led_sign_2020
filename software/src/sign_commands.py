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
    def crid(self, str, speed, direction = 'left'):
        self._cri_x(str, speed,
            lambda: range(0, 7),
            lambda x: x << 1,
            lambda x: x + 1,
            direction
        )

    # column-wise roll in up. clears sign first.
    def criu(self, str, speed, direction = 'left'):
        self._cri_x(str, speed,
            lambda: range(6, -1, -1),
            lambda x: x >> 1,
            lambda x: x + 0x40,
            direction
        )

    # column-wise roll in, handles either direction. clears sign first.
    def _cri_x(self, str, speed, ranger, shifter, modifier, direction):
        sign = self.sign
        sign.clear()
        msg_bytes = SignPrinter.to_byte_array(str)
        offset = int((COLS - len(msg_bytes))/2)
        multiplier = 1
        if direction == 'right':
            offset = COLS - offset
            multiplier = -1
            msg_bytes.reverse()
        for i,msgcol in enumerate(msg_bytes):
            col = offset + multiplier * i
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

    # column-wise wipe in message from left
    def lwipe(self, str, speed):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        for i in range(0, COLS-1):
            sign.col(i+1, msg_bytes[i])
            time.sleep_ms(speed)

    # column-wise wipe in message from right
    def rwipe(self, str, speed):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        for i in range(COLS-1, -1, -1):
            sign.col(i+1, msg_bytes[i])
            time.sleep_ms(speed)

    def mwoo(self, speed):
        sign = self.sign
        half = int(COLS/2)+1
        for i in range(0, half):
            sign.col(half-i, 0)
            sign.col(half+i, 0)
            time.sleep_ms(speed)

    # message wipe out in
    def mwoi(self, speed):
        sign = self.sign
        start = 2
        end = COLS-1
        while sign.get_col(start) == 0 and start < end:
            start = start + 1
        while sign.get_col(end) == 0 and end > start:
            end = end - 1
        while(start <= end):
            sign.col(start, 0)
            sign.col(end, 0)
            start = start + 1
            end = end - 1
            time.sleep_ms(speed)

    # shift sign right num cols
    def sr(self, num, speed = 0):
        sign = self.sign
        for i in range(0, num):
            sign.shift_right()
            time.sleep_ms(speed)

    # shift in a byte from the left
    def sil(self, byte_val):
        sign = self.sign
        sign.shift_right()
        sign.col(2, byte_val)

    # shift in a byte from the right
    def sir(self, byte_val):
        sign = self.sign
        sign.shift_left()
        sign.col(144, byte_val)

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

    # roll message in upwards
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

    # roll message in upwards
    def riu(self, str, speed = 50):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        for row in range(6, -1, -1):
            sign.roll_up(clear_row)
            mask = 1 << ( 6 - row)
            for col in range(0, COLS-2):
                # print('col %d' % (col))
                if col < len(msg_bytes) and (msg_bytes[col] & mask):
                    sign.on(col+2, 6)
                else:
                    sign.off(col+2, 6)
            time.sleep_ms(speed)

    def strobe(self, speed, times):
        sign = self.sign
        for i in range(0, times):
            sign.all_on()
            time.sleep_ms(speed)
            sign.all_off()
            time.sleep_ms(speed)

    # display message word-wise in center of display
    def mwc(self, str, speed = 50):
        printer = self.printer
        input_length = len(str)
        start = 0
        next = 0
        while(next <= input_length):
            if next >= input_length or str[next] == ' ':
                word = str[start:next]
                printer.clear()
                printer.center(word)
                time.sleep_ms(speed)
                start = next + 1
            next = next + 1

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
