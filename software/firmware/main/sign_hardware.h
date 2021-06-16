
#define BYTES_PER_ROW 19

void init_sign_hardware();
void enable_output();
void disable_output();
void row_on(uint8_t row);
void row_off(uint8_t row);
void all_rows_off();
void shift_row(uint8_t *row);
