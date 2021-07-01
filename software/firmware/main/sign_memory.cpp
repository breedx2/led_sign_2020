
#include <Arduino.h>
#include "sign_memory.h"

volatile SIGN_MEM _mem = new_sign_memory();

SIGN_MEM new_sign_memory(){
  SIGN_MEM result = new SIGN_ROW[7];
  for(int i=0; i < 7; i++){
    result[i] = new uint8_t[BYTES_PER_ROW];
  }
  return result;
}

SIGN_ROW get_mem_row(uint8_t rownum){
  return _mem[rownum];
}
