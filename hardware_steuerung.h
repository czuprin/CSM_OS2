#define anz_sensor_werte 7
#include "spiffs_steuerung.h"
#include <WiFi.h>
#include <Wire.h>
#include <I2C_EEPROM.h>

#include "./zusatz/treiber_beschleunigung.h"
#include "./zusatz/treiber_lidar.h"
#include "./zusatz/treiber_tsl2591.h"
#include "./zusatz/adc_hardwaresteuerung.h"
M24C64<0x50> eep;
#include <MQTTPubSubClient.h>

sensor_lidar o_sensor_lidar;
sensor_beschleunigung o_sensor_beschleunigung;
sensor_tsl2591 o_sensor_tsl2591;




String auslesen_sensorname() {
  char text[30];
  String ruckgabe = "";
  if (eep.ready()) {

    eep.get(0, text); // String lesen
    ruckgabe = String(text);
    ruckgabe.trim();
  }
  else {
    ruckgabe = "kein Sensor";
  }
  return ruckgabe;
}

bool get_sensor_angeschlossen() {
  bool ruckgabe = false;
  Wire.beginTransmission(0x50);

  if (Wire.endTransmission() == 0) {
    ruckgabe = true;
  }
  return ruckgabe;
}

void schreiben_sensorname(String eingabe) {
  char text[30];
  eingabe.toCharArray(text, 30);
  if (eep.ready())
    Serial.println ("EE Prom ist bereit!");
  else Serial.println("EE Prom ist nicht bereit, Verkabelung prüfen ");
  eep.put(0, text); // String ins EEProm schreiben
}

//Wlan

bool mit_ext_wlan_verbinden(bool eingabe) {
  bool ruckgabe = false;
  if (eingabe == true) {
    WiFi.begin(ext_ssid.c_str(), ext_password.c_str());
  }

  //Serial.print("Connecting to WiFi ..");
  if (WiFi.status() == WL_CONNECTED) {

    ruckgabe = true;
  }
  //Serial.println(WiFi.localIP());
  return ruckgabe;
}

void ap_starten() {
  int_password = String(random(32767)) + String(random(32767)) + String(random(32767)) + String(random(32767)) + String(random(32767));
  int_ssid = "CSM_V3.2_Wlan" + String(random(32767));
  WiFi.softAP(int_ssid.c_str(), int_password.c_str(), 1, false, 1);

}



//MQTT

WiFiClient client;
MQTTPubSubClient mqtt;

TaskHandle_t task_mqtt_aktualisieren;

void void_task_mqtt_aktualisieren( void * parameter ) {
  while (1) {
    int mqtt_umlauf_start_zeit = millis();
    mqtt.update();  // should be called



    int pausenzeit = (1000 / mqtt_abfragefrequenz) - (millis() - mqtt_umlauf_start_zeit);
    vTaskDelay(pausenzeit / portTICK_RATE_MS);
    //if (pausenzeit < (1000 / mqtt_abfragefrequenz)){
    // Serial.println(pausenzeit);}
    //
  }
}

void sende_mqtt(String eingabe_topic, String eingabe_daten) {
  mqtt.publish(eingabe_topic, eingabe_daten);
  Serial.println(eingabe_topic + "    :    " + eingabe_daten);
}

void start_mqtt_client() {
  Serial.print("connecting to host...");
  while (!client.connect("151.80.4.135", 1883)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" connected!");

  // initialize mqtt client
  mqtt.begin(client);

  Serial.print("connecting to mqtt broker...");
  while (!mqtt.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" connected!");
  xTaskCreatePinnedToCore(void_task_mqtt_aktualisieren, "task_mqtt_aktualisieren", 10000, NULL, 2, &task_mqtt_aktualisieren, 1);
  mqtt.subscribe("csm_emfangen", [](const String & payload, const size_t size) {
    csm_befehl_hinzufugen(payload);
  });
}

void init_hardware_steuerung() {
  Wire.begin();
  init_adc();
}

void hardware_betriebssteuerung() {
  if (ist_sensor_angeschlossen == get_sensor_angeschlossen()) {}
  else {
    ist_sensor_angeschlossen = ! ist_sensor_angeschlossen;
    Serial.println(1);
    angeschlossenser_sensor = auslesen_sensorname();
    sensor_status_aktualisiert = true;
    csm_befehl_hinzufugen("init_direktausgabe_hardwaresteuerung();");
  }

}
