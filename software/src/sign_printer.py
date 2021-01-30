
from font5x7 import font

class SignPrinter:
    """Writes basic static text messages to the sign"""
    def __init__(self, sign):
        self.sign = sign

    def print(self, msg):
        buff = []
        for ch in msg:
            glyph = font[ ord(ch) - ord(' ')]
            buff.extend(glyph)
            buff.append(0)
        self.sign.blit(0, buff)
