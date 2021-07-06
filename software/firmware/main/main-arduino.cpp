 #include <Arduino.h>
 #include "sign_memory.h"
 #include "sign_hardware.h"
 #include "sign_updater.h"
 #include "font5x7.h"
 #include "Sign.h"
 #include "SignPrinter.h"

 Sign sign;
 SignPrinter printer = SignPrinter(sign);
 int loopcounter;
 uint8_t offset = 0;

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("It is alive. Die now.");

  // for(uint8_t i = 0; i < 7; i++){
  //
  //   SIGN_ROW row = get_mem_row(i);
  //
  //   for(uint8_t c = 0; c < BYTES_PER_ROW; c++){
  //     row[c] = c;
  //   }
  // }
  printer.clear();
  printer.print("hello world how are you?", 20);
  start_updater();
  enable_output();
}

void loop(){
  delay(2000);
  printer.clear();
  printer.left("i'm ok");
  delay(2000);
  printer.clear();
  printer.right("you're ok");
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
  //
  // GLYPH g = glyph('o');
  // sign.blit(24, g.cols, g.length);
  //
  // offset++;
  // if( offset >= SIGN_COLS){
  //   offset = 0;
  // }
  // delay(150);
}
