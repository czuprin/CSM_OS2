#pragma once
#include <ArduinoJson.h>
#define anzahl_int_parameter 10
#define anzahl_str_parameter 10
#define anzahl_menu_punkte 10
#define anzahl_farben 20





String int_parameter_maske[anzahl_int_parameter] = {"x_pos", "y_pos", "x_lang", "y_lang", "gt"};
String str_parameter_maske[anzahl_str_parameter] = {"fu", "fh", "ft", "text"};

const String farben_name[anzahl_farben] = {"BLACK", "NAVY", "DARKGREEN", "MAROON", "PURPLE", "OLIVE", "LIGHTGREY", "DARKGREY", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA",
                                           "YELLOW", "WHITE", "ORANGE", "GREENYELLOW", "PINK"
                                          };
const int farben_wert[anzahl_farben] = {0,
                                        0x000F
                                        , 0x03E0
                                        , 0x7800
                                        , 0x780F
                                        , 0x7BE0
                                        , 0xC618
                                        , 0x7BEF
                                        , 0x001
                                        , 0x07E0
                                        , 0x07FF
                                        , 0xF800
                                        , 0xF81F
                                        , 0xFFE0
                                        , 0xFFFF
                                        , 0xFD20
                                        , 0xAFE5
                                        , 0xF81F
                                       };

int get_int_Farbe(String eingabe) {
  int ausgabe = 0xF81F;
  for (int i = 0; i < anzahl_farben; i++) {
    if (farben_name[i] == eingabe) {
      ausgabe = farben_wert[i];
    }
  }

  return ausgabe;


}


String knof_verandern = R"=====(
{
  "frame": [
    {"id": |FRAME_ID|,
      
      "knopf": [
        {"id": |KNOPF_ID|,
          "text": |TEXT|
        }]
    }
  ]
}
)=====";
String label_verandern = R"=====(
{
  "frame": [
    {"id": |FRAME_ID|,
      
      "knopf": [
        {"id": |LABEL_ID|,
          "text": "|TEXT|"
        }]
    }
  ]
}
)=====";




#define anzahl_label 10
#define anzahl_knopf 10
#define anzahl_schalter 10
#define anzahl_menu 10
#define anzahl_frame 10


void befehl_interpretieren(String eingabe) {

}


void befehle_interpretieren(String eingabe[anzahl_befehle]) {
  for (int i = 0; i < anzahl_befehle; i++) {
    befehl_interpretieren(eingabe[i]);
  }

}







class c_label: public TFT_eSPI_Button {
  public:
    bool _genutzt = false;
    bool _str_init = false;
    int frame_nummer = 0;
    int objekt_nummer = 0;

    void aktualisiere_browser_label(){
      String eingabe = label_verandern;
eingabe.replace("|FRAME_ID|",String(frame_nummer));
eingabe.replace("|LABEL_ID|",String(objekt_nummer));
eingabe.replace("|TEXT|",_label);
notifyClients(eingabe);
delay(200);
    }

    void set_frame_nummer(int eingabe){
      frame_nummer = eingabe;
    }
    void set_objekt_nummer(int eingabe){
      objekt_nummer = eingabe;
    }
     int get_frame_nummer(){
      return frame_nummer;
    }
    int get_objekt_nummer(){
      return objekt_nummer;
    }
    
    
    String get_label() {
      return _label;
    }
    void aktualisiere_label(String label, bool hard = false) {

      if (_genutzt == true) {
        if (label != String(_label) || hard == true) {
          drawButton(isPressed(), label);
          aktualisiere_browser_label();
        }
      }
    }

    void aktualisiere_label_hard() {

      if (_genutzt == true) {

        drawButton(isPressed(), _label);
      }
    }

