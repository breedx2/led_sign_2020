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
#include "SerialCommander.h"

Sign sign;
SignPrinter printer = SignPrinter(sign);
SignCommands sc = SignCommands(sign, printer);
Demo demo = Demo(sc, printer);
int loopcounter;
uint8_t offset = 0;

SerialCommander ser = SerialCommander();

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("LED sign is alive.");

  printer.center("* hello world *", true);
  start_updater();
  enable_output();

	delay(1000);
	sc.clear();
	// memset(cmdbuff, 0, 1024);
	// Serial.print("sign > ");
}

void loop(){
	if(!Serial.available()){
		delay(25);
	}

	if(ser.loop()){
		char cmd[1024];
		memset(cmd, 0, 1024);
		uint16_t len = ser.drain(cmd, 1023);
		Serial.printf("OUTER GOT COMMAND: '%s'\r\n", cmd);
	}

  // Serial.printf("LOOP %d chillin offset = %d\r\n", loopcounter++, offset);
}
