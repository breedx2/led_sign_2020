#include <Arduino.h>
#include "sign_memory.h"
#include "Sign.h"

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
