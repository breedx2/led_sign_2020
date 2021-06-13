import utime

DAYS = ['Mon', 'Tue', 'Wed', 'Thr', 'Fri', 'Sat', 'Sun']
MONS = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']

# Returns a string formatted with the current date/time
@micropython.native # probably not required, didn't help
def asctime():
    t = utime.localtime()
    dow = DAYS[t[6]]
    mon = MONS[t[2]-1]
    return "%s %s %02d %02d:%02d:%02d" % (dow, mon, t[2], t[3], t[4], t[5])

# Fills a buffer with a string formatted with the current date/time
# but without using string formatting or concat.
# Data is columnar
@micropython.native
def asctime2(buff):
    # length = 6*len('Sun Jan 01 00:00:00')-3
    # buff = bytearray(length)
    t = utime.localtime()
    dow = DAYS[t[6]]
    mon = MONS[t[2]-1]
    offset = 0
    offset = quick_print(buff, dow, offset)
    offset = quick_print(buff, ' ', offset)
    offset = quick_print(buff, mon, offset)
    offset = quick_print(buff, ' ', offset)
    offset = quick_2digit(buff, t[2], offset)
    offset = quick_print(buff, ' ', offset)
    offset = quick_2digit(buff, t[3], offset)
    offset = quick_print(buff, ':', offset)
    offset = quick_2digit(buff, t[4], offset)
    offset = quick_print(buff, ':', offset)
    offset = quick_2digit(buff, t[5], offset)
    return offset

import font5x7 as font
# print the str into the buff at offset
def quick_print(buff, str, offset):
    for i,ch in enumerate(str):
        g = font.glyph(ch)
        glyphlen = len(g)
        buff[offset:offset+glyphlen] = g
        offset = offset + glyphlen
        if(ch != ' ' and i < len(str)-1):
            buff[offset] = 0x00
            offset = offset + 1
    return offset

# prints a 2-digit number at offset
def quick_2digit(buff, num, offset):
    g = font.digit(int(num/10))
    glyphlen = len(g)
    buff[offset:offset+glyphlen] = g
    offset = offset + glyphlen + 1

    g = font.digit(num%10)
    glyphlen = len(g)
    buff[offset:offset+glyphlen] = g
    offset = offset + glyphlen
    return offset + 1
