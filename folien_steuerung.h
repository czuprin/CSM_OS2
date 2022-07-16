#include "grafik_display_steuerung.h"
c_folie folie1;
//c_folie aasdasd[4];


void offne_seite(int eingabe) {
  angezeigte_seite = eingabe;
  tft.fillRect (0, 40, 320, 440, TFT_BLACK);// lösche den Bereich auf dem die alte Folie angezeigt wurde
  folie1.seite_aktualisieren(eingabe, true);
}

void init_folien_steuerung() {
  init_Grafik_Display_Steuerung();

  //seite_anzeigen
  //frame_anzeigen(1);
  //for(int i = 0;i<8;i++){
  //folie1.o_frame[2].o_menu[1].set_auswahl( i,String(i));}

  folie1.init(angezeigte_folie);
  //folie1.seite_aktualisieren(1,true);


  //folie1.o_frame[1].o_label[1].aktualisiere_label(false);

}
