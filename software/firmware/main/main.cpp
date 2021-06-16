#include <Arduino.h>
#include "sign_hardware.h"

void setup(){
	Serial.begin(115200);
	init_sign_hardware();
	Serial.println("It is alive. Die now.");
	enable_output();
}

void loop(){
	uint8_t rowData[] = {
			1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	};
	shift_row(rowData);
	Serial.print("on3...");
	row_on(3);
	delay(500);
	Serial.println("off3...");
	row_off(3);
	delay(500);
}
