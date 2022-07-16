class c_folie {
  public:
  
    c_frame o_frame[10];
    
    void seite_aktualisieren(uint8_t seite, bool hard = false) {
      for (int i = 0; i < anzahl_frame; i++) {
        if ( o_frame[i].get_seite() == seite) {
          o_frame[i].bildschirm_frame_aktualisieren(hard);
        }
      }
    }

    bool seite_objekte_abfrage(uint8_t seite) {
      bool ruckgabe = false;
      for (int i = 0; i < anzahl_frame; i++) {
        if ( o_frame[i].get_seite() == seite) {
          if (o_frame[i].frame_objekte_abfrage() == true){
            
            objekt_befehl_anfrage = objekt_befehl_anfrage + "o_label[" + String(i) + "].";
            return true;
        }
      }
    }
    
    return false;
    }

    String frames_internet_erstellen(){
      String ruckgabe = "";
      
      for (int i = 0; i < 10; i++) {
       

          ruckgabe = ruckgabe+ o_frame[i].frame_internet_erstellen(); //"<script>console.log(read('/www/dynamisch/frame_" + String(i) + ".html'));</script>\n";

      
          
      }
      return ruckgabe;
      
    }



    void init(int _angezeigte_folie) {//Frmes und Knopfe werden initialisiert
      angezeigte_folie = _angezeigte_folie;
      DynamicJsonDocument doc(50000);
      File file = get_datei("/folie" + String(_angezeigte_folie) + ".json");
      DeserializationError error = deserializeJson(doc, file);

      // Test if parsing succeeds.
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }
      const char* ausgelesen;

      for (int a = 0; a < anzahl_frame; a++) {
        int id_frame = doc["frame"][a]["id"];
        if (id_frame == 0) {

          o_frame[id_frame].set_genutzt(false);
          for (int b = 0; b < anzahl_knopf; b++) {
            o_frame[id_frame].o_knopf[b].set_genutzt(false);
          }
        }
        else {
          
          
          //wenn Frame vorhanden



           o_frame[id_frame].set_genutzt(true);
              int16_t wip[anzahl_int_parameter]; //werte_int_parameter
              for (int c = 0; c < anzahl_int_parameter; c++) {
                wip[c] = doc["frame"][a][int_parameter_maske[c]];
              }
               
              wip[1] = o_frame[id_frame].get_y_pos()+ wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              int8_t seite = doc["frame"][a]["seite"];
              o_frame[id_frame].frame_init(wip,wsp,seite);





          for (int b = 0; b < anzahl_label; b++) {
            int id_label = doc["frame"][a]["label"][b]["id"];
            if (id_label == 0) {
              o_frame[id_frame].o_label[id_label].set_genutzt(false);
            }
            else {                                                                                      //wenn label vorhandeen
              o_frame[id_frame].o_label[id_label].set_genutzt(true);
              int16_t wip[anzahl_int_parameter]; //werte_int_parameter
              for (int c = 0; c < anzahl_int_parameter; c++) {
                wip[c] = doc["frame"][a]["label"][b][int_parameter_maske[c]];
              }
               
              wip[1] = o_frame[id_frame].get_y_pos()+ wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["label"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              o_frame[id_frame].o_label[id_label].label_init(wip,wsp);
              
              

            }
          }





          for (int b = 0; b < anzahl_knopf; b++) {
            int id_knopf = doc["frame"][a]["knopf"][b]["id"];
            if (id_knopf == 0) {
              o_frame[id_frame].o_knopf[id_knopf].set_genutzt(false);
            }
            else {                                                                                      //wenn Knopf vorhandeen
              o_frame[id_frame].o_knopf[id_knopf].set_genutzt(true);
              int16_t wip[anzahl_int_parameter]; //werte_int_parameter
              for (int c = 0; c < anzahl_int_parameter; c++) {
                wip[c] = doc["frame"][a]["knopf"][b][int_parameter_maske[c]];
              }
               
              wip[1] = o_frame[id_frame].get_y_pos()+ wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["knopf"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              
              String bf[anzahl_befehle];
              for (int c = 0; c < anzahl_befehle; c++) {
              ausgelesen = doc["frame"][a]["knopf"][b]["befehle"][c];
              bf[c] = ausgelesen;
           
              } 
              o_frame[id_frame].o_knopf[id_knopf].knopf_init(wip,wsp,bf);
              


            }
          }
          



          for (int b = 0; b < anzahl_menu; b++) {
            int id_menu = doc["frame"][a]["menu"][b]["id"];
            if (id_menu == 0) {
              o_frame[id_frame].o_menu[id_menu].set_genutzt(false);
            }
            else {                                                                                      //wenn menu vorhandeen
              o_frame[id_frame].o_menu[id_menu].set_genutzt(true);


              
              int16_t wip[anzahl_int_parameter]; //werte_int_parameter
              for (int c = 0; c < anzahl_int_parameter; c++) {
                wip[c] = doc["frame"][a]["menu"][b][int_parameter_maske[c]];
              }
               
              wip[1] = o_frame[id_frame].get_y_pos()+ wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["menu"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              o_frame[id_frame].o_menu[id_menu].label_init(wip,wsp);
              for (int c = 0; c < anzahl_str_parameter; c++) {
                if (str_parameter_maske[c] == "text"){
                   ausgelesen = doc["frame"][a]["menu"][b]["punkte"][0];
                }
                else{
                ausgelesen = doc["frame"][a]["menu"][b][str_parameter_maske[c]];
                }
                
                wsp[c] = ausgelesen;
              }
              
              String wmp[anzahl_menu_punkte];
              for (int c = 0; c < anzahl_menu_punkte; c++) {
              ausgelesen = doc["frame"][a]["menu"][b]["punkte"][c];
              wmp[c] = ausgelesen;
              Serial.println(ausgelesen);
           

              } 
              o_frame[id_frame].o_menu[id_menu].menu_init(wip,wsp,wmp);
            }
          }






           for (int b = 0; b < anzahl_schalter; b++) {
            int id_schalter = doc["frame"][a]["schalter"][b]["id"];
            if (id_schalter == 0) {
              o_frame[id_frame].o_schalter[id_schalter].set_genutzt(false);
            }
            else {                                                                                      //wenn schalter vorhandeen
              o_frame[id_frame].o_schalter[id_schalter].set_genutzt(true);
              int16_t wip[anzahl_int_parameter]; //werte_int_parameter
              for (int c = 0; c < anzahl_int_parameter; c++) {
                wip[c] = doc["frame"][a]["schalter"][b][int_parameter_maske[c]];
              }
               
              wip[1] = o_frame[id_frame].get_y_pos()+ wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["schalter"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }

              bool anfangszustand = doc["frame"][a]["schalter"][b]["start"];
              
              o_frame[id_frame].o_schalter[id_schalter].schalter_init(wip,wsp,anfangszustand);
              


            }
          }




          
        }
      }
    }



