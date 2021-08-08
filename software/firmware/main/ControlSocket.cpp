
#include <Arduino.h>
#include "esp_websocket_client.h"
#include "ControlSocket.h"
#include "secrets.h"

static void ws_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

void ControlSocket::start(){
  if(ws != NULL){
    Serial.printf("ControlSocket already started, skipping");
    return;
  }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
  const esp_websocket_client_config_t ws_cfg = {
    .uri = WS_SERVER_URI,
    .user_context = this,
  };
#pragma GCC diagnostic pop

  Serial.printf("Init ControlSocket ws..., this (%d)\r\n", (uintptr_t)this);
  ws = esp_websocket_client_init(&ws_cfg);
  esp_websocket_register_events(ws, WEBSOCKET_EVENT_ANY, ws_event_handler, (void *)ws);
  Serial.printf("Opening ControlSocket connection (%d)...\r\n", (uintptr_t)ws);
  esp_err_t rc = esp_websocket_client_start(ws);
  if(rc != ESP_OK){
    Serial.printf("Error starting ws: %d\r\n", rc);
  }
}

void ControlSocket::sendAuth(){
  char buff[100];
  memset(buff, 0, 100);
  sprintf(buff, "id:%s\r\n", SIGN_TOKEN);
  Serial.printf("(%d) Sending auth string: %s %d\r\n", (uintptr_t)ws, buff, strlen(buff));
  int rc = esp_websocket_client_send_text(ws, buff, strlen(buff), portMAX_DELAY);
  Serial.printf("We sent %d bytes\r\n", rc);
}

static void ws_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    esp_websocket_event_data_t *data = (esp_websocket_event_data_t *)event_data;
    Serial.printf("SEE WS EVENT YAY! (%d)\r\n", (uintptr_t)data->user_context);
    ControlSocket *cs;
    switch (event_id) {
    case WEBSOCKET_EVENT_CONNECTED:
        Serial.println("WEBSOCKET_EVENT_CONNECTED");
        cs = (ControlSocket*)data->user_context;
        cs->sendAuth();
        break;
    case WEBSOCKET_EVENT_DISCONNECTED:
        Serial.println("WEBSOCKET_EVENT_DISCONNECTED");
        break;
    case WEBSOCKET_EVENT_DATA:
        Serial.println("WEBSOCKET_EVENT_DATA");
        Serial.printf("Received opcode=%d\r\n", data->op_code);
        if (data->op_code == 0x08 && data->data_len == 2) {
            Serial.printf("Received closed message with code=%d\r\n", 256*data->data_ptr[0] + data->data_ptr[1]);
        } else {
            Serial.printf("Received=%.*s\r\n", data->data_len, (char *)data->data_ptr);
        }
        Serial.printf("Total payload length=%d, data_len=%d, current payload offset=%d\r\n", data->payload_len, data->data_len, data->payload_offset);
        // xTimerReset(shutdown_signal_timer, portMAX_DELAY);
        break;
    case WEBSOCKET_EVENT_ERROR:
        Serial.println("WEBSOCKET_EVENT_ERROR");
        break;
    }
}
