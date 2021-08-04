
typedef struct {
  uint8_t length;
  uint8_t cols[5];  // TODO: FIXME because this wants to be variable size one day, which is the whole point of having a flippin struct with length
} GLYPH;

GLYPH glyph(char ch);
GLYPH single_digit(uint8_t dig); // dig must be between 0 and 9
uint16_t text_length(const char *str);
