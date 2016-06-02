#include <Servo.h>
#include "Ultrasonic.h"

const int motorAA = 6;
const int motorAB = 7;
const int EnableA = 8;
const int motorBA = 3;
const int motorBB = 4;
const int EnableB = 2;

int DelayFrente = 25;
int FrenteDireita;
int FrenteEsquerda;

Ultrasonic cabeca(11, 12);
Servo motor;
typedef enum {
  ESQUERDA, DIREITA
} lado;

typedef enum {
  ANDANDO, TOMAR_DECISAO
} estado;

typedef void (*Action)();

estado estadoAtual=ANDANDO;

Action actions[2];



void setup() {
  Serial.begin(9600);
  motor.attach(10);
  pinMode(motorAA, OUTPUT);
  pinMode(motorAB, OUTPUT);
  pinMode(EnableA, OUTPUT);
  pinMode(motorBA, OUTPUT);
  pinMode(motorBB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  analogWrite(EnableA, 128);
  analogWrite(EnableB, 128);
  motor.write(90);
  actions[0] = toDeBoa;
  actions[1] = decisao;

}

void loop() {
  
  actions[estadoAtual]();
//toDeBoa();
}
void toDeBoa() {
  moverFrente();
  delay(25);
  Stop();
  delay(500);
  if (distancia() <= 10) {
    estadoAtual = TOMAR_DECISAO;
  }
}
float distancia() {
  long microsec = cabeca.timing();
  float cmMsec = cabeca.convert(microsec, Ultrasonic::CM);
  Serial.println(cmMsec);
  return cmMsec;
}


boolean ladoLivre(int l) {
  motor.write(l == ESQUERDA ? 180 : 0);
  delay(2000);
  if (distancia() > 10) {
    return true;
  }
  return false;
}
void decisao() {
  Stop();
  if (ladoLivre(ESQUERDA) == true) {
    moverEsquerda();
    delay(300);
    Stop();
  } else if (ladoLivre(DIREITA) == true) {
    moverDireita();
    delay(300);
    Stop();
  } else {
    moverTras();
    delay(300);
    Stop();
  }
}
void Stop() {
  digitalWrite(motorAA, LOW);
  digitalWrite(motorAB, LOW);
  digitalWrite(motorBA, LOW);
  digitalWrite(motorBB, LOW);
}
void moverDireita() {
  digitalWrite(motorAA, LOW);
  digitalWrite(motorAB, HIGH);
  digitalWrite(motorBA, LOW);
  digitalWrite(motorBB, HIGH);
}
void moverEsquerda() {
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

