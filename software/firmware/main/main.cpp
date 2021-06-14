#include <Arduino.h>

void setup(){
	Serial.begin(115200);
}

void loop(){
	Serial.println("It is alive. Die now.");
	delay(500);
}