    String andere_label_int_parameter(String parameter, int eingabe) {
      String ruckgabe = "true";
      if (parameter == "x_pos") {
        _x1 = eingabe;
      }
      else if (parameter == "y_pos") {
        _y1 = eingabe;
      }
      else if (parameter == "x_lang") {
        _w = eingabe;
      }
      else if (parameter == "y_lang") {
        _h = eingabe;
      }
      else if (parameter == "gt") {
        _textsize = eingabe;
      }
      else {
        ruckgabe = "kein passender Parameter";
      }
      //aktualisiere_label_hard();
      return ruckgabe;
    }

    String andere_label_str_parameter(String parameter, String eingabe) {
      String ruckgabe = "true";
      if (parameter == "fu") {
        _outlinecolor = get_int_Farbe(eingabe);
      }
      else if (parameter == "fh") {
        _fillcolor = get_int_Farbe(eingabe);
      }
      else if (parameter == "ft") {
        _textcolor = get_int_Farbe(eingabe);
      }
      else if (parameter == "text") {
        _textsize = get_int_Farbe(eingabe);
      }
      else {
        ruckgabe = "kein passender Parameter";
      }
      aktualisiere_label_hard();
      return ruckgabe;
    }
    //{"fu", "fh", "ft", "text"};}


    void label_init(int16_t int_eingabe[anzahl_int_parameter], String str_eingabe[anzahl_str_parameter]) { //, uint8_t textsize

      if (str_eingabe[0] == "") {
        str_eingabe[0] = "WHITE";//WHITE
      }
      if (str_eingabe[1] == "") {
        str_eingabe[1] = "WHITE";
      }
      if (str_eingabe[2] == "") {
        str_eingabe[2] = "BLACK";
      }
      str_eingabe[3].toCharArray(_label, label_textlange - 1);

      if (int_eingabe[4] == 0) {
        int_eingabe[4] = 2;
      }


      initButtonUL(&tft, int_eingabe[0] ,  int_eingabe[1] , int_eingabe[2], int_eingabe[3], // x, y, b, h
                   get_int_Farbe(str_eingabe[0]), get_int_Farbe(str_eingabe[1]), get_int_Farbe(str_eingabe[2]), // Farben: Umrandung, Hintergrund ,Text
                   _label, int_eingabe[4]); //Textinhalt, Textgröße{


    }

    void set_genutzt(bool genutzt) {
      _genutzt = genutzt;
    }
    bool get_genutzt() {
      return _genutzt;
    }




    int16_t get_x_pos() {
      return _x1 ;
    }
    int16_t get_y_pos() {
      return _y1 ;
    }
    int16_t get_x_lang() {
      return _w ;
    }
    int16_t get_y_lang() {
      return _h ;
    }




    String label_internet_erstellen() {

      String ruckgabe = "";
      if (_genutzt == true) {
        ruckgabe = ruckgabe + "<p class='state'>";
        ruckgabe = ruckgabe + _label;
        ruckgabe = ruckgabe +  "</p>\n";
      }
      return ruckgabe;

    }

    String label_befehl_ausfuhren(String eingabe,
                                  int p_int[anz_parameter_csm_befehle] = new int[anz_parameter_csm_befehle],
                                  String p_str[anz_parameter_csm_befehle] = new String[anz_parameter_csm_befehle],
                                  float p_float[anz_parameter_csm_befehle] = new float[anz_parameter_csm_befehle],
                                  bool interpretiert = false) {
      String* nachstes_objekt;
      String ruckgabe = "false_label";
      nachstes_objekt = get_nachstes_objekt(eingabe);
      String methodenname = "";
      if (nachstes_objekt[1] == "" || interpretiert == true) {
        if (interpretiert == false) {
          methodenname = get_methode(eingabe,   //test123(1.535435,34534,\"avc\");//test123(1.535435,34534,"avc");
                                     p_int, p_str, p_float);
        }
        else
        {
          methodenname = eingabe;
        }
        //methode ausführen
        if (methodenname == "aktualisiere_label") {
          aktualisiere_label(p_str[0]);
          ruckgabe = "aktualisiere_label: " + p_str[0];
        }
        else if (methodenname == "andere_label_int_parameter") {
          ruckgabe = andere_label_int_parameter(p_str[0], p_int[1]);
        }
        else if (methodenname == "andere_label_str_parameter") {
          ruckgabe = andere_label_str_parameter(p_str[0], p_str[1]);
        }

        else {
          // in verschachtelte objekte gehen
        }
      }
      else {
      }

      return ruckgabe;
    }

};



