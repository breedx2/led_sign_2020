
# software for the led_sign_2020

This is the software side of the vintage LED sign refresh.

Going to try using [micropython](https://micropython.org/) for starters, if
it doesn't work out we'll try something lower level.

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

To use the python REPL then on the device:
`screen /dev/ttyUSB0 115200`

To upload a file to the device:
`ampy -p /dev/ttyUSB0 put somefile`
