#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int BoutonVert = 2;
int  BoutonJaune = 3;
int  BoutonBleue = 4; 
int  BoutonRouge = 5;
//
void setup () {
  Serial.begin (9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (15);
  mp3_set_device(2);
 
  pinMode(BoutonVert, INPUT);
  pinMode(BoutonJaune, INPUT);
  pinMode(BoutonBleue, INPUT);
  pinMode(BoutonRouge, INPUT);
}


//
void loop () {  

  boolean etatBouton = digitalRead(BoutonVert);
   mp3_play ();
  if (etatBouton==HIGH)//test si bouton appuyé
  {
      Serial.print("la vie esy belle");
      Serial.print("\n");
       mp3_play ();
      delay (2000); 
  }  
 // mp3_play ();
  //delay (15000);
//  mp3_next ();
//  delay (6000);
//  mp3_prev ();
//  delay (6000);

}
