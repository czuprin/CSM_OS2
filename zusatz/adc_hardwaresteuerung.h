#pragma once
#define SELPIN 15 //Selection Pin 
#define DATAOUT 13//MOSI 
#define DATAIN  12//MISO 
#define SPICLOCK  14//Clock 
int readvalue; 
#include <SPI.h>
#include <driver/dac.h>

unsigned char ok_flag;
unsigned char fail_flag;

unsigned short lenth_val = 0;
unsigned char i2c_rx_buf[16];
unsigned char dirsend_flag=0;
int wie = 20;
void init_adc(){
    pinMode(SELPIN, OUTPUT); 
 pinMode(DATAOUT, OUTPUT); 
 pinMode(DATAIN, INPUT); 
 pinMode(SPICLOCK, OUTPUT); 
 //disable device to start with 
 digitalWrite(SELPIN,HIGH); 
 digitalWrite(DATAOUT,LOW); 
 digitalWrite(SPICLOCK,LOW); 
dac_output_enable(DAC_CHANNEL_1);}


int read_adc(int channel){
  int adcvalue = 0;
  byte commandbits = B11000000; //command bits - start, mode, chn (3), dont care (3)

  //allow channel selection
  commandbits|=((channel-1)<<3);

  digitalWrite(SELPIN,LOW); //Select adc
  delayMicroseconds(1);
  // setup bits to be written
  for (int i=7; i>=3; i--){
    digitalWrite(DATAOUT,commandbits&1<<i);
    //cycle clock
    digitalWrite(SPICLOCK,HIGH);
    digitalRead(DATAIN);
    digitalWrite(SPICLOCK,LOW);   
    digitalRead(DATAIN); 
  }

  digitalWrite(SPICLOCK,HIGH);    //ignores 2 null bits
  digitalRead(DATAIN);
  digitalWrite(SPICLOCK,LOW);
  digitalRead(DATAIN);
  digitalWrite(SPICLOCK,HIGH);  
  digitalRead(DATAIN);
  digitalWrite(SPICLOCK,LOW);

  //read bits from adc
  for (int i=11; i>=0; i--){
digitalRead(DATAIN);
    adcvalue+=digitalRead(DATAIN)<<i;
    //cycle clock

    digitalWrite(SPICLOCK,HIGH);
digitalRead(DATAIN);
    
      //delayMicroseconds(1);
    
  
    digitalWrite(SPICLOCK,LOW);

  }
  
  digitalWrite(SELPIN, HIGH); //turn off device
  return adcvalue;
}




  
#define MA 1000
int Messwerte[MA];  
void schreib_helligkeitsdaten(int adc){


//AVE Einstellen

dac_output_enable(DAC_CHANNEL_1);//einschalten des DACs
dac_output_voltage(DAC_CHANNEL_1, 0);
int a = 0;
Serial.println(1);
   while (read_adc(adc)>2000 && a<256){//Die Gegenspannung wird so lange erhöht bis die Spannung etwa 0,8V liegt oder die Gegenspannung maximal ist
                                              //Der Operationsverstärker hat eine maximale Ausgangsspannung von 2 V
    dac_output_voltage(DAC_CHANNEL_1, a); 
a = a+1;}

int optimaler_DAC = a;

  
//Messen
Serial.println(2);
  
  float zeit_alt = millis();

  for (int i = 0; i<MA; i++){
    Messwerte[i] = read_adc(adc) + read_adc(adc);
  }
  Serial.println(1);
  float zeit_neu = millis();
File file;

  file = SPIFFS.open("/y.csv" , "w");
  //file.println("Zeit in ms;Messwerte;DAC_Einstellung:;" + String(optimaler_DAC));
  
   for (int i = 0; i<MA-1; i++){
    file.print(String(Messwerte[i]));
    file.println(",");
  }
  file.print(String(Messwerte[MA-1]));
  
  file = SPIFFS.open("/x.csv" , "w");
  //file.println("Zeit in ms;Messwerte;DAC_Einstellung:;" + String(optimaler_DAC));
   for (int i = 0; i<MA-1; i++){
    file.print(String((zeit_neu - zeit_alt)*i/MA));
    file.print(",");
  }
  file.print(String((zeit_neu - zeit_alt)));
}
