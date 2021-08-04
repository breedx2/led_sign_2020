#include <Arduino.h>
#include "sign_memory.h"
#include "sign_hardware.h"
#include "sign_updater.h"
#include "font5x7.h"
#include "sign_utils.h"
#include "CommandParser.h"
#include "Demo.h"
#include "SerialCommander.h"
#include "Sign.h"
#include "SignPrinter.h"
#include "SignCommands.h"
#include "NetTools.h"

Sign sign;
SignPrinter printer = SignPrinter(sign);
SignCommands sc = SignCommands(sign, printer);
Demo demo = Demo(sc, printer);

SerialCommander ser = SerialCommander();
CommandParser parser = CommandParser(sc, printer);
NetTools netTools = NetTools();

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("LED sign is alive.");

  printer.center("* hello world *", true);
  start_updater();
  enable_output();

	delay(500);
	sc.clear();
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
		if(strncmp(cmd, "demo", 4) == 0){
			return demo.run();
		}
		if(strncmp(cmd, "wifi on", 7) == 0){
			netTools.initWifi();
			return;
		}
		parser.parse(cmd);
	}
}
