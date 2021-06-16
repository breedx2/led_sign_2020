#include <Arduino.h>
#include "sign_hardware.h"

void setup(){
	Serial.begin(115200);
	init_sign_hardware();
	Serial.println("It is alive. Die now.");
}

void loop(){
	Serial.print("on3...");
	row_on(3);
	delay(500);
	Serial.println("off3...");
	row_off(3);
	delay(500);
}
