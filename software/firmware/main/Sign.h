
#ifndef SIGN_H

#define SIGN_COLS 145

class Sign {

  public:
    void col(uint8_t colnum, uint8_t value);
    void blit(uint8_t offset, uint8_t *cols, uint8_t length);
};

#endif
