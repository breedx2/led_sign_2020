#ifndef CONTROL_SOCKET_H
#define CONTROL_SOCKET_H 1

#define WS_SERVER_URI "ws://192.168.66.8:8080/sign"


class ControlSocket {

private:
  esp_websocket_client_handle_t ws;
  bool authed;

public:
  ControlSocket(){
    ws = NULL;
    authed = false;
  }
  void start();
  void sendAuth();
};

#endif
