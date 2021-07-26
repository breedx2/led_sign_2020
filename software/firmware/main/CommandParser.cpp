#include <Arduino.h>
#include <string.h>
#include "CommandParser.h"

void CommandParser::parse(const char *cmd){
  Serial.printf("Parsing: %s\r\n", cmd);
  if(strcmp(cmd, "clear") == 0){
    return sc.clear();
  }
  if(strcmp(cmd, "invert") == 0){
    return sc.invert();
  }
  if(strncmp(cmd, "center ", strlen("center ")) == 0){
    return sc.center(cmd + strlen("center "));
  }
  if(strncmp(cmd, "sir ", 4) == 0){
    long value = strtol(cmd+4, NULL, 16);
    return sc.sir(value);
  }
  std::string command = cmd;

}