class c_knopf :  public c_label {
  public:

    String _knopf_befehle[anzahl_befehle];


    String *get__knopf_befehle() {
      return _knopf_befehle;
    }


    bool knopf_abfrage() {
      bool ruckgabe = false;
      if (_genutzt == true) {
        int taste_gedruckt = 0;
        if (pressed && contains(t_x, t_y)) {
          vTaskPrioritySet(NULL, 4);
          press(!isPressed());
          taste_gedruckt = 1;
          while (pressed && contains(t_x, t_y)) {
            vTaskDelay(100 / portTICK_RATE_MS);//delay(1);
            pressed = tft.getTouch(&t_x, &t_y);
          }//bleibe so lange in der Schleife bis dies Taste losgelassen wurde
          press(!isPressed());
          for (int i = 0; i < anzahl_befehle; i++) {
            if (_knopf_befehle[i] == "") {}
            else {
              csm_befehl_hinzufugen(_knopf_befehle[i]);
            }
          }

          //Serial.println("erst");
          //vTaskPrioritySet(NULL, 1);
          return true;

        }
      }
      return ruckgabe;
    }




    void knopf_init(int16_t int_eingabe[anzahl_int_parameter], String str_eingabe[anzahl_str_parameter], String knopf_befehle[anzahl_befehle]) {
      for (int i = 0; i < anzahl_befehle; i++) {
        _knopf_befehle[i] = knopf_befehle[i];
      }
      label_init(int_eingabe, str_eingabe);

      //  memmove(_knopf_befehle,knopf_befehle,sizeof(knopf_befehle));

    }

    String knopf_internet_erstellen() {

      String ruckgabe = "";
      if (_genutzt == true) {
        ruckgabe = ruckgabe + "<button>";
        ruckgabe = ruckgabe + String(_label);
        ruckgabe = ruckgabe + "</button><br>\n";

        return ruckgabe;

      }
      return ruckgabe;

    }



    String knopf_befehl_ausfuhren(String eingabe,
                                  int p_int[anz_parameter_csm_befehle] = new int[anz_parameter_csm_befehle],
                                  String p_str[anz_parameter_csm_befehle] = new String[anz_parameter_csm_befehle],
                                  float p_float[anz_parameter_csm_befehle] = new float[anz_parameter_csm_befehle],
                                  bool interpretiert = false) {
      String* nachstes_objekt;
      String ruckgabe = "false_knopf";
      nachstes_objekt = get_nachstes_objekt(eingabe);
      String methodenname = "";
      if (nachstes_objekt[1] == "") {
        if (interpretiert == false) {
          methodenname = get_methode(eingabe,   //test123(1.535435,34534,\"avc\");//test123(1.535435,34534,"avc");
                                     p_int, p_str, p_float);
        }
        else
        {
          methodenname = eingabe;
        }
        //methode ausführen
        if (methodenname == "knopf_internet_erstellen") {
          ruckgabe = knopf_internet_erstellen();
        }
        else {


          ruckgabe = label_befehl_ausfuhren( methodenname,
                                             p_int,
                                             p_str,
                                             p_float,
                                             true);



        }
      }





      return ruckgabe;
    }


};


class c_schalter :  public c_label {
  public:
    bool get_zustand() {
      return isPressed();
    }
    void schalter_abfrage()
    {
      bool taste_gedruckt = 0;

      if (pressed && contains(t_x, t_y)) {

        press(!isPressed());  // tell the button it is pressed
        taste_gedruckt = 1;
        while (pressed && contains(t_x, t_y)) {
          delay(1);
          pressed = tft.getTouch(&t_x, &t_y);
        }//bleibe so lange in der Schleife bis dies Taste losgelassen wurde


      }

    }


