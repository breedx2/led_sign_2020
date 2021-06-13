# import wifi
# import ntptime
import sign_hardware as hw

hw.disable_output()
hw.row_off(0)
hw.row_off(1)
hw.row_off(2)
hw.row_off(3)
hw.row_off(4)
hw.row_off(5)
hw.row_off(6)


# print("Setting up wifi...")
# ip = wifi.up()
# print("Wifi connected! %s" % (ip[0]))

# TODO: Might be better to fetch this from the websocket once that's going
# print("Fetching the current time")
# ntptime.settime()
