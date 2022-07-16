#pragma once
#include <SPIFFS.h>


void init_SPIFFS_steuerung() {
  while (!SPIFFS.begin()) {
    Serial.println(F("Failed to initialize SD library"));
    delay(1000);
  }
}
File get_datei(String eingabe) {
  return SPIFFS.open(eingabe);
}
