#include <TFT_eSPI.h>      // Hardware-specific library
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(); // Invoke custom library
#include <c_qrcode.h>
QR_CODE o_qrcode(&tft);




void t_aktual() {
  pressed = tft.getTouch(&t_x, &t_y);

}

#include "objekte_csm.h"
#include "vorprogrammierte_funktionen.h"

c_frame o_steuerungs_elemente;


void init_steuerungselemente() {
  o_steuerungs_elemente.set_genutzt(true);
  int16_t wip[anzahl_int_parameter] = {0, 0, 50, 40, 2};
  String wsp[anzahl_str_parameter] = {"WHITE", "BLACK", "WHITE", "<"};
  String bf[anzahl_befehle] = {"offne_seite(1);"};
  o_steuerungs_elemente.o_knopf[1].set_genutzt(true);
  o_steuerungs_elemente.o_knopf[1].knopf_init(wip, wsp, bf);


  wip[0] = 50;
  wip[1] = 0;
  wip[2] = 200;
  wip[3] = 40;
  wsp[3] =  "kein Sensor";
  bf[1] = "";
  o_steuerungs_elemente.o_knopf[2].set_genutzt(true);
  o_steuerungs_elemente.o_knopf[2].knopf_init(wip, wsp, bf);

  wip[0] = 250;
  wip[1] = 0;
  wip[2] = 70;
  wip[3] = 40;
  wsp[3] =  "-";
  bf[1] = "test";
  o_steuerungs_elemente.o_knopf[3].set_genutzt(true);
  o_steuerungs_elemente.o_knopf[3].knopf_init(wip, wsp, bf);






  o_steuerungs_elemente.bildschirm_frame_aktualisieren(true);
}


void init_Grafik_Display_Steuerung() {
  // Initialise the TFT screen
  tft.init();
  o_qrcode.init();
  // Set the rotation before we calibrate
  tft.setRotation(0);
  // Calibrate the touch screen and retrieve the scaling factors
  uint16_t calData[5] = { 247, 3614, 247, 3664, 7 };
  tft.setTouch(calData);
  // Draw keypad background
  tft.fillScreen(TFT_BLACK);
  init_steuerungselemente();
}

//void frame_anzeigen(int _angezeigtes_frame){
//  angezeigtes_frame = _angezeigtes_frame;
//  for (int a = 0; a < anzahl_knopf; a++) {
//    o_knopf[_angezeigtes_frame,a].aktualisieren();
//  }

//}
