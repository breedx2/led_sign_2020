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
  sc.criu("...STARTING TEST...", 10);
  delay(250);
  sc.criu("LET'S GO!", 25, RIGHT);
  delay(500);
  // sc.ctr(151, 25);
  // delay(200);
  //
  // sc.left("left align", true);
  // delay(300);
  // sc.right("right align", true);
  // delay(300);
  // sc.center("=[ centered ]=", true);
  // delay(300);
  // sc.center("=[ inverted ]=", true);
  // sc.invert();
  // delay(300);
  // sc.clwipe(10);
  // delay(300);
  // sc.time(10);
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
