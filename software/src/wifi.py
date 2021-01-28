import network
import wifi_env
import utime

_wlan = network.WLAN(network.STA_IF)

# brings up the device, waiting for it to be connected
def up():
    env = wifi_env.get()
    _wlan.active(True)
    _wlan.connect(env['ssid'], env['password'])
    while not _wlan.isconnected():
        utime.sleep(0.250)
    return _wlan.ifconfig()

def connected():
    return _wlan.isconnected()

def info():
    return _wlan.ifconfig()
