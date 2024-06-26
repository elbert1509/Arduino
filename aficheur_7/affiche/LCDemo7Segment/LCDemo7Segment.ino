//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(8,13,9,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=250;
char tab1[]="HELL0";

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,10);
  /* and clear the display */
  lc.clearDisplay(0);
}


/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0. 
 */
void writeArduinoOn7Segment() {
  //lc.setChar(0,0,'',false);
  lc.setChar(0,1,'_',false);
  lc.setChar(0,2,'_',false);
  lc.setChar(0,3,'0',false);
  lc.setChar(0,4,'L',false);
  lc.setChar(0,5,'L',false);
  lc.setChar(0,6,'E',false);
  lc.setChar(0,7,'H',false);
  delay(delaytime);
  //lc.setChar(0,0,'',false);
  //lc.setChar(0,1,'',false);
  lc.setChar(0,2,'H',false);
  lc.setChar(0,3,'A',false);
  lc.setChar(0,4,'J',false);
  lc.setChar(0,5,'I',false);
  lc.setChar(0,6,'L',false);
  lc.setChar(0,7,'E',false);
  delay(delaytime);

} 

void chennillard()
{
  char hello[] = "0LLEH";
  for(int i = 0; i < 5; i++)
  {
    lc.setChar(0, 4, hello[i], false);
    lc.setChar(0, 3, hello[i+1], false);
    lc.setChar(0, 2, hello[i+2], false);
    lc.setChar(0, 1, hello[i+3], false);
    lc.setChar(0, 0, hello[i+4], false);
    delay(delaytime);
  }
}

void chennillard1 ()
{
  for(int i=0; i<6 ;i++)
  {
     lc.setChar(0,i,tab1[i],false);
     delay(delaytime);

  }

}

/*
  This method will scroll all the hexa-decimal
 numbers and letters on the display. You will need at least
 four 7-Segment digits. otherwise it won't really look that good.
 */
void scrollDigits() {
  for(int i=0;i<13;i++) {
    lc.setDigit(0,3,i,false);
    lc.setDigit(0,2,i+1,false);
    lc.setDigit(0,1,i+2,false);
    lc.setDigit(0,0,i+3,false);
    delay(delaytime);
  }
  lc.clearDisplay(0);
  delay(delaytime);
}

void loop() { 
  //writeArduinoOn7Segment();
  chennillard();
  //scrollDigits();
}
