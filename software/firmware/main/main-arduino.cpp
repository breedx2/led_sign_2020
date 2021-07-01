 #include <Arduino.h>
 #include "sign_memory.h"
 #include "sign_hardware.h"
 #include "sign_updater.h"

void setup(){
	Serial.begin(115200);

	init_sign_hardware();

	Serial.println("It is alive. Die now.");

  for(uint8_t i = 0; i < 7; i++){
    SIGN_ROW row = get_mem_row(i);
    for(uint8_t c = 0; c < BYTES_PER_ROW; c++){
      row[c] = c;
    }
  }
  start_updater();
  enable_output();
}

int loopcounter;

void loop(){
  Serial.printf("LOOP %d chillin.\r\n", loopcounter++);
  for(uint8_t i = 0; i < 7; i++){
    SIGN_ROW row = get_mem_row(i);
    for(uint8_t c = 0; c < BYTES_PER_ROW; c++){
      row[c] = row[c] + i + 1;
    }
  }
  delay(150);
}
