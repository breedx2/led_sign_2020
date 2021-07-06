 #include <Arduino.h>
 #include "sign_memory.h"
 #include "sign_hardware.h"
 #include "sign_updater.h"
 #include "font5x7.h"
 #include "Sign.h"

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("It is alive. Die now.");

  for(uint8_t i = 0; i < 7; i++){

    SIGN_ROW row = get_mem_row(i);

    for(uint8_t c = 0; c < BYTES_PER_ROW; c++){
      row[c] = c;
    }
  }
  start_updater();
  enable_output();
}

Sign sign = Sign();
int loopcounter;
uint8_t offset = 0;

void loop(){
  Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);

  GLYPH g = glyph('G');
  if(offset > 0){
    sign.col(offset-1, 0);
  }
  else {
    sign.col(SIGN_COLS-1, 0);
  }
  for(uint8_t i = 0; i < g.length; i++){

    uint8_t glyph_col = g.cols[i];
    sign.col( offset + i, glyph_col);
  }

  offset++;
  if( offset >= SIGN_COLS){
    offset = 0;
  }
  sign.col(2, 0xff);
  sign.col(SIGN_COLS-1, 0xff);
  delay(25);
}
