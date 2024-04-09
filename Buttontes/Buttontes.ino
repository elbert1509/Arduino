/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int button1 = 10;     // the number of the pushbutton pin
const int button2 =  11;      // the number of the LED pin
const int analogInPin = A0;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
// variables will change:
int button1State = 0; 
int button2State = 0; // variable for reading the pushbutton status

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int melody2[] = {
NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_G4 ,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4 ,NOTE_G4,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_D4,NOTE_C4};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
2,2,4,2,2,4,2,2,2,1,8,2,2,2,1,2,2,2,1,1,2,2,2,2,4,4,2,2,4,2,2,4,2,2,2,1,8,2,2,2,2,2,2,2,1,1,2,2,2,2,8 };



void setup() {
   Serial.begin(9600);
 
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
 
}


void melodie1 (){


 for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  
}


void melodie2(){

    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 1000 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration2 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  
}



void loop() {
  // read the state of the pushbutton value:
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);

   sensorValue = analogRead(analogInPin);
   outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);
   
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (outputValue == 0) {
    // turn LED on:
     Serial.print("Bouton rouge\n");
   melodie1();
  } 

  if (outputValue ==126) {
    // turn LED on:
     Serial.print("Bouton Bleu\n");
     melodie2();
    
  } 


  
}
