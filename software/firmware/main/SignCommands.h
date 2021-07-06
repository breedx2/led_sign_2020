
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

class SignCommands {
  private:
    Sign &sign;
  public:
    SignCommands(Sign &sign): sign(sign) {}
    void clwipe(uint16_t speed);
};

#endif
