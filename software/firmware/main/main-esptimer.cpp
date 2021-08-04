#include "esp_timer.h"

volatile int ctr;

void onTimer();

esp_timer_handle_t timer;
const esp_timer_create_args_t timerParameters = { .callback = reinterpret_cast<esp_timer_cb_t>(&onTimer) };

void onTimer(){
		ctr++;
}

void setup(){
	Serial.begin(115200);

	esp_timer_create(&timerParameters, &timer);
  esp_timer_start_periodic(timer, 1000000);

	Serial.println("It is alive. Die now.");
}

int loopcounter;
void loop(){

  Serial.printf("loop %d counter = %d\r\n", loopcounter++, ctr);
	delay(500);
}
