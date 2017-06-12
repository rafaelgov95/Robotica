#include <Ultrasonic.h>
#define echoDireita 11
#define echoEsquerda 6

Ultrasonic ultrasonic(13,echoDireita); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonic2(13,echoEsquerda  ); 
void setup() {
Serial.begin(9600);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.print("CM Direita|| ");
  
  Serial.print(ultrasonic2.Ranging(CM)); // CM or INC
  Serial.println("CM Esquerda");
  delay(100);
}
