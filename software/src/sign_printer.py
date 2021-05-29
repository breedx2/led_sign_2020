from font5x7 import glyph
from sign import COLS

class SignPrinter:
    """Writes basic static text messages to the sign memory"""
    def __init__(self, sign):
        self.sign = sign
        self.screen_buff = bytearray(COLS)

    def clear(self):
        self.sign.clear()
        return self

    def left(self, msg):
        buff = self.screen_buff
        len = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - len) / 2))
        self.sign.blit(2, buff, len) # first 2 columns are unaddressable

    def center(self, msg):
        buff = self.screen_buff
        len = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - len) / 2))
        self.sign.blit(index, buff, len)

    def right(self, msg):
        buff = self.screen_buff
        len = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - len) / 2))
        self.sign.blit(COLS-len, buff, len) # first 2 columns are unaddressable

    def char_at_pos(self, ch, pos):
        glyph_cols = glyph(ch)
        self.sign.blit(pos, glyph_cols, len(glyph_cols))

    def _print(self, buff, index, len):
        self.sign.blit(index, buff, len)

    # writes the given message to the buff.
    # assumes that the buff is large enough to hold it
    def write_byte_array(msg, buff):
        offset = 0
        for i,ch in enumerate(msg):
            glyph_cols = glyph(ch)
            glyph_len = len(glyph_cols)
            buff[offset:offset+glyph_len] = glyph_cols
            offset = offset + glyph_len
            if(ch != ' ' and i < len(msg)-1):
                buff[offset] = 0x00
                offset = offset + 1
            if(offset >= len(buff)):
                return len(buff)
        return offset

    # deprecated! this allocates memory, use the other one
    def to_byte_array(msg):
        buff = []
        for i,ch in enumerate(msg):
            glyph_cols = glyph(ch)
            buff.extend(glyph_cols)
            if(ch != ' ' and i < len(msg)-1):
                buff.append(0) # gap in between chars (kerning)
        return buff

    # experiment to see if bytearray is better than extending array
    # def to_byte_array2(msg):
    #     buff = bytearray((6*len(msg))-1) # 5-byte char glyphs plus space between
    #     offset = 0
    #     for i,ch in enumerate(msg):
    #         glyph = font[ ord(ch) - ord(' ')]
    #         for col in glyph:
    #             buff[offset] = col
    #             offset = offset + 1
    #         if(ch != ' ' and i < len(msg)-1):
    #             buff[offset] = 0 # gap in between chars (kerning)
    #             offset = offset + 1
    #     return buff

    # Just like the above, but returns an array full sign width
    def to_byte_array_full(msg, align = 'center'):
        buff = SignPrinter.to_byte_array(msg)
        # TODO: Use the alignment
        delta = (COLS - len(buff))/2
        for i in range(0,delta):
            buff.insert(0, 0)
            buff.append(0)
        return buff
