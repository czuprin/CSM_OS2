void qrcode_anzeigen(String eingabe) {
  tft.fillRect(40, 80, 240, 240, TFT_WHITE);
  o_qrcode.create(eingabe);
}


void ap_mit_csm_verbinden_qr() {

}

void mit_csm_verbinden_qr() {
  tft.fillRect(allgemein_nutzbar_x1, allgemein_nutzbar_y1, allgemein_nutzbar_x2 - allgemein_nutzbar_x1, allgemein_nutzbar_y2 - allgemein_nutzbar_y1, TFT_BLACK);

  String ip_adresse = IpAddress2String(WiFi.localIP());
  Serial.println(ip_adresse);
  if (ip_adresse == "0.0.0.0") {
    ap_starten();
    qrcode_anzeigen("WIFI:S:" + int_ssid + ";T:WPA;P:" + int_password + ";");

    while (WiFi.softAPgetStationNum() < 1) {
      delay(10);
    }
    tft.fillRect(allgemein_nutzbar_x1, allgemein_nutzbar_y1, allgemein_nutzbar_x2 - allgemein_nutzbar_x1, allgemein_nutzbar_y2 - allgemein_nutzbar_y1, TFT_BLACK);
    ip_adresse = IpAddress2String(WiFi.softAPIP());
    delay(1000);
  }

  qrcode_anzeigen("http://" + ip_adresse + "/");
  tft.setCursor(0, 330);
  tft.setTextSize(2);
  tft.println("Offne Internetseite:");
  tft.println("http://" + ip_adresse + "/");

  while (indexseite_aufgerufen == false) {
    delay(100);
  }
  indexseite_aufgerufen = false;
  tft.fillRect(allgemein_nutzbar_x1, allgemein_nutzbar_y1, allgemein_nutzbar_x2 - allgemein_nutzbar_x1, allgemein_nutzbar_y2 - allgemein_nutzbar_y1, TFT_BLACK);
  csm_befehl_hinzufugen("offne_angezeigte_seite();");

}
