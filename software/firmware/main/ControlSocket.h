#ifndef CONTROL_SOCKET_H
#define CONTROL_SOCKET_H 1

#define WS_SERVER_URI "ws://192.168.66.8:8080/sign"

#include "SignCommands.h"
#include "CommandParser.h"

class ControlSocket {

private:
  SignCommands &signCommands;
  CommandParser &parser;
  esp_websocket_client_handle_t ws;
  bool authed;

public:
  ControlSocket(SignCommands &sc, CommandParser &cp) : signCommands(sc), parser(cp){
    ws = NULL;
    authed = false;
  }
  void start();
  void sendAuth();
  void disconnected();
  void dump();
  // void bufferCmd(const char *cmd);
  void parseCmd(const char *cmd, size_t len);
};

#endif
