from sign import Sign, COLS
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
import sign_memory
from sign_buffers import Buffers
import _thread

lock = _thread.allocate_lock()
sb = Buffers(lock)
sign = Sign(sb)
upd.start(sb, lock)
p = SignPrinter(sign)

sc = SignCommands(sign)
sc.clear()

buff = bytearray(COLS)
# SignPrinter.write_byte_array('Sat Jan 01 00:05:00', buff)
# sign.blit2(0, buff, COLS)
# sb.flip()
sc.time(60)
