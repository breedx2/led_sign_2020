
#ifndef SIGN_COMMANDS_H
#define SIGN_COMMANDS_H 1

class SignCommands {
  private:
    Sign &sign;
    SignPrinter &printer;
  public:
    SignCommands(Sign &sign, SignPrinter &printer): sign(sign), printer(printer){}
    void clwipe(uint16_t speed);
    void time(uint16_t seconds = 10);
};

#endif
