from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
from sign_buffers import Buffers
import time

sb = Buffers()
sign = Sign(sb)
upd.start(sb)
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
sc.riu('//////\\\\\\\\\\\\', 100)
sc.riu('\\/////\\\\\\\\\\\\', 1)
sc.riu('\\\\////\\\\\\\\\\\\', 1)
sc.riu('\\\\\\///\\\\\\\\\\\\', 1)
sc.riu('\\\\\\\\//\\\\\\\\\\\\', 1)
sc.riu('\\\\\\\\\\/\\\\\\\\\\\\', 1)
sc.riu('\\\\\\\\\\\\\\\\\\\\\\\\', 1)
sc.riu('\\\\\\\\\\\\/\\\\\\\\\\', 1)
sc.riu('\\\\\\\\\\\\//\\\\\\\\', 1)
sc.riu('\\\\\\\\\\\\////\\\\\\', 1)
sc.riu('\\\\\\\\\\\\/////\\\\', 1)
sc.riu('\\\\\\\\\\\\//////\\', 1)
sc.riu('\\\\\\\\\\\\///////', 100)
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
p.left('shift in left')
for i in [1,3,7,15,31,63,127]:
    sc.sil(i)
    time.sleep_ms(200)
sign.clear()
p.right('shift in right')
for i in [127,63,31,15,7,3,1]:
    sc.sir(i)
    time.sleep_ms(200)

sign.clear()
p.center('** RANDOM DISSOLVE **')
sc.rando()
p.center('ANYTHING BASICALLY')
sc.randi("** RANDOM APPEAR **")
time.sleep_ms(250)
sc.randt("! A MOTH IS BORN ANEW !")
time.sleep_ms(1000)

sign.clear()
sc.lazr("IT'S A LAZER BEAM BOZO")
sign.clear()
sc.kriu('* CHARS RISE ON UP *')
sign.clear()
sc.krid('* CHARS FALL FROM SKY *')
sign.clear()
sc.krou('* CHARS FLOAT AWAY *')
sign.clear()
sc.krod('* CHARS MELT INTO MUD *')
sc.msl('WE CAN SCROLL A MESSAGE THAT IS MUCH MUCH WIDER THAN THE SIGN ITSELF', 2)
sc.msr('AND WE CAN DO IT IN THE OTHER DIRECTION EVEVEN THO ITS HARD TO READ', 2)
sign.clear()
p.center('_._.all done._._')
