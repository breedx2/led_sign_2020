#include <Arduino.h>
#include "Sign.h"
#include "SignCommands.h"

void SignCommands::clwipe(uint16_t speed){
  for(int i=2; i < SIGN_COLS; i++){
    sign.col(i, 0x00);
    delay(speed);
  }
}
