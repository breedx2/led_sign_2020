
#ifndef SIGN_H
#define SIGN_H 1

#define SIGN_COLS 145

class Sign {

  public:
    void clear();
    void col(uint8_t colnum, uint8_t value);
    void blit(uint8_t offset, uint8_t *cols, uint8_t length);
    void invert();
};

#endif
