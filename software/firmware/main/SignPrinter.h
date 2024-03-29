#ifndef SIGN_PRINTER_H
#define SIGN_PRINTER_H 1

#include "Sign.h"

class SignPrinter {
  private:
    Sign &sign;
  public:
    SignPrinter(Sign &sign): sign(sign) {}
    void clear();
    void print(const char *msg, int pos, bool clear_first = false);
    uint8_t char_at_pos(const char ch, uint8_t pos);
    uint8_t print_mem(const char *str, uint8_t *buff, uint8_t bufflen, bool center = false);
    void left(const char *msg, bool clear_first = false);
    void right(const char *msg, bool clear_first = false);
    void center(const char *msg, bool clear_first = false);
};

#endif
