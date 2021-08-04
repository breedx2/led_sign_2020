
#include <Arduino.h>
#include "sign_memory.h"
#include "sign_hardware.h"
#include "sign_updater.h"

volatile int rownum = 0;
hw_timer_t *timer = NULL;

void onTimer(){
  row_off(rownum);
  rownum++;
  if(rownum > 6) rownum = 0;
  SIGN_ROW row = get_mem_row(rownum);
  shift_row(row);
  row_on(rownum);
}

void start_updater(){
  timer = timerBegin(0, 80, true);
	timerAttachInterrupt(timer, onTimer, true);
	timerAlarmWrite(timer, 1000, true);
	timerAlarmEnable(timer);
}

void stop_updater(){
  if (timer != NULL) {
    timerAlarmDisable(timer);
    timerDetachInterrupt(timer);
    timerEnd(timer);
    timer = NULL;
  }
}
