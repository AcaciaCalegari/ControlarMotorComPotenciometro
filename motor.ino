//Controlar pra onde o servo motor gira com o Potenciomêtro
//AcaciaCalegari
//29/01/2019
//O pino do meio do potenciometro eh o arduino
//o pino do meio do motor no positivo
#include <VarSpeedServo.h>

#define pinServo 8 //pino do motor no digital 8
#define pinPotenciometro A0 //potenciometro no Analogico 8

VarSpeedServo servo1; //declarando um nome p poder controlar a velocidade


void setup() {
  
  servo1.attach(pinServo); //falando p motor "se liga, mano"
  Serial.begin(9600); //Ajuste da Tranferencia de bits p seg

  
}

void loop() {
  
  int lido = analogRead(pinPotenciometro); //ler o potenciometro p poder
  byte angulo = map(lido, 0, 1023, 0, 179); //girar o motor igual ele

  
  servo1.slowmove(angulo, 40); //velocidade do motor q vai de 0 a 250

//Aki eh se qser ver no serial do arduino q angulo q o motor tah
  Serial.print("A0:");
  Serial.print(lido);
  Serial.print(" angulo:");
  Serial.println(angulo);
  
}
