/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(14, 15);
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;        // value read from the pot
     

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (25);
  mp3_set_device(2);
 
}

void loop() {
  // read the analog in value:
 
  

  
    Serial.print("jaune ");
    mp3_play (1);
    delay (15000);
  

    if(sensorValue == 509)
  {
    Serial.print("Blzue ");
     mp3_play (2);
  //  delay (15000);
  }

    if(sensorValue == 679)
  {
    Serial.print("rouge ");
     mp3_play (3);
   // delay (15000);
  }
  

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
