String csm_befehl_ausfuhren(String eingabe) {
  int* p_int = new int[anz_parameter_csm_befehle];
  String* p_str = new String[anz_parameter_csm_befehle];
  float* p_float = new float[anz_parameter_csm_befehle];
  String ruckgabe = "false_csm_befehl_ausfuren";
  String* nachstes_objekt;
  nachstes_objekt = get_nachstes_objekt(eingabe);
  String methodenname = "";
  if (nachstes_objekt[1] == "") {
    methodenname = get_methode(eingabe,   //test123(1.535435,34534,\"avc\");//test123(1.535435,34534,"avc");
                               p_int, p_str, p_float);

    //methode ausführen


    if (methodenname == "start_mqtt_client") {
      start_mqtt_client();
      ruckgabe = "true";
    }
    else if (methodenname == "init_direktausgabe_hardwaresteuerung") {
      init_direktausgabe_hardwaresteuerung();
      ruckgabe = "true";
    }
    else if (methodenname == "schreib_helligkeitsdaten") {
      schreib_helligkeitsdaten(p_int[0]);
      ruckgabe = "true";
    }
    else if (methodenname == "offne_seite") {
      offne_seite(p_int[0]);
      ruckgabe = "true";
    }
    else if (methodenname == "seite_aktualisieren") {
      folie1.seite_aktualisieren(1, true);
      ruckgabe = "true";
    }
    else if (methodenname == "mit_csm_verbinden_qr") {
      mit_csm_verbinden_qr();
      ruckgabe = "true";
    }
    else if (methodenname == "offne_angezeigte_seite") {
      offne_seite(angezeigte_seite);
      ruckgabe = "true";
    }
    else if (methodenname == "sende_mqtt") {
      sende_mqtt(p_str[0], p_str[1]);
      ruckgabe = "true";
    }
    else if (methodenname == "offne_folie") {
      //folie1.init(p_int[0]);
      offne_seite(p_int[0]);
      ruckgabe = "true";
    }







  }

  else {
    if (nachstes_objekt[1] == "folie") {
      ruckgabe =  folie1.folie_befehl_ausfuhren(nachstes_objekt[0]);
    }
    //in nachstes Objekt gehen
  }
  return ruckgabe;


}



TaskHandle_t task_uart_eingabe;

void void_task_uart_eingabe( void * parameter ) {
  Serial.println("Eingabe: ") ;
  while (1) {
    String zu_schreiben = "";
    if (Serial.available()) {

      while (Serial.available()) {
        zu_schreiben = zu_schreiben + char(Serial.read());
      }
      csm_befehl_hinzufugen(zu_schreiben);

      Serial.println("Eingabe: ");
    }
    vTaskDelay(100 / portTICK_RATE_MS);
  }
}



void uart_init() {
  xTaskCreatePinnedToCore(void_task_uart_eingabe, "task_uart_eingabe", 1024, NULL, 1, &task_uart_eingabe, 0);
}
