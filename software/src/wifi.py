import network
import wifi_env

_wlan = network.WLAN(network.STA_IF)

def up():
    env = wifi_env.get()
    _wlan.active(True)
    _wlan.connect(env['ssid'], env['password'])
    return _wlan.ifconfig()

def connected():
    return _wlan.isconnected()

def info():
    return _wlan.ifconfig()
