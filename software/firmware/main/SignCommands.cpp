#include <time.h>
#include <Arduino.h>
#include "Sign.h"
#include "SignPrinter.h"
#include "SignCommands.h"

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
