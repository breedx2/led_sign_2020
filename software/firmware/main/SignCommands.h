
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

enum DIRECTION { LEFT, RIGHT };

class SignCommands {
  private:
    Sign &sign;
    SignPrinter &printer;
  public:
    SignCommands(Sign &sign, SignPrinter &printer): sign(sign), printer(printer){}
    void center(const char *str, bool clear_first = false);
    void clear();
    void clwipe(uint16_t speed);
    void crid(const char *str, uint16_t speed = 25, DIRECTION dir = LEFT);
    void ctr(uint16_t num, uint16_t speed = 0);
    void invert();
    void left(const char *str, bool clear_first = false);
    void right(const char *str, bool clear_first = false);
    void time(uint16_t seconds = 10);
};

#endif
