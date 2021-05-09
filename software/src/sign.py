from sign_memory import create_memory, ROWBUFF_LEN

COLS = const(145)

class Sign:
    """A low level memory representation of the sign"""

    def __init__(self, memory = create_memory()):
        # byte per column
        self.memory = memory

    @micropython.native
    def col(self, colnum, value):
        """sets an entire column value """
        rownum = 0
        realigned_col = colnum + 6
        byteoff = self._col_to_index(realigned_col)
        # print("byteoff => %d" % ( byteoff))
        mask = (1 << realigned_col % 8)
        # print("mask = %s" %(hex(mask)))
        rows = self.memory
        while rownum < 7:
            row = rows[rownum]
            # print("before => %s" %(hex(row[byteoff])))
            # print("value & mask : %s" %(hex(value & mask)));
            if value & (1<<rownum):
                row[byteoff] = row[byteoff] | mask
            else:
                row[byteoff] = row[byteoff] & ~mask
            # print("after => %s" %(hex(row[byteoff])))
            rownum = rownum + 1
        return self

    @micropython.native
    def _col_to_index(self, col):
        # TODO: probably nudge/offset corrections
        # maybe this should return byte offset and bit index both?
        return int(col/8)

    def blit(self, index, cols):
        """copies some columns in at an index"""
        for i,col in enumerate(cols):
            self.col(index+i, col)
        return self

    def on(self, col, rownum):
        """turns on a bit at col,row"""
        realigned_col = col + 6
        byteoff = self._col_to_index(realigned_col)
        row = self.memory[rownum]
        mask = (1 << realigned_col % 8)
        row[byteoff] = row[byteoff] | mask
        return self

    def off(self, col, rownum):
        """turns off a bit at row,col"""
        realigned_col = col + 6
        byteoff = self._col_to_index(realigned_col)
        row = self.memory[rownum]
        mask = ~(1 << realigned_col % 8)
        row[byteoff] = row[byteoff] & mask
        return self

    def clear(self):
        return self._do_for_every_byte(lambda i,r,b: 0x00)

    def invert(self):
        return self._do_for_every_byte(lambda i,r,b: b ^ 0xFF)

    def rot_right(self):
        op = self._right_op(True)
        return self._do_for_every_byte_backwards(op)

    def shift_right(self):
        op = self._right_op(False)
        return self._do_for_every_byte_backwards(op)

    def rot_left(self):
        op = self._left_op(True)
        return self._do_for_every_byte(op)

    def shift_left(self):
        op = self._left_op(False)
        return self._do_for_every_byte(op)

    def _left_op(self, roll):
        def op(i,r,b):
            result = b >> 1
            if b & 0x01: # Low bit is set...
                nextindex = i-1
                if roll and (nextindex < 0):
                    nextindex = ROWBUFF_LEN - 1
                if nextindex >= 0:
                    row = self.memory[r]
                    row[nextindex] = row[nextindex] | 0x80
            return result
        return op

    def _right_op(self, roll):
        def op(i,r,b):
            result = b << 1
            if b & 0x80: # High bit is set...
                nextindex = i+1
                if roll and (nextindex == ROWBUFF_LEN):
                    nextindex = 0
                if nextindex < ROWBUFF_LEN:
                    row = self.memory[r]
                    row[nextindex] = row[nextindex] | 0x01
            return result
        return op


    def _do_for_every_byte(self, op):
        def rowop(r, row):
            i = 0
            while(i < ROWBUFF_LEN):
                row[i] = op(i, r, row[i])
                i = i + 1
        return self._do_for_every_row(rowop)

    def _do_for_every_byte_backwards(self, op):
        def rowop(r, row):
            i = ROWBUFF_LEN - 1
            while(i >= 0):
                row[i] = op(i, r, row[i])
                i = i - 1
        return self._do_for_every_row(rowop)

    def _do_for_every_row(self, rowop):
        r = 0
        memory = self.memory
        while(r < 7):
            row = memory[r]
            rowop(r, row)
            r = r + 1
        return self

    def roll_down(self):
        mem = self.memory
        b = mem[6]
        mem[6] = mem[5]
        mem[5] = mem[4]
        mem[4] = mem[3]
        mem[3] = mem[2]
        mem[2] = mem[1]
        mem[1] = mem[0]
        mem[0] = b

    def roll_up(self):
        mem = self.memory
        b = mem[0]
        mem[0] = mem[1]
        mem[1] = mem[2]
        mem[2] = mem[3]
        mem[3] = mem[4]
        mem[4] = mem[5]
        mem[5] = mem[6]
        mem[6] = b
