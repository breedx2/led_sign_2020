 #include <Arduino.h>
 #include "sign_memory.h"
 #include "sign_hardware.h"
 #include "sign_updater.h"
 #include "font5x7.h"
 #include "sign_utils.h"
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
  sc.criu("...STARTING TEST...", 5);
  delay(250);
  sc.criu("LET'S GO!", 15, RIGHT);
  delay(1000);
  sign.clear();

  // printer.print("LET'S GO!", 46);
  // printer.print("E", 46);
  // dump_mem_serial();
  // delay(1000);
  // // sign.clear();
  // printer.print("E", 52);
  // dump_mem_serial();
  // delay(100000);
  // delay(100000);
  // delay(100000);
  // sign.clear();
  // printer.print("E", 52);
  // dump_mem_serial();
  // delay(1000);

  // Serial.printf("Now setting special col\r\n");
  // sign.col(45, 192);
  // delay(3000);

  // sc.ctr(151, 25);
  // delay(200);
  //
  sc.left("left align", true);
  delay(500);
  sc.right("right align", true);
  delay(500);
  sc.center("=[ centered ]=", true);
  delay(500);
  sc.center("=[ inverted ]=", true);
  sc.invert();
  delay(300);
  sc.clwipe(10);
  delay(300);
  sc.time(10);
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
