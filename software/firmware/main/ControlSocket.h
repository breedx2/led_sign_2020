#ifndef CONTROL_SOCKET_H
#define CONTROL_SOCKET_H 1

#define WS_SERVER_URI "ws://192.168.66.8:8080/sign"

#include "SignCommands.h"

class ControlSocket {

private:
  SignCommands &signCommands;
  esp_websocket_client_handle_t ws;
  bool authed;

public:
  ControlSocket(SignCommands &sc) : signCommands(sc){
    ws = NULL;
    authed = false;
  }
  void start();
  void sendAuth();
  void disconnected();
  void dump();
};

#endif
