#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

int rangee[] = {9, 8, 7, 6};
int colonne[] = {0, 1, 2, 3};
int col_scan;
SoftwareSerial mySoftwareSerial(10, 11); // TX, RX
DFRobotDFPlayerMini myDFPlayer;
int langue = 1;

void setup() 
{
 
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  myDFPlayer.begin(mySoftwareSerial);

  
  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3

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
// delay(10000);
   // myDFPlayer.next();  //Play next mp3 every 3 second.
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
   myDFPlayer.playLargeFolder (langue,11);
    delay (7000);
}


void toucherBouton(int i, int j)
{
   if (i == 0 && j == 0) // Bouton S1 enfoncé
   {
    Serial.println("S1");
    myDFPlayer.playLargeFolder (langue,1);
    delay (7000);
   }
   if (i == 0 && j == 1) // Bouton S2 enfoncé
   {
    Serial.println("S2");
     myDFPlayer.playLargeFolder (langue,2);
     
   }
  
   if (i == 0 && j == 2) // Bouton S3 enfoncé
   {
    Serial.println("S3");
    myDFPlayer.playLargeFolder (langue,3);
    delay (7000);
   }
   
   if (i == 0 && j == 3) // Bouton S4 enfoncé
   {
    Serial.println("S4");
    myDFPlayer.playLargeFolder (langue,4);
    delay (7000);
   }
   
   if (i == 1 && j == 0) // Bouton S5 enfoncé
   {
    Serial.println("S5");
    myDFPlayer.playLargeFolder (langue,5);
    delay (7000);
   }
   
   if (i == 1 && j == 1) // Bouton S6 enfoncé
   {
    Serial.println("S6");
    myDFPlayer.playLargeFolder (langue,6);
    delay (7000);
   }
   
   if (i == 1 && j == 2) // Bouton S7 enfoncé
   {
    Serial.println("S7");
    myDFPlayer.playLargeFolder (langue,7);
    delay (7000);
   }
   
   if (i == 1 && j == 3) // Bouton S8 enfoncé
   {
    Serial.println("S8");
    myDFPlayer.playLargeFolder (langue,8);
    delay (7000);
   }

   if (i == 2 && j == 0) // Bouton S9 enfoncé
   {
    Serial.println("S9");
    myDFPlayer.playLargeFolder (langue,9);
    delay (7000);
   }
   
   if (i == 2 && j == 1) // Bouton S10 enfoncé
   {
    Serial.println("S10");
     myDFPlayer.playLargeFolder (langue,10);
     delay (7000);
   }
  
   if (i == 2 && j == 2) // Bouton S11 enfoncé
   Serial.println("S11");
   if (i == 2 && j == 3) // Bouton S12 enfoncé
   Serial.println("S12");
   if (i == 3 && j == 0) // Bouton S13 enfoncé
   {

    langue=2;
     Serial.println("S13");
     start();
     Serial.println("Changement de langues");
   }
   
   Serial.println("S13");
   if (i == 3 && j == 1) // Bouton S14 enfoncé
   {
      langue=0;
     Serial.println("S14");
     start();
     Serial.println("Changement de langues");
    
   }
   Serial.println("S14");
   if (i == 3 && j == 2) // Bouton S15 enfoncé

   {
      langue=1;
     Serial.println("S15");
     start();
     Serial.println("Changement de langues");

    
   }
   Serial.println("S15");
   if (i == 3 && j == 3) // Bouton S16 enfoncé
   Serial.println("S16");
}
