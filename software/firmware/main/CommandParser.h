#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H 1

#include "SignCommands.h"
#include "SignPrinter.h"

class CommandParser {
private:
  SignCommands &sc;
  SignPrinter &printer;
  CommandParser(SignCommands &sc, SignPrinter &printer): sc(sc), printer(printer){}
public:
  void parse(const char *cmd);
};

#endif
