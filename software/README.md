
# software for the led_sign_2020

This is the software side of the vintage LED sign refresh.

Micropython has failed us. Let's cpp with arduino libs now.

# setup

In some other directory, like `~/software` do

```
$ git clone -b v4.2.1 --recursive https://github.com/espressif/esp-idf.git
```

And in this dir, should only have to do this once:
```
$ git submodule update --init --recursive
```

## dev setup

each time you're ready to develop:

`$ source ./dev-setup.sh`

# misc

To compile/build:

`idf.py build`

To burn new firmware:

`idf.py -p /dev/ttyUSB0 flash`

To use the serial console:
`screen /dev/ttyUSB0 115200`

To upload a file to the device:
`ampy -p /dev/ttyUSB0 put somefile`
