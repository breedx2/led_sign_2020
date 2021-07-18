#include <Arduino.h>
#include "sign_memory.h"
#include "font5x7.h"
#include "Sign.h"
#include "SignPrinter.h"

void SignPrinter::clear(){
  sign.clear();
}

// Prints a message to the sign at a given position
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

// "prints" a message into a buffer. returns the actual length, in columns,
// used by the print.
uint8_t SignPrinter::print_mem(const char *str, uint8_t *buff, uint8_t bufflen, bool center){
  uint8_t index = 0;
  uint16_t str_cols_len = text_length(str);

  if(str_cols_len > bufflen) str_cols_len = bufflen;
  if(center){
    index = (bufflen - str_cols_len)/2;
  }
  uint8_t msglen = strlen(str);
  for(uint8_t i = 0; i < msglen; i++){
    if(index >= bufflen){
      return index;
    }
    GLYPH g = glyph(str[i]);
    for(uint8_t colnum = 0; colnum < g.length; colnum++){
      if(index >= bufflen) return index;
      buff[index++] = g.cols[colnum];
    }
    if((str[i] != ' ') && (i < msglen-1)){
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
