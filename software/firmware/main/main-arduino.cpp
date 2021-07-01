 #include <Arduino.h>

volatile int ctr;
hw_timer_t *timer = NULL;

void onTimer();

void onTimer(){
		ctr++;
}

void setup(){
	Serial.begin(115200);

	timer = timerBegin(3, 80, true);
	timerAttachInterrupt(timer, onTimer, true);
	timerAlarmWrite(timer, 1000000, true);
	timerAlarmEnable(timer);

	// init_sign_hardware();
	Serial.println("It is alive. Die now.");
	// enable_output();
}

int loopcounter;
void loop(){

  Serial.printf("LOOP%d counter = %d\r\n", loopcounter++, ctr);
	delay(500);

	// uint8_t rowData[] = {
	// 		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	// };
	// shift_row(rowData);
	// Serial.print("on3...");
	// row_on(3);
	// delay(500);
	// Serial.println("off3...");
	// row_off(3);
	// delay(500);
}
