#include <Arduino.h>
#include "sign_hardware.h"

// pin mappings
#define _EN    21
#define _CDATA 22
#define _CCLK  23
// #define _BS_IN 34
#define _C1    12
#define _C2    13
#define _C3    14
#define _C4    15
#define _C5    16
#define _C6    17
#define _C7    18

uint8_t row_pins[] = {
  _C1, _C2, _C3, _C4, _C5, _C6, _C7
};

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
}

void enable_output(){
  digitalWrite(_EN, HIGH);
}

void disable_output(){
  digitalWrite(_EN, LOW);
}

void row_on(uint8_t row){
  digitalWrite(row_pins[row-1], HIGH);
}

void row_off(uint8_t row){
  digitalWrite(row_pins[row-1], LOW);
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

void shift_row(uint8_t row){
  //TBD
}
