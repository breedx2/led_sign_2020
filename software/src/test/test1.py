from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
import sign_updater as upd
from sign_memory import create_memory

mem = create_memory()
sign = Sign(mem)
upd.start(mem)
p = SignPrinter(sign)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
