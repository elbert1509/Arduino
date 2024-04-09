#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

int rangee[] = {9, 8, 7, 6};
int colonne[] = {10, 11, 12, 13};
int col_scan;
SoftwareSerial mySerial(4, 5); // RX, TX
void setup()
{
 Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (25);
  mp3_set_device(2);
  
 for (int i = 0; i <= 3; i++)
 {
 // Initialisation des broches
 pinMode(rangee[i], OUTPUT);
 pinMode(colonne[i], INPUT);
 digitalWrite(colonne[i], HIGH);
 }
 Serial.println("====== Clavier pret ======");
  start ();
}
void loop()
{

//  if (go ==1)
//  {
//    void start ()
//  }
//  
//  void start () ;
   // Regarde si un bouton est enfoncé
   for (int i = 0; i <= 3; i++)
   {
     digitalWrite(rangee[0], HIGH);
     digitalWrite(rangee[1], HIGH);
     digitalWrite(rangee[2], HIGH);
     digitalWrite(rangee[3], HIGH);
     digitalWrite(rangee[i], LOW);
       for (int j = 0; j <= 3; j++)
       {
       col_scan = digitalRead(colonne[j]);
       if (col_scan == LOW)
         {
         // Lorsqu'un bouton est enfoncé, appel de la fonction toucherBouton
         // pour savoir quel bouton est enfoncé
         toucherBouton(i, j);
         delay(300);
        }
     }
   }
}


void start () 
{
   mp3_play (11);
    delay (7000);
}


// Fonction de reconnaissance et affichage du bouton enfoncé
void toucherBouton(int i, int j)
{
   if (i == 0 && j == 0) // Bouton S1 enfoncé
   {
    Serial.println("S1");
    mp3_play (1);
    delay (7000);
   }
   if (i == 0 && j == 1) // Bouton S2 enfoncé
   {
    Serial.println("S2");
     mp3_play (2);
     
   }
  
   if (i == 0 && j == 2) // Bouton S3 enfoncé
   {
    Serial.println("S3");
    mp3_play (3);
    delay (7000);
   }
   
   if (i == 0 && j == 3) // Bouton S4 enfoncé
   {
    Serial.println("S4");
    mp3_play (4);
    delay (7000);
   }
   
   if (i == 1 && j == 0) // Bouton S5 enfoncé
   {
    Serial.println("S5");
    mp3_play (5);
    delay (7000);
   }
   
   if (i == 1 && j == 1) // Bouton S6 enfoncé
   {
    Serial.println("S6");
    mp3_play (6);
    delay (7000);
   }
   
   if (i == 1 && j == 2) // Bouton S7 enfoncé
   {
    Serial.println("S7");
    mp3_play (7);
    delay (7000);
   }
   
   if (i == 1 && j == 3) // Bouton S8 enfoncé
   {
    Serial.println("S8");
    mp3_play (8);
    delay (7000);
   }

   if (i == 2 && j == 0) // Bouton S9 enfoncé
   {
    Serial.println("S9");
    mp3_play (9);
    delay (7000);
   }
   
   if (i == 2 && j == 1) // Bouton S10 enfoncé
   {
    Serial.println("S10");
     mp3_play (10);
     delay (7000);
   }
  
   if (i == 2 && j == 2) // Bouton S11 enfoncé
   Serial.println("S11");
   if (i == 2 && j == 3) // Bouton S12 enfoncé
   Serial.println("S12");
   if (i == 3 && j == 0) // Bouton S13 enfoncé
   Serial.println("S13");
   if (i == 3 && j == 1) // Bouton S14 enfoncé
   Serial.println("S14");
   if (i == 3 && j == 2) // Bouton S15 enfoncé
   Serial.println("S15");
   if (i == 3 && j == 3) // Bouton S16 enfoncé
   Serial.println("S16");
}
