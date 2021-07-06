#ifndef SIGN_PRINTER_H
#define SIGN_PRINTER_H 1

#include "Sign.h"

class SignPrinter {
  private:
    Sign &sign;
  public:
    SignPrinter(Sign &sign): sign(sign) {}
    void clear();
    void print(const char *msg, int pos);
    void left(const char *msg);
    void right(const char *msg);
};

#endif
