import network
import wifi_env

wlan = network.WLAN(network.STA_IF)

def up():
    env = wifi_env.get()
    wlan.active(True)
    wlan.connect(env['ssid'], env['password'])
    wlan.ifconfig()

def connected():
    wlan.isconnected()
