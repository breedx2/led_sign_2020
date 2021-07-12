
#ifndef SIGN_H
#define SIGN_H 1

#include <functional>
#include "sign_memory.h"

#define SIGN_COLS 145

class Sign {

  public:
    void clear();
    void col(uint8_t colnum, uint8_t value);
    void blit(uint8_t offset, uint8_t *cols, uint8_t length);
    void invert();
    void roll_down(std::function<SIGN_ROW(SIGN_ROW)> first_row_fn);
    void roll_up(std::function<SIGN_ROW(SIGN_ROW)> last_row_fn);
};

#endif
