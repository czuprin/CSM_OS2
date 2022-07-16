#define allgemein_nutzbar_x1 0
#define allgemein_nutzbar_x2 320
#define allgemein_nutzbar_y1  40
#define allgemein_nutzbar_y2  440

#define anz_parameter_csm_befehle 20
String angeschlossenser_sensor = "";
bool ist_sensor_angeschlossen = false;
bool sensor_status_aktualisiert = false;
int angezeigte_folie = 1;
#define anzahl_befehle 10
String objekt_befehl_anfrage;
String befehle_ausfuhren[anzahl_befehle];
String aktueller_restbefehl;

String ext_ssid = "Hotspot Clemens";
String ext_password = "123456789";
//String ext_ssid = "Powerline CR13";
//String ext_password = "6623687999950583";
String int_ssid = "CSM_V3.2_Wlan";
String int_password = "";
bool indexseite_aufgerufen = false;
uint16_t t_x = 0, t_y = 0; // To store the touch coordinates
boolean pressed;

int angezeigte_seite = 1;
bool touch_abfragen = true;

float mqtt_abfragefrequenz = 10;

String IpAddress2String(const IPAddress& ipAddress)
{
  return String(ipAddress[0]) + String(".") + \
         String(ipAddress[1]) + String(".") + \
         String(ipAddress[2]) + String(".") + \
         String(ipAddress[3])  ;
}


String* getValue(String data, char separator, int index)
{
  String *ruckgabe = new String[2];

  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  ruckgabe[0] =  data.substring(strIndex[1] + 1, maxIndex + 1);
  ruckgabe[1] = found > index ? data.substring(strIndex[0], strIndex[1]) : "";
  return ruckgabe;
}


bool noch_objekte_vorhanden(String eingabe) {
  bool  ruckgabe = true;
  if ((eingabe.indexOf('.') == -1) || (eingabe.indexOf('(') < eingabe.indexOf('.'))) {
    ruckgabe = false;
  }
  return ruckgabe;
}

String* get_nachstes_objekt(String eingabe) {
  String *ruckgabe = new String[3];

  if (noch_objekte_vorhanden(eingabe) == true) {
    String *eingabe2;
    eingabe2 = getValue(eingabe, '.', 0);
    ruckgabe[0] = eingabe2[0];
    ruckgabe[1] = eingabe2[1];

    int anfang_objektnummer = ruckgabe[1].indexOf("[", 0);
    int ende_objektnummer = ruckgabe[1].indexOf("]", 0);

    if (anfang_objektnummer == -1 && ende_objektnummer == -1) {
    }
    else {
      ruckgabe[2] =  (ruckgabe[1].substring(anfang_objektnummer + 1, ende_objektnummer));
      ruckgabe[1] = ruckgabe[1].substring(0, anfang_objektnummer);
    }
  }

  else {
    ruckgabe[0] = eingabe;
  }

  return ruckgabe;

}
int interpretiere_parameter(String* _eingabe) {
  int ruckgabe = 0;

  String eingabe = _eingabe[0];
  int string_marker[3];
  for (int i = 0; i < 3; i++) {
    string_marker[i] = eingabe.indexOf("\'", i);
  }
  //Serial.println(eingabe);
  if ((string_marker[0] == 0) && (string_marker[1] > string_marker[0]) && (string_marker[1] == string_marker[2])) {
    ruckgabe = 2;
    eingabe = eingabe.substring(string_marker[0] + 1, string_marker[1]);
  }
  else if (eingabe.indexOf(".", 0) == -1) {
    ruckgabe = 1;
  }
  else {
    ruckgabe = 3;
  }
  _eingabe[0] = eingabe;
  //Serial.println(eingabe);
  Serial.print("a");
  Serial.println(ruckgabe);
  return ruckgabe;
}

String get_methode(String eingabe, int ruckgabe_int[], String ruckgabe_str[], float ruckgabe_float[]) {


  String ruckgabe_methode = "";
  int eingabe_methode = eingabe.indexOf("(", 0);
  ruckgabe_methode =  eingabe.substring(0, eingabe_methode);
  eingabe = eingabe.substring(eingabe_methode + 1, eingabe.length());
  String* eingabe2 = new String[2];
  eingabe2[0] = eingabe;
  for (int i = 0; i < anz_parameter_csm_befehle; i++) {
    //  Serial.print("b");
    // Serial.println(i);
    if (eingabe2[0].indexOf(")", 0) > 0) {
      String parameter_uninterpretiert;
      bool abbruch = false;
      if (eingabe2[0].indexOf(",", 0) == -1) {
        //ruckgabe[i] =  eingabe2[0].substring(0, eingabe2[0].indexOf(")", 0));
        parameter_uninterpretiert =  eingabe2[0].substring(0, eingabe2[0].indexOf(")", 0));
        abbruch = true;
      }
      else {
        eingabe2 = getValue(eingabe2[0], ',', 0);
        parameter_uninterpretiert = eingabe2[1];
      }
      int parameterart = interpretiere_parameter(&parameter_uninterpretiert);

      String parameter_interpretiert = parameter_uninterpretiert;
      if (parameterart == 1) {
        ruckgabe_int[i] = parameter_interpretiert.toInt();
      }
      else if (parameterart == 2) {
        ruckgabe_str[i] = parameter_interpretiert;
      }
      else if (parameterart == 3) {
        ruckgabe_float[i] = parameter_interpretiert.toFloat();
      }
      if (abbruch == true) {
        break;
      }

    }
    else {
      break;
    }
  }


  return ruckgabe_methode;

}
