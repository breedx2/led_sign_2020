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

time.sleep_ms(250)
sc.rod(25)
time.sleep_ms(50)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
time.sleep_ms(250)
sc.rou(25)
time.sleep_ms(150)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
time.sleep_ms(250)
sc.rid("scum sucking depravity!!", 50)
time.sleep_ms(250)
sc.rid("SOME CANDY", 50)
time.sleep_ms(500)
sc.riu("SOME OTHER CANDY", 50)
time.sleep_ms(250)
sc.riu("//////^^^^^ gott ^^^^^^^", 50)
time.sleep_ms(500)
sc.mwc("a bundle of peeled eggs in burlap weighs twice as much as molten metals or 3 times as much as anxiety", 150)
sc.mwoi(50)
