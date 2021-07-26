#include <Arduino.h>
#include "sign_memory.h"
#include "sign_hardware.h"
#include "sign_updater.h"
#include "font5x7.h"
#include "sign_utils.h"
#include "Sign.h"
#include "SignPrinter.h"
#include "SignCommands.h"
#include "Demo.h"

Sign sign;
SignPrinter printer = SignPrinter(sign);
SignCommands sc = SignCommands(sign, printer);
Demo demo = Demo(sc, printer);
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
	demo.run();
  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