    void schalter_init(int16_t int_eingabe[anzahl_int_parameter], String str_eingabe[anzahl_str_parameter], bool startzustand)
    {

      label_init(int_eingabe, str_eingabe);
      if (startzustand == true) {
        currstate = true;
      }
      Serial.println(get_zustand());


    }

    String schalter_internet_erstellen() {

      String ruckgabe = "";
      if (_genutzt == true) {
        ruckgabe = ruckgabe + _label + " <input type='checkbox'><br>\n";


      }
      return ruckgabe;
    }

};


class c_menu :  public c_label {
  public:
    String _menu_punkte[anzahl_menu_punkte];
    int aktueller_stand = 0;

    void menu_abfrage()
    {
      bool taste_gedruckt = 0;

      if (pressed && contains(t_x, t_y)) {

        press(!isPressed());  // tell the button it is pressed
        taste_gedruckt = 1;
        while (pressed && contains(t_x, t_y)) {
          delay(1);
          pressed = tft.getTouch(&t_x, &t_y);
        }//bleibe so lange in der Schleife bis dies Taste losgelassen wurde

        aktueller_stand = aktueller_stand + 1;
        if (_menu_punkte[aktueller_stand] == "") {
          aktueller_stand = 0;
        }
        else {
          Serial.println(_menu_punkte[aktueller_stand]);

        }
        _menu_punkte[aktueller_stand].toCharArray(_label, label_textlange - 1); ;
        press(!isPressed());
      }

    }


    void menu_init(int16_t int_eingabe[anzahl_int_parameter], String str_eingabe[anzahl_str_parameter], String menu_punkte[anzahl_menu_punkte]) {

      label_init(int_eingabe, str_eingabe);
      for (int i = 0; i < anzahl_menu_punkte; i++) {
        _menu_punkte[i] = menu_punkte[i];
      }
      // memmove(_menu_punkte,menu_punkte,sizeof(menu_punkte));
      Serial.println(_menu_punkte[1]);
    }


    String menu_internet_erstellen() {

      String ruckgabe = "";
      if (_genutzt == true) {
        ruckgabe = ruckgabe + "<select  >";

        for (int i = 0; i < anzahl_menu_punkte; i++) {
          if (_menu_punkte[i] != "") {
            ruckgabe = ruckgabe +  "<option value='";
            ruckgabe = ruckgabe + String(i) + "'>";
            ruckgabe = ruckgabe + _menu_punkte[i];
            ruckgabe = ruckgabe +  "</option>";
          }


        }
        ruckgabe = ruckgabe +  "</select><br>\n";
      }

      return ruckgabe;

    }


    void aktualisiere_menu(bool hard) {
      if (_menu_punkte[aktueller_stand] == _label) {
        aktualisiere_label_hard();
      }
      else {
        aktualisiere_label(_menu_punkte[aktueller_stand], hard);
      }

    }




};







class c_frame: public c_label {
  public:

    c_label o_label[anzahl_label];
    c_knopf o_knopf[anzahl_knopf];
    c_schalter o_schalter[anzahl_schalter];
    c_menu o_menu[anzahl_menu];


    void frame_objekte_nummerrieren(){
      

    for (int i = 0; i<anzahl_label; i++){
      o_label[i].set_frame_nummer(get_frame_nummer());
      o_label[i].set_objekt_nummer(i);
    }

     for (int i = 0; i<anzahl_knopf; i++){
      o_knopf[i].set_frame_nummer(get_frame_nummer());
      o_knopf[i].set_objekt_nummer(i);
    }

     for (int i = 0; i<anzahl_schalter; i++){
      o_schalter[i].set_frame_nummer(get_frame_nummer());
      o_schalter[i].set_objekt_nummer(i);
    }

     for (int i = 0; i<anzahl_menu; i++){
      o_menu[i].set_frame_nummer(get_frame_nummer());
      o_menu[i].set_objekt_nummer(i);
    }


    }


