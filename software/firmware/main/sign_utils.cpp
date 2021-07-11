#include <Arduino.h>
#include "sign_memory.h"
#include "sign_utils.h"

void reverse_buffer(uint8_t *buff, uint8_t length){
  for(uint8_t i = 0; i <= (length/2); i++){
    uint8_t tmp = buff[i];
    buff[i] = buff[length-i-1];
    buff[length-i-1] = tmp;
  }
}

// Dumps the raw sign memory to the serial port
void dump_mem_serial(){
  for(uint8_t rownum = 0; rownum < 7; rownum++){
    SIGN_ROW row = get_mem_row(rownum);
    Serial.printf("%d: ", rownum);
    for(uint8_t j = 0; j < BYTES_PER_ROW; j++){
      Serial.printf("%02X ", row[j]);
    }
    Serial.printf("\r\n");
  }
}
