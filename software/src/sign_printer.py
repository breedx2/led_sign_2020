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
        self.sign.buffer_flip()
        return self

    def left(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(2, buff, msglen) # first 2 columns are unaddressable
        self.sign.buffer_flip()

    def center(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(index, buff, msglen)
        self.sign.buffer_flip()
        
    @micropython.native
    def center2(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array2(msg, buff)
        # index = max(0,int((COLS - msglen) / 2))
        # self.sign.blit(index, buff, msglen)
        self.sign.buffer_flip()

    def right(self, msg):
        buff = self.screen_buff
        msglen = SignPrinter.write_byte_array(msg, buff)
        index = max(0,int((COLS - msglen) / 2))
        self.sign.blit(COLS-msglen, buff, msglen) # first 2 columns are unaddressable
        self.sign.buffer_flip()

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
            if(ch == ' '):
                offset = offset - 1
            if(offset >= bufflen):
                return bufflen
        return offset
    def write_byte_array2(msg, buff):
        msglen = len(msg)
        for i in range(0, msglen):
            # ch = 'a'
            # pass
            ch = msg[i]
            # glyph_cols = glyph(msg[i])
        # for i,ch in enumerate(msg):
        #     pass
        return 0

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
