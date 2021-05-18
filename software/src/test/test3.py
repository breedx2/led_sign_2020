from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
import sign_memory
import time

mem = sign_memory.create()
sign = Sign(mem)
upd.start(mem)
p = SignPrinter(sign)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')

sc = SignCommands(sign)
# sc.criu('i am a real person!', 3)
# sc.mwoi(55)

time.sleep_ms(500)
sc.rod(150)
time.sleep_ms(500)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
time.sleep_ms(1000)
sc.rou(150)
