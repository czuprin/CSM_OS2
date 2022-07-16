#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
class sensor_tsl2591 {
  public:
  String sensorname = "TSL2591";
  String datenbezeichner[anz_sensor_werte];
  String messdaten[anz_sensor_werte];
  Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)
void init(){
  tsl.begin();
  tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  datenbezeichner[0] = "IR";
  datenbezeichner[1] = "Voll";
  datenbezeichner[2] = "Sichtbar";
  datenbezeichner[3] = "Lux";
}

  void aktualisiere_messdaten(){
      // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
  // That way you can do whatever math and comparisons you want!
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
    messdaten[0] = String(ir);
    messdaten[1] = String(full); 
    messdaten[2] = String(full - ir); 
    messdaten[3] = String(tsl.calculateLux(full, ir), 6);
    
  }
  String* get_messdaten(){
    return messdaten;
  }
  String* get_datenbezeichner(){
    return datenbezeichner;
  }
};
