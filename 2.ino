String csm_befehl_speicher[20];
int csm_befehl_hinzufugen_stelle = 0;
int csm_befehl_abarbeiten_stelle = 0;
int erhohe_stelle(int eingabe, int maximalzahl) {
  eingabe = eingabe + 1;
  if (eingabe >= maximalzahl) {
    eingabe = 0;
  }
  return eingabe;
}

void einzelnen_csm_befehl_hinzufugen(String eingabe) {

    csm_befehl_speicher[csm_befehl_hinzufugen_stelle] = eingabe;
  csm_befehl_hinzufugen_stelle = erhohe_stelle(csm_befehl_hinzufugen_stelle, 20);
}

void csm_befehl_hinzufugen(String eingabe) {
  Serial.println(eingabe);
  while (!(eingabe.indexOf(";", 1)==-1)){
    int trenner = eingabe.indexOf(";", 0);
    einzelnen_csm_befehl_hinzufugen(eingabe.substring(0 , trenner+1));
    eingabe = eingabe.substring(trenner+1,sizeof(eingabe));
  }
  
einzelnen_csm_befehl_hinzufugen(eingabe);
}


String text_knopf = "";
String csm_befehl_zum_ausfuhren = "";
#include "allgemeine_variablen.h"
#include "hardware_steuerung.h"
#include "ui_steuerung.h"
#include "spektrometer.h"

void init_direktausgabe_hardwaresteuerung() {
  String* eingabe;
  bool hilf_var = true;
  if (angeschlossenser_sensor == "LIDAR") {
    o_sensor_lidar.init();
    eingabe = o_sensor_lidar.get_datenbezeichner();
  }
  else if (angeschlossenser_sensor == "Beschleunigung") {
    o_sensor_beschleunigung.init();
    eingabe = o_sensor_beschleunigung.get_datenbezeichner();
  }
  else if (angeschlossenser_sensor == "TSL2591") {
    o_sensor_tsl2591.init();
    eingabe = o_sensor_tsl2591.get_datenbezeichner();
  }
  
  
   else {
    if (angeschlossenser_sensor == "Spektrometer") {
    init_spektometer();}
    else{
      tft.setRotation(0);
    for (int i = 0; i < anz_sensor_werte; i++) {
      folie1.o_frame[1].o_label[i + 1].aktualisiere_label("");
      hilf_var = false;
    }
    }
    hilf_var = false;
  }
    
  if (hilf_var == true) {
    for (int i = 0; i < anz_sensor_werte; i++) {
      Serial.println(eingabe[i]);
      folie1.o_frame[1].o_label[i + 1].aktualisiere_label(eingabe[i]);
    }
  }
}

void aktualisiere_direktausgabe() {
  String* eingabe;
  bool hilf_var = true;
  if (angeschlossenser_sensor == "LIDAR") {
    o_sensor_lidar.aktualisiere_messdaten();
    eingabe = o_sensor_lidar.get_messdaten();
  }
  else if (angeschlossenser_sensor == "Beschleunigung") {
    o_sensor_beschleunigung.aktualisiere_messdaten();
    eingabe = o_sensor_beschleunigung.get_messdaten();
  }


  else if (angeschlossenser_sensor == "TSL2591") {
    o_sensor_tsl2591.aktualisiere_messdaten();
    eingabe = o_sensor_tsl2591.get_messdaten();}


  else {
    if (angeschlossenser_sensor == "Spektrometer") {
    aktualisiere_spektrometer1();
  }
  else{
    for (int i = 0; i < anz_sensor_werte; i++) {
      folie1.o_frame[2].o_label[i + 1].aktualisiere_label("");
      
    }
  }
  hilf_var = false;
  }

  if (hilf_var == true) {
      
    
    
    for (int i = 0; i < anz_sensor_werte; i++) {
      folie1.o_frame[2].o_label[i + 1].aktualisiere_label(eingabe[i]);
    
  }

    
  }
}

#include "csm_befehl_steuerung.h"
#include "tcp_server.h"


void csm_befehl_handler() {
  if (csm_befehl_hinzufugen_stelle == csm_befehl_abarbeiten_stelle) {}
  else {
    Serial.println(csm_befehl_ausfuhren(csm_befehl_speicher[csm_befehl_abarbeiten_stelle]));
    csm_befehl_abarbeiten_stelle = erhohe_stelle(csm_befehl_abarbeiten_stelle, 20);

  }
}



TaskHandle_t task = NULL;
String externes_schreiben = "";


void void_task( void * parameter ) {
  // while (true){

  // delay(1000);}
  vTaskDelete(NULL);
}


//xTaskCreatePinnedToCore(void_task,"task",2000,NULL,1,&task,1);

#include <Adafruit_AW9523.h>

Adafruit_AW9523 aw;

uint8_t LedPin = 2;  // 0 thru 15


void setup()
{
  
  init_hardware_steuerung();
  init_SPIFFS_steuerung();
pinMode(13, OUTPUT);
      digitalWrite(13, HIGH);
      delay(1000);
      aw.begin(0x58);
aw.pinMode(LedPin, OUTPUT);
aw.pinMode(0, OUTPUT);
aw.pinMode(3, OUTPUT);
aw.pinMode(1, OUTPUT);

aw.digitalWrite(LedPin, HIGH);
aw.digitalWrite(0, HIGH);
aw.digitalWrite(1, HIGH);
aw.digitalWrite(3, HIGH);
delay(1000);

  // put your setup code here, to run once:
  Serial.begin(115200);
  //while (!Serial) continue;

  initWebSocket();
  tft.loadFont("NotoSansBold15");
  init_ui_steuerung();


  //qrcode.create("http://192.168.0.11/www/dynamisch/index.html");
  //  set_Paramter_Knopf();
  //seitenaufbau();
  // mit_csm_verbinden_qr();
  //befehl_ausfuhren("o_frame[1].o_knopf[2].test123(1.535435,34534,334);");
  init_tcp();
  Serial.println(seite_erstellen());
  /*start_mqtt_client();


    mqtt.subscribe("csm_emfangen", [](const String& payload, const size_t size){
      vTaskPrioritySet(NULL,0);
      Serial.println("b" + String(uxTaskPriorityGet(NULL)));
      Serial.println(payload);

         vTaskPrioritySet(NULL,6);
     o_steuerungs_elemente.o_knopf[2].aktualisiere_label(payload);

     vTaskPrioritySet(NULL,2);
       });


       //xTaskCreatePinnedToCore(void_task,"task",2000,NULL,10,&task,1);
  */

  uart_init();
}

void loop() {
  hardware_betriebssteuerung();
  if (angezeigte_seite == 2) {
    aktualisiere_direktausgabe();
  }
  csm_befehl_handler();
  void_task_displayeingabe();
  delay(100);
  // o_steuerungs_elemente.o_knopf[2].aktualisiere_label("asd");
  //Serial.print(csm_befehl_hinzufugen_stelle);
  //Serial.print("   ");
  //Serial.println(csm_befehl_abarbeiten_stelle);
  ws.cleanupClients();
}
