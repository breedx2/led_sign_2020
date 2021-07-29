
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

#include <functional>
#include "Sign.h"
#include "SignPrinter.h"

enum class VDIRECTION { NONE, UP, DOWN };
enum class DIRECTION { NONE, LEFT, RIGHT };
enum class CLOCK_DIR { CW, CCW };

#define DEFAULT_CRID_SPEED   25
#define DEFAULT_CRIU_SPEED   25
#define DEFAULT_KR_SPEED     25

class SignCommands {
  private:
    Sign &sign;
    SignPrinter &printer;
    void cri_x(const char *str, uint16_t speed, DIRECTION dir, std::function<uint8_t(uint8_t, uint8_t)> shifter);
    void roll_chars(const char *str, uint16_t speed, std::function<uint8_t(uint8_t, uint8_t)> colmaker);
  public:
    SignCommands(Sign &sign, SignPrinter &printer): sign(sign), printer(printer){}
    void center(const char *str, bool clear_first = false);
    void clear();
    void clwipe(uint16_t speed = 5);
    void crwipe(uint16_t speed = 5);
    void crid(const char *str, uint16_t speed = DEFAULT_CRID_SPEED, DIRECTION dir = DIRECTION::LEFT);
    void criu(const char *str, uint16_t speed = DEFAULT_CRIU_SPEED, DIRECTION dir = DIRECTION::LEFT);
    void ctr(uint16_t num, uint16_t speed = 50);
    void invert();
    void krid(const char *str, uint16_t speed = DEFAULT_KR_SPEED, bool clear_first = true);
    void kriu(const char *str, uint16_t speed = DEFAULT_KR_SPEED, bool clear_first = true);
    void krod(const char *str, uint16_t speed = DEFAULT_KR_SPEED, bool clear_first = true);
    void krou(const char *str, uint16_t speed = DEFAULT_KR_SPEED, bool clear_first = true);
    void lazr(const char *str);
    void left(const char *str, bool clear_first = false);
    void lwipe(const char *str, uint16_t speed = 35);
    void msl(const char *str, uint16_t speed = 35);
    void msr(const char *str, uint16_t speed = 35);
    void mwc(const char *str, uint16_t speed = 50);
    void mwoi(uint16_t speed = 50);
    void mwoo(uint16_t speed = 50);
    void on(uint8_t col, uint8_t rownum);
    void off(uint8_t col, uint8_t rownum);
    void randi(const char *str, uint16_t speed = 10);
    void rando(uint16_t speed = 10);
    void randt(const char *str, uint16_t speed = 10);
    void rid(const char *str, uint16_t speed = 50);
    void right(const char *str, bool clear_first = false);
    void riu(const char *str, uint16_t speed = 50);
    void rod(uint16_t speed = 50);
    void rou(uint16_t speed = 50);
    void rwipe(const char *str, uint16_t speed = 35);
    void sil(uint8_t byte_val);
    void sir(uint8_t byte_val);
    void strobe(uint16_t speed, uint16_t count);
    void throb(CLOCK_DIR dir = CLOCK_DIR::CW, uint8_t pos = (SIGN_COLS/2)-2, uint16_t speed = 65, uint16_t revolutions = 10);
    void time(uint16_t seconds = 10);
};

#endif
