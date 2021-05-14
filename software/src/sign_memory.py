
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
