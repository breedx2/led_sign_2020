
#define BYTES_PER_ROW 19

typedef uint8_t* SIGN_ROW;
typedef uint8_t** SIGN_MEM;

SIGN_MEM new_sign_memory();
SIGN_ROW get_mem_row(uint8_t rownum);
