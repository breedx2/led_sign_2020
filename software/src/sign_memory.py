
ROWBUFF_LEN = const(19)
def create_memory():
    return [
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN),
        bytearray(ROWBUFF_LEN)
    ]
