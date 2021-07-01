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
	delay(500);

  //
  // uint8_t rowData[] = {
	//  		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	//  };
  // shift_row(rowData);
  // row_on(7);


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
