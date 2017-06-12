#include <Servo.h>
#include <Ultrasonic.h>
Ultrasonic ultrasonic(3, 4);
Servo motor;
#define SERVO 13

const int motorAA = 7;
const int motorAB = 6;
const int EnableA = 8;
const int motorBA = 11;
const int motorBB = 12;
const int EnableB = 10;
void setup ()
{
  motor.write(85);
  motor.attach(SERVO);
  Serial.begin(9600);
  pinMode(motorAA, OUTPUT);
  pinMode(motorAB, OUTPUT);
  pinMode(EnableA, OUTPUT);
  pinMode(motorBA, OUTPUT);
  pinMode(motorBB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  analogWrite(EnableA, 200);
  analogWrite(EnableB, 200);
}
int Distancia() {
  float cmMsec;
  for (int i = 0; i < 10; i++) {
    long microsec = ultrasonic.timing();
    cmMsec += ultrasonic.convert(microsec, Ultrasonic::CM);
    delay(30);
  }
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec / 10);
  return cmMsec / 10;
}
void loop()

{
  moverFrente();
  delay(600);
  if (Distancia() < 20 ) {
    delay(50);
    motor.write(20);
    delay(600);
    if ( Distancia() < 20 ) {
      delay(50);
      motor.write(85);
      delay(600);
      if (Distancia() < 20 ) {
        delay(50);
        motor.write(160);
        delay(600)    ;
        if (Distancia() < 20 ) {
          delay(50);
          motor.write(85);
          delay(600);
          if (Distancia() < 20 ) {
            delay(50);
            motor.write(20);
            delay(600);
          }
        }
      }
    } else {
     moverDireita();
     delay(10);
     Stop(); 
    }
  } else {
    moverFrente();
    delay(100);
    Stop();
  }
  Stop();
}

void Stop() {
  digitalWrite(motorAA, LOW);
  digitalWrite(motorAB, LOW);
  digitalWrite(motorBA, LOW);
  digitalWrite(motorBB, LOW);
}
void moverEsquerda() {
  digitalWrite(motorAA, LOW);
  digitalWrite(motorAB, HIGH);
  digitalWrite(motorBA, LOW);
  digitalWrite(motorBB, HIGH);
}
void moverDireita() {
  digitalWrite(motorAA, HIGH);
  digitalWrite(motorAB, LOW);
  digitalWrite(motorBB, LOW);
  digitalWrite(motorBA, HIGH);
}

void moverTras() {
  digitalWrite(motorAA, HIGH);
  digitalWrite(motorAB, LOW);
  digitalWrite(motorBA, LOW);
  digitalWrite(motorBB, HIGH);
}

void moverFrente() {
  digitalWrite(motorAA, LOW);
  digitalWrite(motorAB, HIGH);
  digitalWrite(motorBA, HIGH);
  digitalWrite(motorBB, LOW);


}

