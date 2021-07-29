#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H 1

#include <regex>
#include "SignCommands.h"
#include "SignPrinter.h"

class CommandParser {
private:
  SignCommands &sc;
  SignPrinter &printer;
  std::string parseCommandPart(const std::string &commandstring);
  std::string firstMatchGroup(std::string &str, const std::regex &re);
  std::string getString(std::string &input);
  uint16_t parseNum(std::ssub_match match, uint16_t defaultNum = 0);
  uint16_t parseNum(std::string str, uint16_t defaultNum = 0);
  uint16_t getNum1AfterString(std::string &input, uint16_t defaultNum = 0);
  std::string getWordAfterNum1(std::string &input);
  DIRECTION parseDirection(std::string &dirstr);
  void parseColRoll(VDIRECTION vdir, std::string &remainder);
  void parseThrob(std::string &params);
  bool stringWithSpeed(std::string &cmd, std::string &params);
public:
  CommandParser(SignCommands &sc, SignPrinter &printer): sc(sc), printer(printer){}
  void parse(const char *cmd);
};

#endif
