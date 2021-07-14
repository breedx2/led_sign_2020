
#ifndef SIGN_H
#define SIGN_H 1

#include <functional>
#include "sign_memory.h"

#define SIGN_COLS 145

class Sign {

  public:
    void all_on();
    void all_off();
    void clear();
    void col(uint8_t colnum, uint8_t value);
    void blit(uint8_t offset, uint8_t *cols, uint8_t length);
    uint8_t get_col(uint8_t colnum);
    void invert();
    void on(uint8_t col, uint8_t rownum);
    void off(uint8_t col, uint8_t rownum);
    void roll_down(std::function<SIGN_ROW(SIGN_ROW)> first_row_fn);
    void roll_up(std::function<SIGN_ROW(SIGN_ROW)> last_row_fn);
    void shift_right();
};

#endif
