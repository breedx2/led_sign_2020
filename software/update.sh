#!/bin/bash

PORT=/dev/ttyUSB1

for f in src/*.py ; do
	echo uploading ${f}...
	ampy -p ${PORT} put ${f}
done
