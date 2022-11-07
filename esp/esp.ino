#include <ESP8266WiFiMulti.h>
#include "data.h"
#include "firebase.h"
#include "uart.h"
#include "control.h"

ESP8266WiFiMulti wifiMulti;

void setup() {
  for (uint8_t i = 0; i < sizeof(ssid); i++) wifiMulti.addAP(ssid[i].c_str(), password[i].c_str());
  while (wifiMulti.run() != WL_CONNECTED) delay(500);

  uart::setup();
  control::setup();
}

void loop() {
  uart::readUART();
  control::controlLcd();
  control::controlLed();
}
