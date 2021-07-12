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
  sc.rid("OMG LOL WTF", 250);
  delay(1000);
  sc.riu("this is a thing", 50);
  delay(1000);
  sc.rid("[[ Here we are ]]", 10);
  delay(1000);
  sc.riu("aGaIN 2 tHriV3", 10);
  delay(15000);



  sc.criu("LET'S GO!", 15, RIGHT);
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
  sc.time(10);
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
