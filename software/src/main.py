import wifi

print("Setting up wifi...")
ip = wifi.up()
print("Wifi connected! %s" % (ip[0]))
