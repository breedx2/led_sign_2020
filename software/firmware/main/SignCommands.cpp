#include <string.h>
#include <time.h>
#include <Arduino.h>
#include "Sign.h"
#include "SignPrinter.h"
#include "font5x7.h"
#include "sign_utils.h"
#include "SignCommands.h"

void SignCommands::center(const char *str, bool clear_first){
  printer.center(str, clear_first);
}

void SignCommands::clear(){
  sign.clear();
}

void SignCommands::crid(const char *str, uint16_t speed, DIRECTION dir){
  cri_x(str, speed, dir, [](uint8_t col, uint8_t bits){
    return col >> (6-bits);
  });
}

void SignCommands::criu(const char *str, uint16_t speed, DIRECTION dir){
  cri_x(str, speed, dir, [](uint8_t col, uint8_t bits){
    return col << (6-bits);
  });
}

void SignCommands::cri_x(const char *str, uint16_t speed, DIRECTION dir, std::function<uint8_t(uint8_t, uint8_t)> shifter){
  uint8_t buff[SIGN_COLS];
  uint8_t col_num = printer.print_mem(str, buff, SIGN_COLS);
  uint8_t index = (SIGN_COLS-col_num)/2;
  if(dir == RIGHT){
    reverse_buffer(buff, col_num);
    index = SIGN_COLS - index - 1;
  }
  sign.clear();
  for(uint8_t i = 0; i < col_num; i++){
    uint8_t col = buff[i];
    index += (dir == LEFT) ? 1 : -1;
    if(col == 0x00) continue;
    for(uint8_t bits = 0; bits < 7; bits++){
      sign.col(index, shifter(col,bits));
      delay(speed);
    }
  }
}

// Counter counts up centered as fast as possible at speed
void SignCommands::ctr(uint16_t num, uint16_t speed){
  char buff[50];
  sign.clear();
  for(uint16_t i = 0; i < num; i++){
    sprintf(buff, "%d", i);
    printer.center(buff);
    delay(speed);
  }
}

// column-wise wipe clear from left
void SignCommands::clwipe(uint16_t speed){
  for(int i=2; i < SIGN_COLS; i++){
    sign.col(i, 0x00);
    delay(speed);
  }
}

// column-wise wipe clear from right
void SignCommands::crwipe(uint16_t speed){
  for(int i = SIGN_COLS; i >= 2; i--){
    sign.col(i, 0x00);
    delay(speed);
  }
}

void SignCommands::invert(){
  sign.invert();
}

// show message left-aligned
void SignCommands::left(const char *str, bool clear_first){
  printer.left(str, clear_first);
}

// column-wise wipe in message from left
// TODO: alignment parameter
void SignCommands::lwipe(const char *str, uint16_t speed){
  uint8_t buff[SIGN_COLS];
  uint8_t col_num = printer.print_mem(str, buff, SIGN_COLS);
  uint8_t pad = (SIGN_COLS - col_num) / 2;
  uint8_t col = 2;
  while(col < pad){
    sign.col(col, 0x00);
    col++;
    delay(speed);
  }
  for(uint8_t i = 0; i < col_num; i++){
    sign.col(pad + i, buff[i]);
    col++;
    delay(speed);
  }
  while(col < SIGN_COLS){
    sign.col(col, 0x00);
    col++;
    delay(speed);
  }
}

// display message word-wise in center of display
void SignCommands::mwc(const char *str, uint16_t speed){
  char buff[128];
  memset(buff, 0x00, 128);
  strncpy(buff, str, 127);
  char *word = strtok(buff, " ");
  while(word != NULL){
    printer.center(word, true);
    delay(speed);
    word = strtok(NULL, " ");
  }
}

// message wipe out in
void SignCommands::mwoi(uint16_t speed){
  uint8_t start = 2;
  uint8_t end = SIGN_COLS - 1;
  while((sign.get_col(start) == 0) && (start < end)){
    start++;
  }
  while((sign.get_col(end) == 0) && (end > start)){
    end--;
  }
  while(start <= end){
    sign.col(start, 0);
    sign.col(end, 0);
    start++;
    end--;
    delay(speed);
  }
}

// message wipe out out
void SignCommands::mwoo(uint16_t speed){
  uint8_t half = int(SIGN_COLS/2)+1;
  for(uint8_t i = 0; i < half; i++){
      sign.col(half-i, 0);
      sign.col(half+i, 0);
      delay(speed);
  }
}

// roll message in downwards
void SignCommands::rid(const char *str, uint16_t speed){
  uint8_t buff[SIGN_COLS];
  uint8_t col_num = printer.print_mem(str, buff, SIGN_COLS);
  for(int i = 0; i < 7; i++){
    uint8_t mask = 1 << (6 - i);
    sign.roll_down([](SIGN_ROW row){
      memset(row, 0x00, BYTES_PER_ROW);
      return row;
    });
    uint8_t offset = (SIGN_COLS-col_num)/2;
    for(int col = 0; col < col_num; col++){
      if (buff[col] & mask){
        sign.on(offset+col+2, 0);
      }
      else{
        sign.off(offset+col+2, 0);
      }
    }
    delay(speed);
  }
}

// show message right-aligned
void SignCommands::right(const char *str, bool clear_first){
  printer.right(str, clear_first);
}

// roll message in upwards
void SignCommands::riu(const char *str, uint16_t speed){
  uint8_t buff[SIGN_COLS];
  uint8_t col_num = printer.print_mem(str, buff, SIGN_COLS);
  for(int i = 6; i >= 0; i--){
    uint8_t mask = 1 << (6 - i);
    sign.roll_up([](SIGN_ROW row){
      memset(row, 0x00, BYTES_PER_ROW);
      return row;
    });
    uint8_t offset = (SIGN_COLS-col_num)/2;
    for(int col = 0; col < col_num; col++){
      if (buff[col] & mask){
        sign.on(offset+col+2, 6);
      }
      else{
        sign.off(offset+col+2, 6);
      }
    }
    delay(speed);
  }
}

// line-wise roll-off downward
void SignCommands::rod(uint16_t speed){
  for(uint8_t i = 0; i < 7; i++){
    sign.roll_down([](SIGN_ROW row){
      return clear_row(row);
    });
    delay(speed);
  }
}

// line-wise roll-off upward
void SignCommands::rou(uint16_t speed){
  for(uint8_t i = 0; i < 7; i++){
    sign.roll_up([](SIGN_ROW row){
      return clear_row(row);
    });
    delay(speed);
  }
}

// format is like 'Sun Jan 01 00:00:00'
void SignCommands::time(uint16_t seconds){
  printer.clear();
  uint16_t elapsed = 0;

  time_t now;
  struct tm parts;
  char buff[20];
  while(elapsed < seconds*1000){
    memset(buff, 0, 20);
    ::time(&now);
    localtime_r(&now, &parts);
    strftime(buff, 20, "%a %b %d %H:%M:%S", &parts);
    printer.center(buff, true);
    delay(250);
    elapsed += 250;
  }
}
