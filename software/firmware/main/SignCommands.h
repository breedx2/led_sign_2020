
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

class SignCommands {
  private:
    Sign &sign;
    SignPrinter &printer;
  public:
    SignCommands(Sign &sign, SignPrinter &printer): sign(sign), printer(printer){}
    void clear();
    void left(const char *str, bool clear_first = false);
    void right(const char *str, bool clear_first = false);
    void center(const char *str, bool clear_first = false);
    void invert();
    void clwipe(uint16_t speed);
    void time(uint16_t seconds = 10);
};

#endif
