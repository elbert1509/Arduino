#include <Stepper.h>

// 32 pas par tour, reducteur de 1/64... Donc 32*64 pas pour 1 tour.
int NbPas = 2048;

//pour un moteur de 200 pas par tour et brancher sur les broches 6, 9, 10 et 11
Stepper moteur(NbPas, 9, 11, 10, 6);

void setup()
{
  moteur.setSpeed(15); 
}

void loop()
{
  //Faire un tour = 2048 pas dans le sens 1
  moteur.step(2048);
  delay(200);
  //Faire un tour = 2048 pas dans le sens 2
  moteur.step(-2048);
} 
