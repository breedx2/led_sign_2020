#include <time.h>
#include <algorithm>
#include <tuple>
#include <vector>
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
  if(dir == DIRECTION::RIGHT){
    reverse_buffer(buff, col_num);
    index = SIGN_COLS - index - 1;
  }
  sign.clear();
  for(uint8_t i = 0; i < col_num; i++){
    uint8_t col = buff[i];
    index += (dir == DIRECTION::LEFT) ? 1 : -1;
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

//char-wise roll in down at speed.
void SignCommands::krid(const char *str, uint16_t speed, bool clear_first){
  if(clear_first) clear();
  roll_chars(str, speed, [](uint8_t col, uint8_t row){
    return col >> (6-row);
  });
}

// char-wise roll in up at speed.
void SignCommands::kriu(const char *str, uint16_t speed, bool clear_first){
  if(clear_first) clear();
  roll_chars(str, speed, [](uint8_t col, uint8_t row){
    return col << (6-row);
  });
}

//char-wise roll out down at speed.
void SignCommands::krod(const char *str, uint16_t speed, bool clear_first){
  if(clear_first) clear();
  center(str);
  roll_chars(str, speed, [](uint8_t col, uint8_t row){
    return col << (row+1);
  });
}

// char-wise roll out up at speed.
void SignCommands::krou(const char *str, uint16_t speed, bool clear_first){
  if(clear_first) clear();
  center(str);
  roll_chars(str, speed, [](uint8_t col, uint8_t row){
    return col >> (row+1);
  });
}


// lazer scanner baby, cheese city
// poorly inspired by the "TANNING INVITATIONAL" pool party lazer text in Real Genius
void SignCommands::lazr(const char *str){
   sign.clear();
   uint8_t buff[SIGN_COLS];
   uint8_t bufflen = printer.print_mem(str, buff, SIGN_COLS);
   uint8_t offset = std::max(0,int((SIGN_COLS - bufflen) / 2));
   auto swipe_pass = [&](uint8_t speed){
       uint8_t h = (bufflen/2);
       for(int i=0; i < h; i++){
           sign.col(offset+i, buff[i]);
           sign.col(offset+i+h, buff[i+h] ^ 0xFF);
           sign.col(offset+bufflen-1-i, buff[bufflen-1-i]);
           sign.col(offset+bufflen-1-h-i, buff[bufflen-1-h-i] ^ 0xFF);
           delay(speed);
           sign.col(offset+i, 0);
           sign.col(offset+i+h, 0);
           sign.col(offset+bufflen-1-i, 0);
           sign.col(offset+bufflen-1-h-i, 0);
       }
   };
   std::vector<uint8_t> speeds{11,9,7,6,5,5,5,5,5,3,3,2,2,1};
   for(uint8_t t: speeds){
     swipe_pass(t);
   }
   for(uint8_t i : std::vector<uint8_t>{4,3,2,1}){
     for(uint8_t j = 0; j < 4; j++){
         printer.center(str);
         delay(13*i);
         printer.clear();
         delay(13*i);
     }
   }
   printer.center(str);
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
  uint8_t pad = 1 + ((SIGN_COLS - col_num) / 2);
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

// message shift in left (from the right)
void SignCommands::msl(const char *str, uint16_t speed){
  for(uint8_t i = 0; i < strlen(str); i++){
      char ch =  str[i];
      GLYPH g = glyph(ch);
      for(uint8_t j = 0; j < g.length; j++){
        sir(g.cols[j]);
        delay(speed);
      }
      if(ch != ' '){
        sign.shift_left();
        delay(speed);
      }
  }
  for(uint8_t i = 0; i < SIGN_COLS; i++){
    sign.shift_left();
    delay(speed);
  }
}

// message shift in right (from the left)
void SignCommands::msr(const char *str, uint16_t speed){
  for(int i = strlen(str)-1; i >= 0; i--){
      char ch =  str[i];
      GLYPH g = glyph(ch);
      for(int j = g.length-1; j >= 0; j--){
        sil(g.cols[j]);
        delay(speed);
      }
      if(ch != ' '){
        sil(0x00);
        delay(speed);
      }
  }
  for(uint8_t i = 0; i < SIGN_COLS; i++){
    sign.shift_right();
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

void SignCommands::on(uint8_t col, uint8_t rownum){
  sign.on(col, rownum);
}

void SignCommands::off(uint8_t col, uint8_t rownum){
  sign.off(col, rownum);
}

// random in (fade in).  Clears sign first.
void SignCommands::randi(const char *str, uint16_t speed){
  sign.clear();
  randt(str, speed);
}

// random dissolve (fade out)
// basically just transition to a blank screen!
void SignCommands::rando(uint16_t speed){
  randt("", speed);
}

// Random pixel-wise transition to this new string
void SignCommands::randt(const char *str, uint16_t speed){
  uint8_t buff[SIGN_COLS];
  memset(buff, 0x00, SIGN_COLS);
  printer.print_mem(str, buff, SIGN_COLS, true);
  std::vector<std::tuple<uint8_t,uint8_t,uint8_t>> remaining;
  for(uint8_t col = 0; col < SIGN_COLS; col++){
    uint8_t cur_col = sign.get_col(col);
    uint8_t new_col = buff[col];
    for(uint8_t row = 0; row < 7; row++){
      uint8_t bitmask = (1 << row);
      if ((cur_col & bitmask) && ((new_col & bitmask) != bitmask)){
        remaining.push_back(std::make_tuple(col, row, 0));
      }
      if ((new_col & bitmask) && ((cur_col & bitmask) != bitmask)){
        remaining.push_back(std::make_tuple(col, row, 1));
      }
    }
  }
  std::random_shuffle ( remaining.begin(), remaining.end() );
  for (auto &t : remaining) {
    auto col = std::get<0>(t);
    auto row = std::get<1>(t);
    auto value = std::get<2>(t);
    if(value) sign.on(col, row);
    else sign.off(col, row);
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

// Char-wise column roller (private, used by kriu etc)
// TODO: add alignment, this currently assumes center
void SignCommands::roll_chars(const char *str, uint16_t speed, std::function<uint8_t(uint8_t, uint8_t)>colmaker){

  uint8_t bufflen = text_length(str);
  uint8_t offset = std::max(0,int((SIGN_COLS - bufflen) / 2));

  for(uint8_t i = 0; i < strlen(str); i++){
    char ch = str[i];
    GLYPH g = glyph(ch);
    if(ch != ' '){
      for(uint8_t row = 0; row < 7; row++){
        for(uint8_t colnum = 0; colnum < g.length; colnum++){
          sign.col(offset+colnum, colmaker(g.cols[colnum],row));
        }
        delay(speed);
      }
      offset = offset + 1;
    }
    offset = offset + g.length;
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

// column-wise wipe in message from right
// TODO: message alignment parameter
void SignCommands::rwipe(const char *str, uint16_t speed){
  uint8_t buff[SIGN_COLS];
  uint8_t col_num = printer.print_mem(str, buff, SIGN_COLS);
  uint8_t pad = (SIGN_COLS - col_num) / 2;
  uint8_t col = SIGN_COLS;
  while(col >= SIGN_COLS - pad){
    sign.col(col, 0x00);
    col--;
    delay(speed);
  }
  for(short i = col_num-1; i >= 0; i--){
    sign.col(col--, buff[i]);
    delay(speed);
  }
  while(col > 1){
    sign.col(col, 0x00);
    col--;
    delay(speed);
  }
}

// shift in a byte from the left
void SignCommands::sil(uint8_t byte_val){
  sign.shift_right();
  sign.col(2, byte_val);
}

// shift in a byte from the right
void SignCommands::sir(uint8_t byte_val){
  sign.shift_left();
  sign.col(SIGN_COLS-1, byte_val);
}

void SignCommands::strobe(uint16_t speed, uint16_t count){
  for(uint16_t i = 0 ; i < count; i++){
    sign.all_on();
    delay(speed);
    sign.all_off();
    delay(speed);
  }
}

void SignCommands::throb(CLOCK_DIR dir, uint8_t pos, uint16_t speed, uint16_t revolutions){
  const char cw[] = {'|', '/', '-', '\\'};
  const char ccw[] = {'|', '\\', '-', '/'};
  const char *chars = (dir == CLOCK_DIR::CW) ? cw : ccw;
  for(uint16_t rev = 0; rev < revolutions; rev++){
      for(uint8_t i = 0 ; i < 4; i++){
        printer.char_at_pos(chars[i], pos);
        delay(speed);
      }
  }
  printer.char_at_pos(' ', pos);
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
