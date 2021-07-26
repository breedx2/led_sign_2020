#include <Arduino.h>
#include "SerialCommander.h"

void show_prompt(){
  Serial.print("sign > ");
}

bool SerialCommander::loop(){
  if(!prompted){
    show_prompt();
    prompted = true;
  }
  if(ready()) return true; // Don't read more if we have a command waiting...
  while(Serial.available()){
    char ch = Serial.read();
    if(ch == '\r' || (cmdbuff_len >= 1022)){
        Serial.print("\r\n");
        have_cmd = true;
        Serial.printf("COMMAND: '%s'\r\n", cmdbuff);
        return true;
    }
    else if(ch == 0x7F){ //delete/backspace
      if(cmdbuff_len > 0){
        Serial.printf("%c %c", 0x08, 0x08); //backspace
        cmdbuff[--cmdbuff_len] = 0x00;
      }
    }
    else {
      Serial.print(ch);
      cmdbuff[cmdbuff_len++] = ch;
    }
  }
  return false;
}

bool SerialCommander::ready(){
  return have_cmd;
}

uint16_t SerialCommander::drain(char *buff, uint16_t len){
  if(!ready()) return 0;
  uint16_t result = std::min(len, cmdbuff_len);
  strncpy(buff, cmdbuff, result);
  have_cmd = 0;
  memset(cmdbuff, 0, 1024);
  prompted = false;
  cmdbuff_len = 0;
  return result;
}
