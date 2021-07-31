#include <Arduino.h>
#include <string.h>
#include <set>
#include <tuple>
#include "CommandParser.h"

typedef std::function<void(SignCommands &sc, uint16_t speed)> SPEED_FN;
typedef struct {
  uint16_t speed;
  SPEED_FN fn;
} speed_cmdinfo;
// just commands that take an optional speed
const std::map<std::string, speed_cmdinfo> CMD_SPEED_CONFIGS {
  {"clwipe", {5,  [](SignCommands &sc, uint16_t speed){ sc.clwipe(speed); } } },
  {"crwipe", {5,  [](SignCommands &sc, uint16_t speed){ sc.crwipe(speed); } } },
  {"mwoi",   {50, [](SignCommands &sc, uint16_t speed){ sc.mwoi(speed); } } },
  {"mwoo",   {50, [](SignCommands &sc, uint16_t speed){ sc.mwoo(speed); } } },
  {"rando",  {10, [](SignCommands &sc, uint16_t speed){ sc.rando(speed); } } },
  {"rod",    {50, [](SignCommands &sc, uint16_t speed){ sc.rod(speed); } } },
  {"rou",    {50, [](SignCommands &sc, uint16_t speed){ sc.rou(speed); } } },
  // sil/sir technically not speed, but we can get away with it
  {"sil",    {0,  [](SignCommands &sc, uint16_t value){ sc.sil(value); } } },
  {"sir",    {0,  [](SignCommands &sc, uint16_t value){ sc.sir(value); } } },
  // time is technically not speed, but one single uint16_t so we get away with it
  {"time",   {10, [](SignCommands &sc, uint16_t seconds){ sc.time(seconds); } } },
};

typedef std::function<void(SignCommands &sc, const char *str, uint16_t speed)> STRING_AND_SPEED_FN;
typedef struct {
  uint16_t speed;
  STRING_AND_SPEED_FN fn;
} string_speed_cmdinfo;

// just commands that take a single string and an optional speed
const std::map<std::string, string_speed_cmdinfo> CMD_STR_SPEED_CONFIGS {
  {"krid",  {DEFAULT_KR_SPEED, [](SignCommands &sc, const char *str, uint16_t speed){ sc.krid(str, speed); } } },
  {"kriu",  {DEFAULT_KR_SPEED, [](SignCommands &sc, const char *str, uint16_t speed){ sc.kriu(str, speed); } } },
  {"krod",  {DEFAULT_KR_SPEED, [](SignCommands &sc, const char *str, uint16_t speed){ sc.krod(str, speed); } } },
  {"krou",  {DEFAULT_KR_SPEED, [](SignCommands &sc, const char *str, uint16_t speed){ sc.krou(str, speed); } } },
  {"lwipe", {35, [](SignCommands &sc, const char *str, uint16_t speed){ sc.lwipe(str, speed); } } },
  {"msl",   {35, [](SignCommands &sc, const char *str, uint16_t speed){ sc.msl(str, speed); } } },
  {"msr",   {35, [](SignCommands &sc, const char *str, uint16_t speed){ sc.msr(str, speed); } } },
  {"mwc",   {50, [](SignCommands &sc, const char *str, uint16_t speed){ sc.mwc(str, speed); } } },
  {"randi", {10, [](SignCommands &sc, const char *str, uint16_t speed){ sc.randi(str, speed); } } },
  {"randt", {10, [](SignCommands &sc, const char *str, uint16_t speed){ sc.randt(str, speed); } } },
  {"rid",   {50, [](SignCommands &sc, const char *str, uint16_t speed){ sc.rid(str, speed); } } },
  {"riu",   {50, [](SignCommands &sc, const char *str, uint16_t speed){ sc.riu(str, speed); } } },
  {"rwipe", {35, [](SignCommands &sc, const char *str, uint16_t speed){ sc.rwipe(str, speed); } } },
};

