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

    # counter - count up to num with speed
    def ctr(self, num, speed = 0):
        p = self.printer
        self.sign.clear()
        for i in range(0,num):
            p.center(str(i))
            time.sleep_ms(speed)

    # column roll in up (does this mean column-wise or all cols again?)
    def criu(self, str, speed):
        pass
