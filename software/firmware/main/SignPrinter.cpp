#include <Arduino.h>
#include "sign_memory.h"
#include "font5x7.h"
#include "Sign.h"
#include "SignPrinter.h"

void SignPrinter::clear(){
  sign.clear();
}

void SignPrinter::print(const char *msg, int pos, bool clear_first){
  if(clear_first) clear();

  uint8_t offset = pos;
  for(uint8_t i = 0; i < strlen(msg); i++){
    char ch = msg[i];
    GLYPH g = glyph(ch);
    sign.blit(offset, g.cols, g.length);
    offset += g.length;
    if(ch != ' '){
      sign.col(offset, 0x00);
      offset += 1;
    }
  }
}

uint8_t SignPrinter::print_mem(const char *str, uint8_t *buff, uint8_t bufflen){
  uint8_t index = 0;
  for(uint8_t i = 0; i < strlen(str); i++){
    GLYPH g = glyph(str[i]);
    for(uint8_t colnum = 0; colnum < g.length; colnum++){
      if(index >= bufflen) return index;
      buff[index++] = g.cols[colnum];
    }
    if(str[i] != ' '){
      buff[index++] = 0x00;
    }
  }
  return index;
}

void SignPrinter::left(const char *msg, bool clear_first){
  print(msg, 2, clear_first); // first 2 cols aren't addressable
}

void SignPrinter::right(const char *msg, bool clear_first){
  uint16_t len = text_length(msg);
  uint8_t pos = (len >= SIGN_COLS) ? 0 : (SIGN_COLS-len);
  print(msg, pos, clear_first);
}

void SignPrinter::center(const char *msg, bool clear_first){
  uint16_t len = text_length(msg);
  uint8_t pos = (len >= SIGN_COLS) ? 0 : ((SIGN_COLS-len)/2);
  print(msg, pos, clear_first);
}
