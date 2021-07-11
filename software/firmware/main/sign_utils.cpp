#include <Arduino.h>
#include "sign_utils.h"

void reverse_buffer(uint8_t *buff, uint8_t length){
  for(uint8_t i = 0; i <= (length/2); i++){
    uint8_t tmp = buff[i];
    buff[i] = buff[length-i-1];
    buff[length-i-1] = tmp;
  }
}
