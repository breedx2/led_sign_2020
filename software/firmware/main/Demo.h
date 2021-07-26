#ifndef DEMO_H
#define DEMO_H 1

#include "SignCommands.h"
#include "SignPrinter.h"

class Demo {

private:
  SignCommands &sc;
  SignPrinter &printer;

public:
  Demo(SignCommands &sc, SignPrinter &printer): sc(sc), printer(printer) {}
  void run();
};

#endif
