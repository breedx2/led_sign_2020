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
        buff = SignPrinter.to_byte_array(msg)
        self._print(buff, 2) # first 2 columns are unaddressable

    def center(self, msg):
        buff = SignPrinter.to_byte_array(msg)
        index = max(0,int((COLS - len(buff)) / 2))
        self._print(buff, index)

    def right(self, msg):
        buff = SignPrinter.to_byte_array(msg)
        self._print(buff, COLS - len(buff))

    def _print(self, buff, index):
        self.sign.blit(index, buff)

    def to_byte_array(msg):
        buff = []
        for i,ch in enumerate(msg):
            glyph = font[ ord(ch) - ord(' ')]
            buff.extend(glyph)
            if(ch != ' ' and i < len(msg)-1):
                buff.append(0) # gap in between chars (kerning)
        return buff

    # Just like the above, but returns an array full sign width
    def to_byte_array_full(msg, align = 'center'):
        buff = SignPrinter.to_byte_array(msg)
        # TODO: Use the alignment
        delta = (COLS - len(buff))/2
        for i in range(0,delta):
            buff.insert(0, 0)
            buff.append(0)
        return buff
