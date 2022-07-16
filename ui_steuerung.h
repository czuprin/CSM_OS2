#include "websocket.h"
#include "folien_steuerung.h"
#include "internet_steuerung.h"


TaskHandle_t task_displayeingabe;


/*
  String befehl_ausfuhren(String eingabe){
  String  ruckgabe = "";

  String* nachstes_objekt ;
  nachstes_objekt = get_nachstes_objekt(eingabe);

  if (nachstes_objekt[1] == ""){
  #include "allgemeine_befehle.h"
  }
  else{
  if (nachstes_objekt[1] == "folie1"){

    ruckgabe = folie1.folie_befehl_ausfuhren(nachstes_objekt[0]);
  }
  }
  return ruckgabe;
  }

*/


void void_task_displayeingabe(// void * parameter
) {
  //while(1){
  if (sensor_status_aktualisiert == true) {
    Serial.println(2);
    Serial.println(angeschlossenser_sensor);
    o_steuerungs_elemente.o_knopf[2].aktualisiere_label(angeschlossenser_sensor);
    sensor_status_aktualisiert = false;
  }

  t_aktual();
  if (pressed ) {
    Serial.println(1);
    vTaskPrioritySet(task_displayeingabe, 2);
    o_steuerungs_elemente.frame_objekte_abfrage();


    // put your main code here, to run repeatedly:
    //if (folie1.o_frame[1].o_knopf[1].abfrage() == true){
    //  if (folie1.o_frame[1].o_knopf[1].funktion() == "Hallo Welt"){
    //    folie1.o_frame[2].o_knopf[1].drawButton();
    //  }

    //if (
    folie1.seite_objekte_abfrage(1);
    /*    == true) {
        Serial.println(objekt_befehl_anfrage);
        for (int i = 0; i < anzahl_befehle; i++) {
          if (befehle_ausfuhren[i] == "") {
            exit;
          }
          else {
            Serial.println(befehle_ausfuhren[i]);
            if (befehle_ausfuhren[i] == "Hallo"){
            // Serial.println(i);
            vTaskPrioritySet(task_displayeingabe,4);
            mit_csm_verbinden_qr();
              folie1.seite_aktualisieren(angezeigte_seite, true);

            //folie1.seite_aktualisieren(angezeigte_folie,true);
            //}
            }
            else if (befehle_ausfuhren[i] == "sende_mqtt") {
                sende_mqtt(befehle_ausfuhren[i+1],folie1.o_frame[1].o_menu[1].get_label());
               }

          }
        }
      }
      vTaskPrioritySet(task_displayeingabe,0); */
  }
  //Serial.print(1);
  //o_steuerungs_elemente.o_knopf[2].aktualisiere_label(text_knopf);
  //vTaskDelay(50 / portTICK_RATE_MS);
}//}

void init_ui_steuerung() {
  Serial.println(1111111);
  init_folien_steuerung();
  if (init_internet_steuerung() == true) {
    o_steuerungs_elemente.o_knopf[3].aktualisiere_label("WLAN");
  }
  folie1.seite_aktualisieren(angezeigte_seite, true);

  //xTaskCreatePinnedToCore(void_task_displayeingabe,"task_displayeingabe",2048,NULL,1,&task_displayeingabe,1);

  Serial.println(1111111);

}
