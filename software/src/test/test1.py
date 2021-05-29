from sign import Sign
import sign_hardware as hw
from sign_printer import SignPrinter
from sign_commands import SignCommands
import sign_updater as upd
import sign_memory

mem = sign_memory.create()
sign = Sign(mem)
upd.start(mem)
p = SignPrinter(sign)
# p.left('ABCDEFGHIJKLMNOPQRSTUVWX')

sc = SignCommands(sign)
sc.clear()
# sc.center('hello')
# sc.dump()

sc.randt('OH YOU FOUND ME :)')

# sc.msl('TANNING INVITATIONAL is only the start we would really like to have a thing where a frickin laser actually got attached to sharks and outlined some text for us all oh BOY yeah!!', 3)
# sc.msr('"What an amazing plan for great success and wealth!" he said ironically', 10)
# sc.throb()
# sc.time()
# sc.rwipe('Does RWIPE work AGAIN?!?!?')
# sign.clear()
# sc.rwipe('yes it does')
# sc.krid('I AM JUST A BASIC TEST')
# sign.clear()
# sc.krod('I AM JUST A SIMPLE TEST')
# sign.clear()
# sc.krou('I AM JUST A BASIC TEST')
