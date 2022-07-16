

#include <Arduino_JSON.h>

// Replace with your network credentials


// Create AsyncWebServer object on port 80

// Create a WebSocket object




String internet_graph(String eingabe_pfad, float skalierung_x = 0, float skalierung_y = 0, int g_x = 0, int g_y = 0) {

  String ruckgabe = "";

  File anfang = get_datei("/internet/graph/anfang.html");
  ruckgabe = ruckgabe + anfang.readString();
  anfang.close();
  File x_achse = get_datei(eingabe_pfad + "/x.csv");
  ruckgabe = ruckgabe + "var xArray = [" + x_achse.readString() + "];" ;
  File y_achse = get_datei(eingabe_pfad + "/y.csv");
  ruckgabe = ruckgabe + "var yArray = [" + y_achse.readString() + "];" ;
  File ende = get_datei("/internet/graph/ende.html");
  ruckgabe = ruckgabe + ende.readString();
  ende.close();


  return ruckgabe;
}











String seite_erstellen() {
  //indexseite_aufgerufen = true;
  String internetseite = "";
  File anfang = get_datei("/www/statisch/anfang.html");
  //internetseite = internetseite + anfang.readString();
  //anfang.close();
  //internetseite = internetseite + folie1.frames_internet_erstellen();
  internetseite = internetseite + internet_graph("");
  File ende = get_datei("/www/statisch/ende.html");
  internetseite = internetseite + ende.readString();
  ende.close();
  return internetseite;
}


bool init_internet_steuerung() {

  WiFi.mode(WIFI_STA);
  mit_ext_wlan_verbinden(true);
  for (int i = 0; (i < 10 && (mit_ext_wlan_verbinden(false) == false)); i++) {
    delay(500);
  }


  //ap_starten();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    indexseite_aufgerufen = true;
    request->redirect("/index.html");
    
  });

  //const char index_html[] PROGMEM = R"rawliteral(
  server.serveStatic("/", SPIFFS, "/");

  // Start server
  server.begin();

  server.on("/www/dynamisch/index.html", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("aaa" + String(uxTaskPriorityGet(NULL)));
    // vTaskPrioritySet(NULL,6);
    request->send(200, "text/html", seite_erstellen());
    // vTaskPrioritySet(NULL,1);
  }
           );

  return mit_ext_wlan_verbinden(false);

}


void endgerat_uber_qr_verbinden(bool eingabe) {

}
