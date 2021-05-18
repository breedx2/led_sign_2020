
ROWBUFF_LEN = const(19)
def create():
    return [
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN)
    ]

def clear_row(row):
    for i in range(0, ROWBUFF_LEN):
        row[i] = 0x00
    return row
