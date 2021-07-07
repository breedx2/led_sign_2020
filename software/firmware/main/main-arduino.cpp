 #include <Arduino.h>
 #include "sign_memory.h"
 #include "sign_hardware.h"
 #include "sign_updater.h"
 #include "font5x7.h"
 #include "Sign.h"
 #include "SignPrinter.h"
 #include "SignCommands.h"

 Sign sign;
 SignPrinter printer = SignPrinter(sign);
 SignCommands sc = SignCommands(sign, printer);
 int loopcounter;
 uint8_t offset = 0;

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("It is alive. Die now.");

  printer.center("* hello world *", true);
  start_updater();
  enable_output();
}

void loop(){
  delay(750);
  printer.left("left align", true);
  delay(750);
  printer.clear();
  printer.right("right align", true);
  delay(750);
  printer.center("=[ centered ]=", true);
  delay(750);
  printer.center("=[ inverted ]=", true);
  sign.invert();
  delay(500);
  sc.clwipe(10);
  sc.time(30);
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
