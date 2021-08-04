#include <Arduino.h>
#include "WiFi.h"
#include "secrets.h"
#include "sign_updater.h"
#include "NetTools.h"

bool NetTools::initWifi(){
  if(WiFi.status() == WL_CONNECTED){
    return true; //already connected
  }

  // Try pausing our update timer while we get settled on the network...
  stop_updater();
  Serial.println("WIFI ONE");
  WiFi.mode(WIFI_STA);
  Serial.println("WIFI TWO");
  WiFi.begin(LED_WIFI_SSID, LED_WIFI_PASS);
  Serial.println("WIFI FOUR");
  Serial.printf("Connecting to '%s' .", LED_WIFI_SSID);
  Serial.println("WIFI FIVE");
  char throb[] = {'|', '/', '-', '\\', '-'};
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    if(i > 4) i = 0;
    Serial.printf("%c %c%c", 0x08, 0x08, throb[i++]);
    delay(333);
  }
  Serial.println();
  Serial.printf("Connected: %s\r\n", WiFi.localIP().toString().c_str());
  start_updater();
  return true;
}

std::string NetTools::address(){
  if(WiFi.status() == WL_CONNECTED){
    return std::string(WiFi.localIP().toString().c_str());
  }
  return "";
}
