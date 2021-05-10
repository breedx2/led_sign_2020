import network
import wifi_env
import utime
from machine import Timer, Pin

# Use a timer to toggle a pin with/out wifi

_wlan = network.WLAN(network.STA_IF)
_tmr = Timer(0);
pin = Pin(32, Pin.OUT, value=0)
v = 0x01

def no_wifi():
    print("not turning on wifi")
    timer_start()

def with_wifi():
    config = wifi_up()
    print(config)
    timer_start()

def timer_start():
    global _tmr
    _tmr.init(period=1, mode=Timer.PERIODIC, callback=_cb)

def _cb(timer):
    global pin
    global v
    if v == 0x01:
        pin.on()
        v = 0x00
    else:
        v = 0x01
        pin.off()

# brings up the device, waiting for it to be connected
def wifi_up():
    env = wifi_env.get()
    _wlan.active(True)
    _wlan.connect(env['ssid'], env['password'])
    while not _wlan.isconnected():
        utime.sleep(0.250)
    return _wlan.ifconfig()
