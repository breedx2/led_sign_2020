#include <Arduino.h>
#include <SPI.h>
#include "sign_memory.h"
#include "sign_hardware.h"

// pin mappings
#define _EN      21
#define _CDATA   22
#define _CCLK    23
// SS for SPI isnt actually used, we just pick an unused pin and don't even ever configure it
#define _BS_SS   27
// same story for this BS MISO pin
#define _BS_MISO 27
// #define _BS_IN 34
#define _C1      12
#define _C2      13
#define _C3      14
#define _C4      15
#define _C5      16
#define _C6      17
#define _C7      18

#define SPI_FREQ 3250000
uint8_t row_pins[] = {
  _C1, _C2, _C3, _C4, _C5, _C6, _C7
};

SPIClass spi;
SPISettings spiSettings;

void init_sign_hardware(){
  pinMode(_EN, OUTPUT);
  digitalWrite(_EN, LOW);
  pinMode(_CDATA, OUTPUT);
  pinMode(_CCLK, OUTPUT);
  pinMode(_C1, OUTPUT);
  pinMode(_C2, OUTPUT);
  pinMode(_C3, OUTPUT);
  pinMode(_C4, OUTPUT);
  pinMode(_C5, OUTPUT);
  pinMode(_C6, OUTPUT);
  pinMode(_C7, OUTPUT);
  spiSettings = SPISettings(SPI_FREQ, LSBFIRST, SPI_MODE0);
  spi = SPIClass(HSPI);
  spi.begin(_CCLK, _BS_MISO, _CDATA, _BS_SS);
  spi.setFrequency(SPI_FREQ);
  spi.setBitOrder(LSBFIRST);
}

void enable_output(){
  digitalWrite(_EN, HIGH);
}

void disable_output(){
  digitalWrite(_EN, LOW);
}

void row_on(uint8_t rownum){
  digitalWrite(row_pins[rownum], HIGH);
}

void row_off(uint8_t rownum){
  digitalWrite(row_pins[rownum], LOW);
}

void all_rows_off(){
  row_off(_C1);
  row_off(_C2);
  row_off(_C3);
  row_off(_C4);
  row_off(_C5);
  row_off(_C6);
  row_off(_C7);
}

void shift_row(SIGN_ROW row){
  spi.writeBytes(row, BYTES_PER_ROW);
}
