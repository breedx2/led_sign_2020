#include <Arduino.h>
#include "CommandParser.h"

void CommandParser::parse(const char *cmd){
  if(strcmp(cmd, "clear")){
    return sc.clear();
  }
}
