#!/bin/bash

MYDIR=$(dirname "${BASH_SOURCE[0]}")
#source "${MYDIR}/env/bin/activate"

ESP32DIR=/home/jason/software/esp32

export PATH=$PATH:${ESP32DIR}/xtensa-esp32-elf/bin
export IDF_PATH=${ESP32DIR}/esp-idf
export IDF_TOOLS_PATH=${ESP32DIR}/idf-tools

source ${IDF_PATH}/export.sh
