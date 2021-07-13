
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

#include <functional>

enum DIRECTION { LEFT, RIGHT };

class SignCommands {
  private:
    Sign &sign;
    SignPrinter &printer;
    void cri_x(const char *str, uint16_t speed, DIRECTION dir, std::function<uint8_t(uint8_t, uint8_t)> shifter);
  public:
    SignCommands(Sign &sign, SignPrinter &printer): sign(sign), printer(printer){}
    void center(const char *str, bool clear_first = false);
    void clear();
    void clwipe(uint16_t speed);
    void crwipe(uint16_t speed);
    void crid(const char *str, uint16_t speed = 25, DIRECTION dir = LEFT);
    void criu(const char *str, uint16_t speed = 25, DIRECTION dir = LEFT);
    void ctr(uint16_t num, uint16_t speed = 50);
    void invert();
    void left(const char *str, bool clear_first = false);
    void lwipe(const char *str, uint16_t speed = 35);
    void mwoi(uint16_t speed = 50);
    void mwoo(uint16_t speed = 50);
    void mwc(const char *str, uint16_t speed = 50);
    void rid(const char *str, uint16_t speed = 50);
    void right(const char *str, bool clear_first = false);
    void riu(const char *str, uint16_t speed = 50);
    void rod(uint16_t speed = 50);
    void rou(uint16_t speed = 50);
    void time(uint16_t seconds = 10);
};

#endif
