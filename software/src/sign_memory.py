
ROWBUFF_LEN = const(19)

def create_frame():
    return bytearray(ROWBUFF_LEN * 7)

# allocates a temp chunk the size of a row
def create_temp_row():
    return bytearray(ROWBUFF_LEN)

def clear_row(buff, row_num):
    for i in range(0, ROWBUFF_LEN):
        buff[ROWBUFF_LEN * row_num + i] = 0x00
