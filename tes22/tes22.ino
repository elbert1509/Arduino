#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // TX, RX
DFRobotDFPlayerMini myDFPlayer;


void setup() 
{
 
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  myDFPlayer.begin(mySoftwareSerial);

  
  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
 
}

void loop()
{
 delay(10000);
    myDFPlayer.next();  //Play next mp3 every 3 second.
  

 
}
