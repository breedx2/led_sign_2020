#include <Arduino.h>
#include <string.h>
#include "CommandParser.h"


void CommandParser::parse(const char *commandstring){
  Serial.printf("Parsing: %s\r\n", commandstring);

  const std::string &cmd_str = commandstring;

  std::string cmd = parseCommandPart(cmd_str);
  Serial.printf("cmd = '%s'\r\n", cmd.c_str());

  std::string remainder = (cmd == cmd_str) ? "" : cmd_str.substr(cmd.length()+1);
  Serial.printf("remainder = '%s'\r\n", remainder.c_str());

  if(cmd == "center"){
    std::string str = getString(remainder);
    Serial.printf("String is: '%s'\r\n", str.c_str());
    return sc.center(str.c_str());
  }
  if(cmd == "clear"){
    return sc.clear();
  }
  if(cmd == "clwipe"){
    return remainder.empty() ? sc.clwipe() : sc.clwipe(parseNum(remainder));
  }
  if(cmd == "crwipe"){
    return remainder.empty() ? sc.crwipe() : sc.crwipe(parseNum(remainder));
  }
  if(cmd == "crid"){
    return parseColRoll(VDIRECTION::DOWN, remainder);
  }
  if(cmd == "criu"){
    return parseColRoll(VDIRECTION::UP, remainder);
  }

  /*

  // const std::string cmd_string = cmd;
  // const std::regex ws_re("\\s+"); // whitespace
  // if(strncmp(cmd, "clwipe ", strlen("clwipe")) == 0){
  //   long value = strtol(cmd+4, NULL, 16);
  //   return sc.clwipe();
  // }

  if(strcmp(cmd, "invert") == 0){
    return sc.invert();
  }
  if(strncmp(cmd, "sil ", 4) == 0){
    long value = strtol(cmd+4, NULL, 16);
    return sc.sil(value);
  }
  if(strncmp(cmd, "sir ", 4) == 0){
    long value = strtol(cmd+4, NULL, 16);
    return sc.sir(value);
  }
  std::string command = cmd;
*/
}

void CommandParser::parseColRoll(VDIRECTION vdir, std::string &remainder){
  std::string msg = getString(remainder);
  uint16_t speed = getNum1AfterString(remainder, DEFAULT_CRID_SPEED);
  std::string dirstr = getWordAfterNum1(remainder);
  DIRECTION dir = parseDirection(dirstr);
  if(dir == DIRECTION::NONE){
    return vdir == VDIRECTION::DOWN ? sc.crid(msg.c_str(), speed) : sc.criu(msg.c_str(), speed);
  }
  return vdir == VDIRECTION::DOWN ? sc.crid(msg.c_str(), speed, dir) : sc.criu(msg.c_str(), speed, dir);
}

std::string CommandParser::parseCommandPart(const std::string &cmd){
  size_t first_space = cmd.find(' ', 0);
  if(first_space == std::string::npos){ // no spaces
    return cmd.substr(0, std::min(10, int(cmd.length())));
  }
  int len = std::min(10, std::max(0, int(first_space)));
  return cmd.substr(0, len);
}

std::string CommandParser::firstMatchGroup(std::string &str, const std::regex &re){
  if(str.empty()) return std::string();
  std::smatch match;
  if (std::regex_match(str, match, re)) {
    if(match.size() > 1){
      std::ssub_match group = match[1];
      return group.str();
    }
  }
  return std::string();
}

std::string CommandParser::getString(std::string &input){
  const std::regex re("\\s*'(.*)'.*");
  return firstMatchGroup(input, re);
}

uint16_t CommandParser::parseNum(std::string &str, uint16_t defaultNum){
  try{
    return std::stoi(str);
  }
  catch(std::invalid_argument& e){
    Serial.printf("Invalid argument '%s' %s\r\n", str.c_str(), e.what());
    return defaultNum;
  }
  catch(std::out_of_range& e){
    Serial.printf("Out of range: %s\r\n", e.what());
    return defaultNum;
  }
}

uint16_t CommandParser::getNum1AfterString(std::string &input, uint16_t defaultNum){
  const std::regex re("'.*' ([0-9]+)");
  std::string numstr = firstMatchGroup(input, re);
  return parseNum(numstr, defaultNum);
}

std::string CommandParser::getWordAfterNum1(std::string &input){
  const std::regex re("'.*' [0-9]+ (\\w+)");
  return firstMatchGroup(input, re);
}

DIRECTION CommandParser::parseDirection(std::string &dirstr){
  if((dirstr == "LEFT") || (dirstr == "left")){
    return DIRECTION::LEFT;
  }
  if((dirstr == "RIGHT") || (dirstr == "right")){
    return DIRECTION::RIGHT;
  }
  return DIRECTION::NONE;
}
