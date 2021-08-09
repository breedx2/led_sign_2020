
#include <Arduino.h>
#include "mbedtls/base64.h"
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
  Serial.println("Opening ControlSocket connection...");
  esp_err_t rc = esp_websocket_client_start(ws);
  if(rc != ESP_OK){
    Serial.printf("Error starting ws: %d\r\n", rc);
  }
}

void ControlSocket::sendAuth(){
  char buff[100];
  memset(buff, 0, 100);
  sprintf(buff, "id:%s\r\n", SIGN_TOKEN);
  // Serial.printf("(%d) Sending auth string: %s %d\r\n", (uintptr_t)ws, buff, strlen(buff));
  esp_websocket_client_send_text(ws, buff, strlen(buff), portMAX_DELAY);
}

void ControlSocket::disconnected(){
  Serial.println("WEBSOCKET_EVENT_DISCONNECTED");
  // Keep ws forever...the framework reconnects every 10s anyway.
  // ws = NULL;
}

void ControlSocket::dump(){
  Serial.println("Performing a memory dump");
  uint8_t buff[7*BYTES_PER_ROW];
  memset(buff, 0, 7*BYTES_PER_ROW);
  auto rc = signCommands.dump(buff);

  size_t outlen;
  mbedtls_base64_encode(NULL, 0, &outlen, (unsigned char*)buff, 7*BYTES_PER_ROW);
  unsigned char sendbuff[outlen+5];
  memcpy((char*)sendbuff, "dump:", 5);

  mbedtls_base64_encode(sendbuff+5, outlen, &outlen,(unsigned char*)buff, 7*BYTES_PER_ROW);
  esp_websocket_client_send_text(ws, (const char*)sendbuff, outlen+5, portMAX_DELAY);
}

static void ws_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    esp_websocket_event_data_t *data = (esp_websocket_event_data_t *)event_data;
    // Serial.printf("SEE WS EVENT YAY! (%d)\r\n", (uintptr_t)data->user_context);
    ControlSocket *cs = (ControlSocket*)data->user_context;
    switch (event_id) {
    case WEBSOCKET_EVENT_CONNECTED:
        Serial.printf("WEBSOCKET_EVENT_CONNECTED (%d) (%d)\r\n", (uintptr_t)event_data, (uintptr_t)data->user_context);
        cs->sendAuth();
        break;
    case WEBSOCKET_EVENT_DISCONNECTED:
        cs->disconnected();
        break;
    case WEBSOCKET_EVENT_DATA:
        Serial.printf("WEBSOCKET_EVENT_DATA, opcode = %d\r\n", data->op_code);

        if (data->op_code == 0x08 && data->data_len == 2) {
            Serial.printf("Received closed message with code=%d\r\n", 256*data->data_ptr[0] + data->data_ptr[1]);
        }
        else if (data->op_code == 0x08) {
          Serial.printf("Receied opcode 0x08 with data length = %d\r\n", data->data_len);
        }
        else if (data->op_code == 0x01) { // Text frame
            Serial.printf("Received=%.*s\r\n", data->data_len, (char *)data->data_ptr);
            if(strncmp((char *)data->data_ptr, "dump\r\n", 6) == 0){
              cs->dump();
            }
        }
        Serial.printf("Total payload length=%d, data_len=%d, current payload offset=%d\r\n", data->payload_len, data->data_len, data->payload_offset);
        // xTimerReset(shutdown_signal_timer, portMAX_DELAY);
        break;
    case WEBSOCKET_EVENT_ERROR:
        Serial.println("WEBSOCKET_EVENT_ERROR");
        break;
    }
}
