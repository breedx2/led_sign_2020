import wifi
import ntptime

print("Setting up wifi...")
ip = wifi.up()
print("Wifi connected! %s" % (ip[0]))

# TODO: Might be better to fetch this from the websocket once that's going
print("Fetching the current time")
ntptime.settime()
