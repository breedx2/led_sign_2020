#include <Arduino.h>
#include <string.h>
#include "CommandParser.h"


void CommandParser::parse(const char *commandstring){
  Serial.printf("Parsing: %s\r\n", commandstring);

  const std::string &cmd_str = commandstring;

  std::string cmd = parseCommandPart(cmd_str);
  Serial.printf("cmd = '%s'\r\n", cmd.c_str());

  std::string params = (cmd == cmd_str) ? "" : cmd_str.substr(cmd.length()+1);
  Serial.printf("params = '%s'\r\n", params.c_str());

  if(cmd == "center"){
    std::string str = getString(params);
    Serial.printf("String is: '%s'\r\n", str.c_str());
    return sc.center(str.c_str());
  }
  if(cmd == "clear"){
    return sc.clear();
  }
  if(cmd == "clwipe"){
    return params.empty() ? sc.clwipe() : sc.clwipe(parseNum(params));
  }
  if(cmd == "crwipe"){
    return params.empty() ? sc.crwipe() : sc.crwipe(parseNum(params));
  }
  if(cmd == "crid"){
    return parseColRoll(VDIRECTION::DOWN, params);
  }
  if(cmd == "criu"){
    return parseColRoll(VDIRECTION::UP, params);
  }
  if(cmd == "throb"){
    return parseThrob(params);
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

void CommandParser::parseColRoll(VDIRECTION vdir, std::string &params){
  std::string msg = getString(params);
  uint16_t speed = getNum1AfterString(params, DEFAULT_CRID_SPEED);
  std::string dirstr = getWordAfterNum1(params);
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

void CommandParser::parseThrob(std::string &params){
  //throb dir pos speed revolutions
  const std::regex re("(cw|CW|ccw|CW)\\s?+(\\d+)?\\s?+(\\d+)?\\s?+(\\d+)?");
  std::smatch match;
  if (!std::regex_match(params, match, re)) {
    return sc.throb();
  }
  std::ssub_match dirmatch = match[1];
  std::ssub_match posmatch = match[2];
  std::ssub_match speedmatch = match[3];
  std::ssub_match revmatch = match[4];

  std::string dirstr = dirmatch.str();
  CLOCK_DIR cd = ((dirstr == "cw") || (dirstr == "CW")) ? CLOCK_DIR::CW : CLOCK_DIR::CCW;

  if(!posmatch.matched){
    return sc.throb(cd);
  }
  std::string posstr = posmatch.str();
  uint16_t pos = parseNum(posstr, (SIGN_COLS/2)-2);
  if(!speedmatch.matched){
    return sc.throb(cd, pos);
  }
  std::string speedstr = speedmatch.str();
  uint16_t speed = parseNum(speedstr, 65);
  if(!revmatch.matched){
    return sc.throb(cd, pos, speed);
  }
  std::string revstr = revmatch.str();
  uint16_t revolutions = std::min(int(parseNum(revstr, 10)), 100);
  return sc.throb(cd, pos, speed, revolutions);
}
