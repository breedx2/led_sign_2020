
COLS = 145

class Sign:
    """A low level memory representation of the sign"""

    def __init__(self):
        # byte per column
        self.memory = [0x00] * COLS

    def col(self, index, value):
        """sets an entire column value """
        self.memory[index] = value
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
        self.memory = [0x00] * COLS
        return self

    def invert(self):
        self.memory = list(map(lambda x: x ^ 0xFF, self.memory))
        return self

    def rot_left(self):
        self.memory.insert(0, self.memory.pop(len(self.memory)-1))
        return self

    def rot_right(self):
        self.memory.append(self.memory.pop(0))
        return self

    def roll_down(self):
        pass

    def roll_up(self):
        pass

    def print(self):
        for row in range(0,7):
            r = self._buildPrintRow(row)
            print(r)

    def _buildPrintRow(self, row):
        r = ''
        for col in range(COLS-1,-1,-1):
            ch = ' '
            if(self.memory[col] & (1<<row)):
                ch = '*'
            r = r + ch
        return r