    uint8_t _seite = 0;
    uint8_t get_seite() {
      return _seite;
    }


    void frame_init(int16_t int_eingabe[anzahl_int_parameter], String str_eingabe[anzahl_str_parameter], uint8_t seite) {

      label_init(int_eingabe, str_eingabe);

      _seite = seite;
    }




    void bildschirm_frame_aktualisieren(bool hard = false) {
      if (_genutzt == true) {
        for (int i = 0; i < anzahl_label; i++) {
          o_label[i].aktualisiere_label_hard();
        }

        for (int i = 0; i < anzahl_knopf; i++) {
          o_knopf[i].aktualisiere_label_hard();
        }

        for (int i = 0; i < anzahl_schalter; i++) {
          o_schalter[i].aktualisiere_label_hard();
        }

        for (int i = 0; i < anzahl_menu; i++) {
          o_menu[i].aktualisiere_label_hard();
        }
      }
    }


    bool frame_objekte_abfrage() {

      if (_genutzt == true) {

        for (int i = 0; i < anzahl_knopf; i++) {

          if (true == o_knopf[i].knopf_abfrage()) {
            objekt_befehl_anfrage = "o_knopf[" + String(i) + "].";
            return true;
          }
        }

        for (int i = 0; i < anzahl_schalter; i++) {
          o_schalter[i].schalter_abfrage();
        }

        for (int i = 0; i < anzahl_menu; i++) {
          o_menu[i].menu_abfrage();
        }
      }

      return false;

    }


