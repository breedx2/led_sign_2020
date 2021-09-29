#include <Arduino.h>
#include "esp_websocket_client.h"
#include "sign_memory.h"
#include "sign_hardware.h"
#include "sign_updater.h"
#include "font5x7.h"
#include "sign_utils.h"
#include "ControlSocket.h"
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
ControlSocket controlSocket = ControlSocket(sc, parser);

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("LED sign is alive.");

  printer.center("* noisybox.net *", true);
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
		ser.drain(cmd, 1023); // read command
		// Serial.printf("OUTER GOT COMMAND: '%s'\r\n", cmd);
		if(strncmp(cmd, "demo", 4) == 0){
			return demo.run();
		}
		if(strncmp(cmd, "wifi on", 7) == 0){
			netTools.initWifi();
			return;
		}
		if(strncmp(cmd, "ntp", 3) == 0){
			int daylightOffset_sec = 3600;
			const char* ntpServer = "pool.ntp.org";
			const long gmtOffset_sec = -28800;
			configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
		}
		if(strncmp(cmd, "ws", 2) == 0){
			controlSocket.start();
		}
		parser.parse(cmd);
	}
}
