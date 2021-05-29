from font5x7 import glyph
from sign import COLS

class SignPrinter:
    """Writes basic static text messages to the sign memory"""
    def __init__(self, sign):
        self.sign = sign
        self.screen_buff = bytearray(COLS)
        self.tmp_screen_buff = bytearray(COLS)

    def clear(self):
        self.sign.clear()
        return self

    def left(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(2, buff, msglen) # first 2 columns are unaddressable

    def center(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(index, buff, msglen)

    def right(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(COLS-len, buff, msglen) # first 2 columns are unaddressable

    def char_at_pos(self, ch, pos):
        glyph_cols = glyph(ch)
        self.sign.blit(pos, glyph_cols, len(glyph_cols))

    def _print(self, buff, index, len):
        self.sign.blit(index, buff, len)

    # writes the given message to the buff.
    # assumes that the buff is large enough to hold it
    def write_byte_array(msg, buff):
        offset = 0
        bufflen = len(buff)
        for i,ch in enumerate(msg):
            glyph_cols = glyph(ch)
            glyph_len = len(glyph_cols)
            buff[offset:offset+glyph_len] = glyph_cols
            offset = offset + glyph_len
            if(ch != ' ' and i < len(msg)-1 and offset < bufflen):
                buff[offset] = 0x00
                offset = offset + 1
            if(offset >= bufflen):
                return bufflen
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

    # Just like the above, but returns an array full sign width
    # deprecated, use the below
    def to_byte_array_full(msg, align = 'center'):
        buff = SignPrinter.to_byte_array(msg)
        # TODO: Use the alignment
        delta = (COLS - len(buff))/2
        for i in range(0,delta):
            buff.insert(0, 0)
            buff.append(0)
        return buff

    # Fills a buffer that's full sign width with the message
    # Returns the actual inner content length, not the buffer length
    # TODO: Use alignment
    def fill_signbuff(self, msg, buff, align = 'center'):
        for i in range(0, len(buff)):
            buff[i] = 0x00
        tmpbuff = self.tmp_screen_buff
        msglen = SignPrinter.write_byte_array(msg, tmpbuff)
        # TODO: Use the alignment
        offset = int((COLS - msglen)/2)
        buff[offset:offset+msglen] = tmpbuff[0:msglen]
        return msglen
