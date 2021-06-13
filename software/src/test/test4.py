from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
import sign_memory
import time
from font5x7 import digit
import datetime

mem = sign_memory.create_frame()
sign = Sign(mem)
upd.start(mem)

sc = SignCommands(sign)
sc.clear()
# sc.center('THIS IS SOME LONG CONTENT')

# x = SignPrinter.to_byte_array('LONG CONTENT XX')
# sign.blit(10, x)
# offset = len('LONG CONTENT ')*6-2
length = 6*len('Sun Jan 01 00:00:00')-3
buff = bytearray(length)
for i in range(0,15):
    # SignPrinter.to_byte_array2('this thing %d' % (i))
    # x = 'this thing %d' % (i))
    # print('doing asctime %i'%(i))

    # datetime.asctime2(buff)
    # if(i % 5 == 0):
    #     sign.blit(10, buff)
    sc.center('THIS IS A TEST')

    # x[offset:offset+5] = bytearray(digit(int(i/10)))
    # x[offset+6:offset+11] = bytearray(digit(i%10))

    # sign.blit(10, x)
    time.sleep(1)
    # sign.col(90, 0x00)
    # time.sleep(1)
