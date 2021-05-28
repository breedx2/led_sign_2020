from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
import sign_memory

mem = sign_memory.create()
sign = Sign(mem)
upd.start(mem)
# p = SignPrinter(sign)
# p.left('ABCDEFGHIJKLMNOPQRSTUVWX')

sc = SignCommands(sign)
sc.clear()
# sc.center('hello')
# sc.dump()
sc.lazr('TANNING INVITATIONAL')
