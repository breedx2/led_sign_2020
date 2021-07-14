#include <Arduino.h>
#include "Sign.h"


void Sign::all_on(){
  for(uint8_t rownum = 0; rownum < 7; rownum++){
    SIGN_ROW row = get_mem_row(rownum);
    memset(row, 0xFF, BYTES_PER_ROW);
  }
}

void Sign::all_off(){
  for(uint8_t rownum = 0; rownum < 7; rownum++){
    SIGN_ROW row = get_mem_row(rownum);
    memset(row, 0x00, BYTES_PER_ROW);
  }
}

void Sign::clear(){
  clear_memory();
}

void Sign::col(uint8_t colnum, uint8_t value) {
  if(colnum >= SIGN_COLS){
    return;
  }
  uint8_t adjusted = colnum + 6;
  uint8_t byte_offset = adjusted / 8;
  uint8_t target_mask = 1 << (adjusted % 8); // TODO: Needs additional offset

  for(uint8_t rownum = 0; rownum < 7; rownum++){

    SIGN_ROW row = get_mem_row(rownum);
    uint8_t mask = 1 << rownum;

    if((value & mask) == mask){
      row[byte_offset] = row[byte_offset] | target_mask;
    }
    else {
      row[byte_offset] = row[byte_offset] & (~target_mask);
    }
  }
}

void Sign::blit(uint8_t offset, uint8_t *cols, uint8_t length) {
  for(uint8_t i=0; i < length; i++){
    col(offset + i, cols[i]);
  }
}

uint8_t Sign::get_col(uint8_t colnum){
  uint8_t rownum = 0;
  uint8_t result = 0;
  uint8_t realigned_col = colnum + 6;
  uint8_t byteoff = realigned_col/8;
  uint8_t mask = (1 << (realigned_col % 8));
  while(rownum < 7){
    SIGN_ROW row = get_mem_row(rownum);
    if(row[byteoff] & mask){
      result = result | (1<<rownum);
    }
    rownum = rownum + 1;
  }
  return result;
}

void Sign::invert(){
  for(uint8_t rownum = 0; rownum < 7; rownum++){
    SIGN_ROW row = get_mem_row(rownum);
    for(uint8_t b = 0; b < BYTES_PER_ROW; b++){
      row[b] ^= 0xFF;
    }
  }
}

void Sign::on(uint8_t col, uint8_t rownum){
  uint8_t realigned_col = col + 6;
  uint8_t byteoff = realigned_col / 8;
  SIGN_ROW row = get_mem_row(rownum);
  uint8_t mask = (1 << realigned_col % 8);
  row[byteoff] = row[byteoff] | mask;
}

void Sign::off(uint8_t col, uint8_t rownum){
  uint8_t realigned_col = col + 6;
  uint8_t byteoff = realigned_col / 8;
  SIGN_ROW row = get_mem_row(rownum);
  uint8_t mask = ~(1 << realigned_col % 8);
  row[byteoff] = row[byteoff] & mask;
}

// The first_row_fn determines how to populate the first row given the last row before rolling
void Sign::roll_down(std::function<SIGN_ROW(SIGN_ROW)> first_row_fn){
  SIGN_MEM mem = get_memory();
  SIGN_ROW b = mem[6];
  mem[6] = mem[5];
  mem[5] = mem[4];
  mem[4] = mem[3];
  mem[3] = mem[2];
  mem[2] = mem[1];
  mem[1] = mem[0];
  mem[0] = first_row_fn(b);
}

// The last_row_fn determines how to populate the last row given the first row before rolling
void Sign::roll_up(std::function<SIGN_ROW(SIGN_ROW)> last_row_fn){
  SIGN_MEM mem = get_memory();
  SIGN_ROW t = mem[0];
  mem[0] = mem[1];
  mem[1] = mem[2];
  mem[2] = mem[3];
  mem[3] = mem[4];
  mem[4] = mem[5];
  mem[5] = mem[6];
  mem[6] = last_row_fn(t);
}

// Shifts the display one column to the right
void Sign::shift_right(){
  for(int rownum = 6; rownum >= 0; rownum--){
    SIGN_ROW row = get_mem_row(rownum);
    for(int b = BYTES_PER_ROW - 1; b >= 0; b--){
      row[b] = row[b] << 1;
      if((b > 0) && (row[b-1] & 0x80)){
        row[b] += 0x01;
      }
    }
  }
}
