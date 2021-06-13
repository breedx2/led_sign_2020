#!/bin/bash

PORT=/dev/ttyUSB0

for f in src/*.py ; do
	echo uploading ${f}...
	ampy -p ${PORT} put ${f}
done

for f in src/test/*.py ; do
	echo uploading ${f}...
	ampy -p ${PORT} put ${f}
done
