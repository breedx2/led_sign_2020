import time
import binascii
from micropython_lib_random import shuffle
from sign import COLS
from sign_memory import clear_row, ROWBUFF_LEN
from sign_printer import SignPrinter
from font5x7 import font

class SignCommands:
    def __init__(self, sign):
        self.sign = sign
        self.printer = SignPrinter(sign)

    def center(self, str):
        self.printer.center(str)

    def left(self, str):
        self.printer.left(str)

    def right(self, str):
        self.printer.right(str)

    def clear(self):
        self.sign.clear()

    def invert(self):
        self.sign.invert()

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

    # returns a hex containing the raw sign memory
    def dump(self):
        result = bytearray(7*ROWBUFF_LEN)
        sign = self.sign
        for rownum in range(0, 7):
            row = sign  .get_row(rownum)
            offset = ROWBUFF_LEN*rownum
            result[offset:offset+ROWBUFF_LEN] = row
        return binascii.hexlify(result).decode('ascii')

    # char-wise roll in up at speed.
    def kriu(self, str, speed = 35):
        self._roll_chars(str, speed, lambda col,row: col << (6-row))

    # char-wise roll in down at speed.
    def krid(self, str, speed = 35):
        self._roll_chars(str, speed, lambda col,row: col >> (6-row))

    # char-wise roll out down at speed
    def krod(self, str, speed = 35):
        self.printer.center(str)
        self._roll_chars(str, speed, lambda col,row: col << (row+1))

    # char-wise roll out down at speed
    def krou(self, str, speed = 35):
        self.printer.center(str)
        self._roll_chars(str, speed, lambda col,row: col >> (row+1))

    # Char-wise column roller.
    # TODO: add alignment, this currently assumes center
    def _roll_chars(self, str, speed, colmaker):
        sign = self.sign
        buff = SignPrinter.to_byte_array(str)
        bufflen = len(buff)
        offset = max(0,int((COLS - len(buff)) / 2))
        for ch in str:
            glyph = font[ ord(ch) - ord(' ')]
            if ch is not ' ':
                for row in range(0, 7):
                    for glyphcol,colvalue in enumerate(glyph):
                        sign.col(offset+glyphcol, colmaker(colvalue,row))
                    time.sleep_ms(speed)
                offset = offset + 1
            offset = offset + len(glyph)

    # lazer scanner baby, cheese city
    # poorly inspired by the "TANNING INVITATIONAL" pool party lazer text in real genius
    def lazr(self, str):
        sign = self.sign
        sign.clear()
        buff = SignPrinter.to_byte_array(str)
        bufflen = len(buff)
        offset = max(0,int((COLS - len(buff)) / 2))
        def swipe_pass(speed):
            h = int(bufflen/2)
            for i in range(0,h):
                sign.col(offset+i, buff[i])
                sign.col(offset+i+h, buff[i+h] ^ 0xFF)
                sign.col(offset+bufflen-1-i, buff[bufflen-1-i])
                sign.col(offset+bufflen-1-h-i, buff[bufflen-1-h-i] ^ 0xFF)
                time.sleep_ms(speed)
                sign.col(offset+i, 0)
                sign.col(offset+i+h, 0)
                sign.col(offset+bufflen-1-i, 0)
                sign.col(offset+bufflen-1-h-i, 0)
        for t in [7,7,5,5,5,3,3,2,2,1]:
            swipe_pass(t)
        for i in [2, 1]:
            for j in range(0,4):
                self.printer.center(str)
                time.sleep_ms(13*i)
                self.printer.clear()
                time.sleep_ms(13*i)
        self.printer.center(str)

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

    # message shift in left (from the right)
    def msl(self, str, speed = 35):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        for col in msg_bytes:
            sign.shift_left()
            sign.col(COLS-1, col)
            time.sleep_ms(speed)
        for x in range(0, COLS):
            sign.shift_left()
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

    # random dissolve (fade out)
    # basically just transition to a blank screen!
    def rando(self, speed = 10):
        self.randt("", speed)

    # random in (fade in).  Clears sign first.
    def randi(self, str, speed = 10):
        self.sign.clear()
        self.randt(str, speed)

    # random transition (fade in)
    def randt(self, str, speed = 10):
        sign = self.sign
        msg_bytes = SignPrinter.to_byte_array_full(str)
        remaining = []
        for i in range(0, COLS):
            cur_col = sign.get_col(i)
            new_col = msg_bytes[i]
            for j in range(0, 7):
                bm = (1 << j)
                if (cur_col & bm) and not (new_col & bm):
                    remaining.append([i,j,0])
                if (new_col & bm) and not (cur_col & bm):
                    remaining.append([i,j,1])
        shuffle(remaining)
        for item in remaining:
            if(item[2]):
                sign.on(item[0], item[1])
            else:
                sign.off(item[0], item[1])
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
