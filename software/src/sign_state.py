
COLS = 145

class SignState:
    """A low level representation of the sign state"""

    def __init__(self):
        # byte per column
        self.memory = [0x00] * COLS

    def col(self, index, value):
        self.memory[index] = value

    def on(self, row, col):
        """turns on a bit at row,col"""
        self.memory[col] = self.memory[col] | (1<<row)

    def off(self, row, col):
        """turns off a bit at row,col"""
        self.memory[col] = self.memory[col] & ~(1<<row)

    def clear(self):
        self.memory = [0x00] * COLS

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
