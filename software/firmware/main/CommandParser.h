#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H 1

#include <tuple>
#include <regex>
#include "SignCommands.h"
#include "SignPrinter.h"

class CommandParser {
private:
  SignCommands &sc;
  SignPrinter &printer;
  std::string parseCommandPart(const std::string &commandstring);
  std::string getString(std::string &input);
  uint16_t parseNum(std::ssub_match match, uint16_t defaultNum = 0);
  uint16_t parseNum(std::string str, uint16_t defaultNum = 0);
  uint16_t getNum1AfterString(std::string &input, uint16_t defaultNum = 0);
  std::string getWordAfterNum1(std::string &input);
  DIRECTION parseDirection(std::string &dirstr);
  void parseColRoll(VDIRECTION vdir, std::string &remainder);
  void parseThrob(std::string &params);
  bool stringWithSpeed(std::string &cmd, std::string &params);
  bool parseCommandWithJustOptionalSpeed(std::string &cmd, std::string &params);
  void parseTwo(std::string &params, std::function<void(uint16_t, uint16_t)> fn);
  std::tuple<int16_t,int16_t> findString(std::string &input);
  std::string afterString(std::string input);
  std::string afterDigits(std::string input);
  std::string afterWhitespace(std::string input);
  uint16_t parseDigits(std::string input, uint16_t defaultNum);
public:
  CommandParser(SignCommands &sc, SignPrinter &printer): sc(sc), printer(printer){}
  void parse(const char *cmd);
};

#endif
