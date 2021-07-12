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
  sc.criu("...STARTING TEST...", 2);
  delay(250);
  sc.criu("LET'S GO!", 5, RIGHT);
  delay(1000);
  sign.clear();
  sc.ctr(150);
  sc.left("left align", true);
  delay(500);
  sc.right("right align", true);
  delay(500);
  sc.center("=[ centered ]=", true);
  delay(500);
  sc.center("=[ inverted ]=", true);
  sc.invert();
  delay(300);
  sc.clwipe(5);
  delay(300);
  sc.left("ABCDEFGHIJKLMNOPQRSTUVWX");
  sc.crwipe(5);
  delay(300);
  sc.left("LINES CAN JUST FALL DOWN");
  delay(666);
  sc.rod(150);
  delay(500);
  sc.left("LINES CAN ALSO FLOAT UP!");
  delay(666);
  sc.rou(150);
  delay(500);

  sc.left("ABCDEFGHIJKLMNOPQRSTUVWX");
  delay(500);
  sc.rid("Attack from above!", 150);
  delay(500);
  sc.riu("ROLLIN' ON UP FROM BELOW", 50);
  delay(500);
  sc.riu("//////\\\\\\\\\\\\", 100);
  sc.riu("\\/////\\\\\\\\\\\\", 75);
  sc.riu("\\\\////\\\\\\\\\\\\", 50);
  sc.riu("\\\\\\///\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\//\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\/\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\/\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\//\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\////\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\/////\\\\", 50);
  sc.riu("\\\\\\\\\\\\//////\\", 75);
  sc.riu("\\\\\\\\\\\\///////", 100);
  delay(500);

  sc.time(10);
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
