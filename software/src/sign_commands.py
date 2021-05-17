import time
from sign import COLS
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
            for row in range(0, 7):
                curb = (curb << 1)
                if inb & ( 1 << (6-row)):
                    curb = curb + 1
                sign.col(col, curb)
                time.sleep_ms(speed)

    # column-wise roll in up. clears sign first.
    def criu(self, str, speed):
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
            for row in range(6, -1, -1):
                curb = (curb >> 1)
                if inb & (1<< (6-row)):
                    curb = curb + 0x40
                sign.col(col, curb)
                time.sleep_ms(speed)

    # counter - count up to num with speed
    def ctr(self, num, speed = 0):
        p = self.printer
        self.sign.clear()
        for i in range(0,num):
            p.center(str(i))
            time.sleep_ms(speed)
