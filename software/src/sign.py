
class Sign:
    """A low level memory representation of the sign"""

    COLS = 145

    def __init__(self, memory = [0x00] * Sign.COLS):
        # byte per column
        self.memory = memory

    def col(self, index, value):
        """sets an entire column value """
        self.memory[index] = value
        return self

    def blit(self, index, cols):
        """copies some columns in at an index"""
        for i,col in enumerate(cols):
            self.col(index+i, col)
        return self

    def on(self, col, row):
        """turns on a bit at col,row"""
        self.memory[col] = self.memory[col] | (1<<row)
        return self

    def off(self, col, row):
        """turns off a bit at row,col"""
        self.memory[col] = self.memory[col] & ~(1<<row)
        return self

    def clear(self):
        self.memory = [0x00] * Sign.COLS
        return self

    def invert(self):
        self.memory = list(map(lambda x: x ^ 0xFF, self.memory))
        return self

    def rot_left(self):
        self.memory.append(self.memory.pop(0))
        return self

    def rot_right(self):
        self.memory.insert(0, self.memory.pop(len(self.memory)-1))
        return self

    def roll_down(self):
        self.memory = list(map(self._bitrot_left, self.memory))
        return self

    def roll_up(self):
        self.memory = list(map(self._bitrot_right, self.memory))
        return self

    def _bitrot_left(self, x):
        b = 1 if (x & 0b01000000 == 0b01000000) else 0
        return ((x << 1) + b) & 0x7F

    def _bitrot_right(self, x):
        b = 0b01000000 if (x & 0b00000001 == 0b00000001) else 0
        return ((x >> 1) | b) & 0x7F

    def print(self):
        for row in range(0,7):
            r = self._buildPrintRow(row)
            print(r)

    def _buildPrintRow(self, row):
        r = ''
        for col in range(0, Sign.COLS):
            ch = ' '
            if(self.memory[col] & (1<<row)):
                ch = '*'
            r = r + ch
        return r
