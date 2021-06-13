from sign_memory import ROWBUFF_LEN, create_temp_row
from sign_buffers import Buffers
import time
import utime

COLS = const(145)

class Sign:
    """A low level memory representation of the sign"""

    def __init__(self, screen_buffers):
        self.sb = screen_buffers

    # @micropython.native
    def buffer_flip(self):
        self.sb.flip()

    @micropython.native
    def col(self, colnum, value):
        """sets an entire column value """
        rownum = 0
        realigned_col = colnum + 6
        # realigned_col = colnum
        # byteoff = self._col_to_index(realigned_col)
        byteoff = int(realigned_col/8)
        mask = (1 << realigned_col % 8)
        while rownum < 7:
            # row = self.get_row(rownum)
            # row = self.sb.off_row(rownum)
            row = self.sb.off_rows[rownum]
            if value & (1<<rownum):
                row[byteoff] = row[byteoff] | mask
            else:
                row[byteoff] = row[byteoff] & ~mask
            rownum = rownum + 1
        return self

    def get_col(self, colnum):
        rownum = 0
        result = 0
        realigned_col = colnum + 6
        byteoff = self._col_to_index(realigned_col)
        mask = (1 << realigned_col % 8)
        while rownum < 7:
            row = self.get_row(rownum)
            if row[byteoff] & mask:
                result = result | (1<<rownum)
            rownum = rownum + 1
        return result

    def get_row(self, row):
        return self.sb.off_row(row)

    def _col_to_index(self, col):
        # TODO: probably nudge/offset corrections
        # maybe this should return byte offset and bit index both?
        return int(col/8)

    # @micropython.native
    def blit(self, index, cols, len):
        """copies some columns in at an index"""
        off_rows = self.sb.off_rows
        i = 0
        while i < len and i + index < COLS:
            # start = utime.ticks_us()

            # self.col(index+i, cols[i])
            realigned_col = index + i + 6
            # realigned_col = colnum
            # byteoff = self._col_to_index(realigned_col)
            byteoff = int(realigned_col/8)
            mask = (1 << realigned_col % 8)
            value = cols[i]

            while rownum < 7:
                # row = self.get_row(rownum)
                # row = self.sb.off_row(rownum)
                row = off_rows[rownum]
                if value & (1<<rownum):
                    row[byteoff] = row[byteoff] | mask
                else:
                    row[byteoff] = row[byteoff] & ~mask
                rownum = rownum + 1




            # delta = utime.ticks_diff(utime.ticks_us(), start)
            # print('  col delta = {:6.3f}ms'.format(delta/1000))
            i = i + 1
        # for i,col in enumerate(cols):
        #     if (i >= len) or (i + index >= COLS):
        #         return self
        #     self.col(index+i, col)
        # return self


    # @micropython.native
    def blit2(self, index, cols, len):
        """copies some columns in at an index"""
        off_rows = self.sb.off_rows

        for rownum in range(0,7):
            row = off_rows[rownum]
            bytenum = int(index / 8)
            byte = 0x00 # TODO: Could nullify existing bits on either end but prevents a read
            # col_index = 0
            colmask = 1 << rownum
            while bytenum < ROWBUFF_LEN:
                for bit_index in range(0,8):
                    bitmask = 1 << bit_index
                    col_index = 8 * bytenum + bit_index

                    # print("row %d bytenum %d bit_index = %d col_index = %d" %(rownum, bytenum, bit_index, col_index))
                    col = cols[col_index] if col_index < len else 0x00
                    if col & colmask:
                        byte = byte | bitmask
                    else:
                        byte = byte & ~bitmask
                row[bytenum] = byte
                bytenum = bytenum + 1
            rownum = rownum + 1

    def on(self, col, rownum):
        """turns on a bit at col,row"""
        realigned_col = col + 6
        byteoff = self._col_to_index(realigned_col)
        row = self.get_row(rownum)
        mask = (1 << realigned_col % 8)
        row[byteoff] = row[byteoff] | mask
        return self

    def off(self, col, rownum):
        """turns off a bit at row,col"""
        realigned_col = col + 6
        byteoff = self._col_to_index(realigned_col)
        row = self.get_row(rownum)
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

    def all_on(self):
        self._do_for_every_byte(lambda i,r,v: 0xff)

    def all_off(self):
        self._do_for_every_byte(lambda i,r,v: 0x00)

    def _left_op(self, roll):
        def op(i,r,b):
            result = b >> 1
            if b & 0x01: # Low bit is set...
                nextindex = i-1
                if roll and (nextindex < 0):
                    nextindex = ROWBUFF_LEN - 1
                if nextindex >= 0:
                    row = self.get_row(r)
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
                    row = self.get_row(r)
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
        while(r < 7):
            row = self.get_row(r)
            rowop(r, row)
            r = r + 1
        return self

    def roll_down(self, first_row_fn = lambda bot: bot):
        mem = self.sb.off
        row6 = self.get_row(6)
        row5 = self.get_row(5)
        row4 = self.get_row(4)
        row3 = self.get_row(3)
        row2 = self.get_row(2)
        row1 = self.get_row(1)
        row0 = self.get_row(0)

        tmp = create_temp_row()
        tmp[0:ROWBUFF_LEN] = row6[0:ROWBUFF_LEN]

        row6[0:ROWBUFF_LEN] = row5[0:ROWBUFF_LEN]
        row5[0:ROWBUFF_LEN] = row4[0:ROWBUFF_LEN]
        row4[0:ROWBUFF_LEN] = row3[0:ROWBUFF_LEN]
        row3[0:ROWBUFF_LEN] = row2[0:ROWBUFF_LEN]
        row2[0:ROWBUFF_LEN] = row1[0:ROWBUFF_LEN]
        row1[0:ROWBUFF_LEN] = row0[0:ROWBUFF_LEN]
        row0[0:ROWBUFF_LEN] = first_row_fn(tmp)

    def roll_up(self, last_row_fn = lambda top: top):
        mem = self.sb.off
        row6 = self.get_row(6)
        row5 = self.get_row(5)
        row4 = self.get_row(4)
        row3 = self.get_row(3)
        row2 = self.get_row(2)
        row1 = self.get_row(1)
        row0 = self.get_row(0)

        tmp = create_temp_row()
        tmp[0:ROWBUFF_LEN] = row0[0:ROWBUFF_LEN]

        row0[0:ROWBUFF_LEN] = row1[0:ROWBUFF_LEN]
        row1[0:ROWBUFF_LEN] = row2[0:ROWBUFF_LEN]
        row2[0:ROWBUFF_LEN] = row3[0:ROWBUFF_LEN]
        row3[0:ROWBUFF_LEN] = row4[0:ROWBUFF_LEN]
        row4[0:ROWBUFF_LEN] = row5[0:ROWBUFF_LEN]
        row5[0:ROWBUFF_LEN] = row6[0:ROWBUFF_LEN]
        row6[0:ROWBUFF_LEN] = last_row_fn(tmp)