void CommandParser::parse(const char *commandstring){
  Serial.printf("Parsing: %s\r\n", commandstring);

  const std::string &cmd_str = commandstring;

  std::string cmd = parseCommandPart(cmd_str);
  Serial.printf("cmd = '%s'\r\n", cmd.c_str());

  std::string params = (cmd == cmd_str) ? "" : cmd_str.substr(cmd.length()+1);
  Serial.printf("params = '%s'\r\n", params.c_str());
  std::smatch match;

  if(cmd == "center"){
    std::string str = getString(params);
    return sc.center(str.c_str());
  }
  if(cmd == "clear"){
    return sc.clear();
  }
  if(cmd == "crid"){
    return parseColRoll(VDIRECTION::DOWN, params);
  }
  if(cmd == "criu"){
    return parseColRoll(VDIRECTION::UP, params);
  }
  if(cmd == "ctr"){
    const std::regex re("([0-9]+)\\s+([0-9]+)?");
    if (!std::regex_match(params, match, re)) {
      return sc.ctr(10, 150);
    }
    uint16_t num = parseNum(match[1], 10);
    std::ssub_match speedmatch = match[2];
    if(!speedmatch.matched){
      return sc.ctr(num);
    }
    uint16_t speed = parseNum(match[2], 50);
    return sc.ctr(num, speed);
  }
  if(cmd == "invert"){
    return sc.invert();
  }
  if(cmd == "lazr"){
    return sc.lazr(getString(params).c_str());
  }
  if(cmd == "left"){
    std::string str = getString(params);
    bool clear_first = getNum1AfterString(params, 0) != 0;
    return sc.left(str.c_str(), clear_first);
  }
  if(cmd == "on"){
    SignCommands *scmd = &sc;
    return parseTwo(params, [scmd](uint16_t num1, uint16_t num2){ scmd->on(num1, num2);});
  }
  if(cmd == "off"){
    SignCommands *scmd = &sc;
    return parseTwo(params, [scmd](uint16_t num1, uint16_t num2){ scmd->off(num1, num2);});
  }
  if(cmd == "right"){
    std::string str = getString(params);
    return sc.right(str.c_str());
  }
  if(cmd == "strobe"){
    SignCommands *scmd = &sc;
    return parseTwo(params, [scmd](uint16_t num1, uint16_t num2){ scmd->strobe(num1, num2);});
  }
  if(cmd == "throb"){
    return parseThrob(params);
  }
  if(parseCommandWithJustOptionalSpeed(cmd, params)){
    return;
  }
  if(stringWithSpeed(cmd, params)){
    return;
  }

}

void CommandParser::parseTwo(std::string &params, std::function<void(uint16_t, uint16_t)> fn){
  const std::regex re("([0-9]+)\\s+([0-9]+)");
  std::smatch match;
  if (!std::regex_match(params, match, re)) {
    return;
  }
  uint8_t col = parseNum(match[1], 0);
  uint8_t row = parseNum(match[2], 0);
  return fn(col, row);
}

// There are quite a number of commadns that just take a single optional uint16_t
bool CommandParser::parseCommandWithJustOptionalSpeed(std::string &cmd, std::string &params){
  auto it = CMD_SPEED_CONFIGS.find(cmd);
  if(it == CMD_SPEED_CONFIGS.end()){
    return false;
  }
  uint16_t default_speed = it->second.speed;
  SPEED_FN fn = it->second.fn;
  uint16_t speed = parseNum(params, default_speed);
  fn(sc, speed);
  return true;
}

// There are quite a number of commands that fit this pattern.
bool CommandParser::stringWithSpeed(std::string &cmd, std::string &params){
  auto it = CMD_STR_SPEED_CONFIGS.find(cmd);
  if(it == CMD_STR_SPEED_CONFIGS.end()){
    return false;
  }
  uint16_t default_speed = it->second.speed;
  STRING_AND_SPEED_FN fn = it->second.fn;
  std::string str = getString(params);
  uint16_t speed = getNum1AfterString(params, default_speed);
  fn(sc, str.c_str(), speed);
  return true;
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

uint16_t CommandParser::parseNum(std::ssub_match match, uint16_t defaultNum){
  std::string str = match.str();
  if(!match.matched) return defaultNum;
  return parseNum(str, defaultNum);
}

uint16_t CommandParser::parseNum(std::string str, uint16_t defaultNum){
  if(str.empty()) return defaultNum;
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
  if(input.empty()) return defaultNum;
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
  uint16_t pos = parseNum(posmatch, (SIGN_COLS/2)-2);
  if(!speedmatch.matched){
    return sc.throb(cd, pos);
  }
  uint16_t speed = parseNum(speedmatch, 65);
  if(!revmatch.matched){
    return sc.throb(cd, pos, speed);
  }
  uint16_t revolutions = std::min(int(parseNum(revmatch, 10)), 100);
  return sc.throb(cd, pos, speed, revolutions);
}
