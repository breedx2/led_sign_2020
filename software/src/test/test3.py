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

sc = SignCommands(sign)

# sc.mwoi(55)
sc.criu('...STARTING TEST...', 5)
time.sleep_ms(250)
sc.criu("LET'S GO!", 25, 'right')
time.sleep_ms(500)
sc.ctr(150)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
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
sc.riu('//////\\\\\\\\\\\\', 50)
time.sleep_ms(500)
sc.mwc("a bundle of peeled eggs in burlap weighs twice as much as molten metals or 3 times as much as anxiety", 150)
sc.mwoi(33)
p.center('-==[WHEELBARROW ANGST]==-')
sc.mwoo(10)
p.left('ABCDEFGHIJKLMNOPQRSTUVWX')
sc.lwipe('abcdefghijklmnopqrstuvwx', 10)
sc.rwipe('XWVUTSRQPONMLKJIHGFEDCBA', 10)
time.sleep_ms(500)
sc.strobe(75, 20)
sc.strobe(20, 50)
sc.strobe(150, 8)

sign.clear()
p.right('ANTHRO')
p.left('ANTHRO')
sign.invert()
p.center('  ANTHRO  ')
for i in range(0, 15):
    sign.invert()
    time.sleep_ms(150)
for i in range(0, 15):
    sign.invert()
    time.sleep_ms(150)

sign.clear()
p.center('_._.all done._._')