    String frame_internet_erstellen() {

      String ruckgabe = "";
      if (_genutzt == true) {
        ruckgabe = ruckgabe + "<div class='card'>";

        for (int i = 0; i < anzahl_label; i++) {
          ruckgabe = ruckgabe + o_label[i].label_internet_erstellen();
        }

        for (int i = 0; i < anzahl_knopf; i++) {
          ruckgabe = ruckgabe + o_knopf[i].knopf_internet_erstellen();
        }

        for (int i = 0; i < anzahl_schalter; i++) {
          ruckgabe = ruckgabe + o_schalter[i].schalter_internet_erstellen();
        }

        for (int i = 0; i < anzahl_menu; i++) {
          ruckgabe = ruckgabe + o_menu[i].menu_internet_erstellen();
        }

        ruckgabe = ruckgabe + "</div>";
      }



      return ruckgabe;

    }
    String frame_befehl_ausfuhren(String eingabe,
                                  int p_int[anz_parameter_csm_befehle] = new int[anz_parameter_csm_befehle],
                                  String p_str[anz_parameter_csm_befehle] = new String[anz_parameter_csm_befehle],
                                  float p_float[anz_parameter_csm_befehle] = new float[anz_parameter_csm_befehle],
                                  bool interpretiert = false) {

      String* nachstes_objekt;
      String ruckgabe = "false_frame";
      nachstes_objekt = get_nachstes_objekt(eingabe);
      String methodenname = "";
      if (nachstes_objekt[1] == "") {
        if (interpretiert == false) {
          methodenname = get_methode(eingabe,   //test123(1.535435,34534,\"avc\");//test123(1.535435,34534,"avc");
                                     p_int, p_str, p_float);
        }
        else
        {
          methodenname = eingabe;
        }
        //methode ausführen
        if (methodenname == "test123") {
          //ruckgabe = testmethode(p_float[0], p_int[1], p_str[2]);
        }
        else {
          // in verschachtelte objekte gehen
        }
      }
      else {
        if (nachstes_objekt[1] == "o_knopf") {
          ruckgabe = o_knopf[nachstes_objekt[2].toInt()].knopf_befehl_ausfuhren(nachstes_objekt[0]);
          //in nachstes Objekt gehen
        }
      }
      return ruckgabe;
    }

};

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
          if (o_frame[i].frame_objekte_abfrage() == true) {

            objekt_befehl_anfrage = objekt_befehl_anfrage + "o_label[" + String(i) + "].";
            return true;
          }
        }
      }

      return false;
    }

    String frames_internet_erstellen() {
      String ruckgabe = "";

      for (int i = 0; i < 10; i++) {


        ruckgabe = ruckgabe + o_frame[i].frame_internet_erstellen(); //"<script>console.log(read('/www/dynamisch/frame_" + String(i) + ".html'));</script>\n";



      }
      return ruckgabe;

    }



    void init(int _angezeigte_folie) {//Frmes und Knopfe werden initialisiert
//tft.fillRect (0, 40, 320, 440, TFT_BLACK);


        for (int i = 0; i<10; i++){
      o_frame[i].set_frame_nummer(i);
      o_frame[i].frame_objekte_nummerrieren();}

      
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

          wip[1] = o_frame[id_frame].get_y_pos() + wip[1];

          String wsp[anzahl_str_parameter];
          for (int c = 0; c < anzahl_str_parameter; c++) {
            ausgelesen = doc["frame"][a][str_parameter_maske[c]];
            wsp[c] = ausgelesen;
          }
          int8_t seite = doc["frame"][a]["seite"];
          o_frame[id_frame].frame_init(wip, wsp, seite);





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

              wip[1] = o_frame[id_frame].get_y_pos() + wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["label"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              o_frame[id_frame].o_label[id_label].label_init(wip, wsp);



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

              wip[1] = o_frame[id_frame].get_y_pos() + wip[1];

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
              o_frame[id_frame].o_knopf[id_knopf].knopf_init(wip, wsp, bf);



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

              wip[1] = o_frame[id_frame].get_y_pos() + wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["menu"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }
              o_frame[id_frame].o_menu[id_menu].label_init(wip, wsp);
              for (int c = 0; c < anzahl_str_parameter; c++) {
                if (str_parameter_maske[c] == "text") {
                  ausgelesen = doc["frame"][a]["menu"][b]["punkte"][0];
                }
                else {
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
              o_frame[id_frame].o_menu[id_menu].menu_init(wip, wsp, wmp);
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

              wip[1] = o_frame[id_frame].get_y_pos() + wip[1];

              String wsp[anzahl_str_parameter];
              for (int c = 0; c < anzahl_str_parameter; c++) {
                ausgelesen = doc["frame"][a]["schalter"][b][str_parameter_maske[c]];
                wsp[c] = ausgelesen;
              }

              bool anfangszustand = doc["frame"][a]["schalter"][b]["start"];

              o_frame[id_frame].o_schalter[id_schalter].schalter_init(wip, wsp, anfangszustand);



            }
          }





        }
      }
    }





    String folie_befehl_ausfuhren(String eingabe,
                                  int p_int[anz_parameter_csm_befehle] = new int[anz_parameter_csm_befehle],
                                  String p_str[anz_parameter_csm_befehle] = new String[anz_parameter_csm_befehle],
                                  float p_float[anz_parameter_csm_befehle] = new float[anz_parameter_csm_befehle],
                                  bool interpretiert = false) {

      String* nachstes_objekt;
      String ruckgabe = "false";
      nachstes_objekt = get_nachstes_objekt(eingabe);
      String methodenname = "";
      if (nachstes_objekt[1] == "") {
        if (interpretiert == false) {
          methodenname = get_methode(eingabe,   //test123(1.535435,34534,\"avc\");//test123(1.535435,34534,"avc");
                                     p_int, p_str, p_float);
        }
        else
        {
          methodenname = eingabe;
        }

        //methode ausführen


        if (methodenname == "test123") {
          // ruckgabe = testmethode(p_float[0], p_int[1], p_str[2]);
        }

        else {
          // in verschachtelte objekte gehen
        }
      }
      else {
        if (nachstes_objekt[1] == "o_frame") {
          ruckgabe = o_frame[nachstes_objekt[2].toInt()].frame_befehl_ausfuhren(nachstes_objekt[0]);
          //in nachstes Objekt gehen
        }
      }
      return ruckgabe;

    }

};
