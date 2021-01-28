
# setup

```
$ virtualenv env
$ source env/bin/activate
$ pip install esptool adafruit-ampy
$ esptool.py --port /dev/ttyUSB0 erase_flash
$ esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash -z 0x1000 firmware/esp32-idf3-20200902-v1.13.bin
```

To use the python REPL then on the device:
`screen /dev/ttyUSB0 115200`

To upload a file to the device:
`ampy -p /dev/ttyUSB0 put somefile`
