from machine import Pin, SPI, SoftSPI, Timer
import time

# pin mappings
EN    = const(21)
CDATA = const(22)
CCLK  = const(23)
BS_IN = const(34)
C1    = const(12)
C2    = const(13)
C3    = const(14)
C4    = const(15)
C5    = const(16)
C6    = const(17)
C7    = const(18)

# COLS = const(145)

class SignHardware:
    """Sign hardware abstraction"""

    def __init__(self):
        # self.spi = SoftSPI(baudrate=100000, polarity=1, phase=0, sck=Pin(CCLK), mosi=Pin(CDATA), miso=Pin(BS_IN))
        self.spi = SPI(1, baudrate=5000000, polarity=1, phase=0, bits=8, firstbit=SPI.LSB, sck=Pin(CCLK), mosi=Pin(CDATA))
        # self.spi = SPI(1, baudrate=1000000, polarity=1, phase=0, bits=8, firstbit=SPI.LSB, sck=Pin(CCLK), mosi=Pin(CDATA))
        self.en = Pin(EN, Pin.OUT, value=0)
        self.rows = [
            Pin(C1, Pin.OUT, value=0),
            Pin(C2, Pin.OUT, value=0),
            Pin(C3, Pin.OUT, value=0),
            Pin(C4, Pin.OUT, value=0),
            Pin(C5, Pin.OUT, value=0),
            Pin(C6, Pin.OUT, value=0),
            Pin(C7, Pin.OUT, value=0)
        ]

    def enable_output(self):
        self.en.on()

    def disable_output(self):
        self.en.off()

    @micropython.native
    def row_on(self, num):
        self.rows[num].on()

    @micropython.native
    def row_off(self, num):
        self.rows[num].off()

    def all_rows_off(self):
        for row in self.rows:
            row.off()

    @micropython.native
    def shift_row(self, rownum, memory):
        self.spi.write(memory[rownum])

    # @micropython.native
    # def clear_rowbuff(self):
    #     i = 0
    #     while i < ROWBUFF_LEN:
    #         rowbuff[i] = 0x00
    #         i = i + 1
    #
    # @micropython.native
    # def recompute_rowbuff(self, rownum, memory):
    #     self.clear_rowbuff()
    #     col = COLS - 1
    #     mask = (1 << rownum)
    #     while col >= 0:
    #         bit_value = 1 if (memory[col] & mask) else 0
    #         realigned_col = col + 6
    #         i = int(realigned_col / 8)
    #         if(bit_value):
    #             bit_num = (realigned_col % 8) # firstbit LSB
    #             rowbuff[i] = rowbuff[i] | (1 << bit_num)
    #         # print("col = %d, mask = 0x%02x, bit_value = %d, i = %d, bit_num = %d, rowbuff[i] = 0x%02x" %(col, mask, bit_value, i, bit_num, rowbuff[i]))
    #         col = col - 1
