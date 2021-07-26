#ifndef SERIAL_COMMANDER_H
#define SERIAL_COMMANDER_H 1

void show_prompt();

class SerialCommander {
private:
  char cmdbuff[1024];
  uint16_t cmdbuff_len;
  bool have_cmd;
  bool prompted;

public:
  SerialCommander(){
    cmdbuff_len = 0;
    memset(cmdbuff, 0, 1024);
    prompted = false;
    have_cmd = false;
  }
  bool ready();
  bool loop();
  uint16_t drain(char *buff, uint16_t len);
};

#endif
