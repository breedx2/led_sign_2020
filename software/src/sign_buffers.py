# implements the double buffering mechanism for the sign

from sign_memory import create_frame, ROWBUFF_LEN

class Buffers:

    def __init__(self, lock):
        cur = create_frame()
        off = create_frame()
        self.cur = cur
        self.off = off
        self.lock = lock
        # We prealloc these memorview objects because we cannot
        # allocate in the hot path (it causes GC blips)
        self.cur_rows = [
            memoryview(cur)[0*ROWBUFF_LEN:1*ROWBUFF_LEN],
            memoryview(cur)[1*ROWBUFF_LEN:2*ROWBUFF_LEN],
            memoryview(cur)[2*ROWBUFF_LEN:3*ROWBUFF_LEN],
            memoryview(cur)[3*ROWBUFF_LEN:4*ROWBUFF_LEN],
            memoryview(cur)[4*ROWBUFF_LEN:5*ROWBUFF_LEN],
            memoryview(cur)[5*ROWBUFF_LEN:6*ROWBUFF_LEN],
            memoryview(cur)[6*ROWBUFF_LEN:7*ROWBUFF_LEN],
        ]
        self.off_rows = [
            memoryview(off)[0*ROWBUFF_LEN:1*ROWBUFF_LEN],
            memoryview(off)[1*ROWBUFF_LEN:2*ROWBUFF_LEN],
            memoryview(off)[2*ROWBUFF_LEN:3*ROWBUFF_LEN],
            memoryview(off)[3*ROWBUFF_LEN:4*ROWBUFF_LEN],
            memoryview(off)[4*ROWBUFF_LEN:5*ROWBUFF_LEN],
            memoryview(off)[5*ROWBUFF_LEN:6*ROWBUFF_LEN],
            memoryview(off)[6*ROWBUFF_LEN:7*ROWBUFF_LEN],
        ]

    # Returns a pointer (memoryview) to the current rendered row
    def cur_row(self, rownum):
        return self.cur_rows[rownum]
    # Returns a pointer (memoryview) to the offscreen buffered row
    def off_row(self, rownum):
        return self.off_rows[rownum]

    # makes the current buffer point to the offscreen one
    # @micropython.native
    def flip(self):
        self.lock.acquire()

        tmp = self.cur
        self.cur = self.off
        self.off = tmp

        tmp = self.cur_rows
        self.cur_rows = self.off_rows
        self.off_rows = tmp

        # Copy all the current content into our new offscreen buffer
        # TODO: Consdier caching or making constants out of these numbers
        self.off[0:ROWBUFF_LEN*7] = self.cur[0:ROWBUFF_LEN*7]
        self.lock.release()
