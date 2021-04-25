
from font5x7 import font
from sign import COLS

class SignPrinter:
    """Writes basic static text messages to the sign memory"""
    def __init__(self, sign):
        self.sign = sign

    def clear(self):
        self.sign.clear()
        return self

    def left(self, msg):
        buff = self._buff(msg)
        self._print(buff, 0)

    def center(self, msg):
        buff = self._buff(msg)
        index = int((COLS - len(buff)) / 2)
        self._print(buff, index)

    def right(self, msg):
        buff = self._buff(msg)
        self._print(buff, COLS - len(buff))

    def _print(self, buff, index):
        self.sign.blit(index, buff)

    def _buff(self, msg):
        buff = []
        for ch in msg:
            glyph = font[ ord(ch) - ord(' ')]
            buff.extend(glyph)
            buff.append(0)
        return buff
