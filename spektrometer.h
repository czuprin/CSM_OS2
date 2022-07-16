#define maximalwert_wert 1.41

class c_saule {
  public:
    bool _genutzt = false;
    int breite = 0;
    int x_pos = 0;
    int y_pos = 0;
    int max_position = 0; // = 100
    float max_wert;
    int aktuelle_position = 0;
    float aktueller_wert = 0;
    int breite_label = 0;

    int hohe_label = 0;
    String text_label = "";
    int farbe = 0;

    c_label o_saule_label_text;
    c_label o_saule_label_wert;




    void erstelle_saule() {

      int16_t wip[anzahl_int_parameter] = {x_pos, y_pos + 3, breite_label, hohe_label, 2};
      String wsp[anzahl_str_parameter] = {"WHITE", "BLACK", "WHITE", text_label};

      o_saule_label_text.set_genutzt(true);
      o_saule_label_text.label_init(wip, wsp);
      o_saule_label_text.aktualisiere_label_hard();


      wip[1] = wip[1] + hohe_label + 2;
      wsp[0] =  "BLACK";
      wsp[3] =  "-";
      o_saule_label_wert.set_genutzt(true);
      o_saule_label_wert.label_init(wip, wsp);

      o_saule_label_wert.aktualisiere_label_hard();
    }


    void saule_init(int e1, int e2, int e3, int e4, float e5, int e6, float e7, int e8, int e9 , String e10, int e11) {

      breite = e1;
      x_pos = e2;
      y_pos = e3;
      max_position = e4; // = 100
      max_wert = e5;
      aktuelle_position = e6;
      aktueller_wert = e7;
      breite_label = e8;
      hohe_label = e9;
      text_label = e10;
      farbe = e11;
      erstelle_saule();
      _genutzt = true;
      Serial.println("Saule INIT");
    }

    void aktualisiere_position(float neuer_wert) {
      if (aktueller_wert == neuer_wert) {}
      else {
        int neue_position = (neuer_wert * max_position) / max_wert;
        if (aktuelle_position < neue_position) {
          for (int i = aktuelle_position + 1; i <= neue_position; i++) {
            tft.drawLine(x_pos, y_pos - i, x_pos + breite, y_pos - i, farbe);
          }
        }
        else if (aktuelle_position > neue_position) {
          for (int i = aktuelle_position; i > neue_position; i--) {
            tft.drawLine(x_pos, y_pos - i, x_pos + breite, y_pos - i, TFT_BLACK);
          }
        }
        aktuelle_position = neue_position;
        aktueller_wert = neuer_wert;

        o_saule_label_wert.aktualisiere_label(String(aktueller_wert));

      }



    }

    bool vorzeichen = false;

    float vorzeichenaddition(float eingabe) {
      int ruckgabe = eingabe;
      if (vorzeichen == false) {
        ruckgabe = ruckgabe * (-1);
      }
      return ruckgabe;
    }


    void ar() {
      float neuer_wert = vorzeichenaddition(random(max_wert / 10));
      int zwischenwert = neuer_wert + aktueller_wert;
      if (zwischenwert > max_wert || zwischenwert < 0) {
        zwischenwert = zwischenwert + neuer_wert * (-2);
        vorzeichen = !vorzeichen;
      }
      aktualisiere_position(zwischenwert);
    }

};
#include <Adafruit_AS7341.h>

Adafruit_AS7341 as7341;


int incomingByte = 0;
c_saule o_saule[10];
c_label o_knopf[3];

void init_spektometer() {


  tft.fillScreen(TFT_BLACK);


  /*
    int16_t wip[anzahl_int_parameter] = {0, 0, 50, 40, 2};
    String wsp[anzahl_str_parameter] = {"WHITE", "BLACK", "WHITE", "<"};
    o_knopf[1].label_init(wip, wsp);
    o_knopf[1].set_genutzt(true);
    o_knopf[1].aktualisiere_label_hard();

    wip[0] = 50;
    wip[1] = 0;
    wip[2] = 200;
    wip[3] = 40;
    o_knopf[2].label_init(wip, wsp);
    o_knopf[2].set_genutzt(true);
    o_knopf[2].aktualisiere_label_hard();

    wip[0] = 250;
    wip[1] = 0;
    wip[2] = 70;
    wip[3] = 40;
    wsp[3] =  "-";
    o_knopf[3].label_init(wip, wsp);
    o_knopf[3].set_genutzt(true);
    o_knopf[3].aktualisiere_label_hard();

  */

  tft.setRotation(1);

  o_saule[0].saule_init(30, 0, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "415nm", 0x701D);
  o_saule[0].aktualisiere_position(0);
  o_saule[1].saule_init(30, 60, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "445nm", 0x015F);
  o_saule[1].aktualisiere_position(0);
  o_saule[2].saule_init(30, 120, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "480nm", 0x06BF);
  o_saule[2].aktualisiere_position(0);
  o_saule[3].saule_init(30, 180, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "515nm", 0x3FE0);
  o_saule[3].aktualisiere_position(0);
  o_saule[4].saule_init(30, 240, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "555nm", 0xB7E0);
  o_saule[4].aktualisiere_position(0);
  o_saule[5].saule_init(30, 300, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "590nm", 0xFEE0);
  o_saule[5].aktualisiere_position(0);
  o_saule[6].saule_init(30, 360, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "630nm", 0x7D20);
  o_saule[6].aktualisiere_position(0);
  o_saule[7].saule_init(30, 420, 250, 240, maximalwert_wert, 0, 0, 60, 30 , "680nm", 0xF800);
  o_saule[7].aktualisiere_position(0);

Serial.println("begin");
if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }
  
  as7341.setATIME(100);
  as7341.setASTEP(100);
  as7341.setGain(AS7341_GAIN_256X);
Serial.println(2);
}



void aktualisiere_spektrometer1() {
  String eingabe = "";
//tft.loadFont("NotoSansBold15");
Serial.println("aktualisieren");
  uint16_t readings[12];
  float counts[12];
  if (!as7341.readAllChannels(readings)){
    Serial.println("Error reading all channels!");
    return;
  }

  for(uint8_t i = 0; i < 12; i++) {
    if(i == 4 || i == 5) continue;
    // we skip the first set of duplicate clear/NIR readings
    // (indices 4 and 5)
    counts[i] = as7341.toBasicCounts(readings[i]);
  }
  for (int i = 0; i<4;i++){
  o_saule[i].aktualisiere_position(counts[i]);
  }
    for (int i = 4; i<8;i++){
  o_saule[i].aktualisiere_position(counts[i+2]);
  }


}
