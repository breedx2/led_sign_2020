#include <time.h>
#include <Arduino.h>
#include "Sign.h"
#include "SignPrinter.h"
#include "SignCommands.h"

void SignCommands::center(const char *str, bool clear_first){
  printer.center(str, clear_first);
}

void SignCommands::clear(){
  sign.clear();
}

// Counter counts up centered as fast as possible at speed
void SignCommands::ctr(uint16_t num, uint16_t speed){
  char buff[SIGN_COLS];
  sign.clear();
  for(uint16_t i = 0; i < num; i++){
    sprintf(buff, "%d", i);
    Serial.printf("%s\r\n", buff);
    printer.center(buff);
    if(speed > 0){
      delay(speed);
    }
  }
}

void SignCommands::left(const char *str, bool clear_first){
  printer.left(str, clear_first);
}

void SignCommands::right(const char *str, bool clear_first){
  printer.right(str, clear_first);
}

void SignCommands::invert(){
  sign.invert();
}

void SignCommands::clwipe(uint16_t speed){
  for(int i=2; i < SIGN_COLS; i++){
    sign.col(i, 0x00);
    delay(speed);
  }
}

// format is like 'Sun Jan 01 00:00:00'
void SignCommands::time(uint16_t seconds){
  printer.clear();
  uint16_t elapsed = 0;

  time_t now;
  struct tm parts;
  char buff[20];
  while(elapsed < seconds*1000){
    memset(buff, 0, 20);
    ::time(&now);
    localtime_r(&now, &parts);
    strftime(buff, 20, "%a %b %d %H:%M:%S", &parts);
    printer.center(buff, true);
    delay(250);
    elapsed += 250;
  }
}
