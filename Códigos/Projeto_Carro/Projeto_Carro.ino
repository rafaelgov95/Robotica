#include <IRremote.h>// incluindo a biblioteca do infravermelho    
int RECV_PIN = 5;

IRrecv irrecv(RECV_PIN);
decode_results results;
const int motorAA = 7;
const int motorAB = 6;
const int EnableA = 8;
const int motorBA = 11;
const int motorBB = 12;
const int EnableB = 10;

int FrenteDireita;
int FrenteEsquerda;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Inicializa o receptor IR
  pinMode(motorAA, OUTPUT);
  pinMode(motorAB, OUTPUT);
  pinMode(EnableA, OUTPUT);
  pinMode(motorBA, OUTPUT);
  pinMode(motorBB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  pinMode(EnableB, OUTPUT);
  analogWrite(EnableA, 200);
  analogWrite(EnableB, 200);
} void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    if (results.value == 0xA3C8EDDB) {
      Serial.println("Frente");
      moverFrente();
      delay(600);

    } else if (results.value == 0xF076C13B) {
      Serial.println("Tras");
      moverTras();
      delay(600);

    } else if (results.value == 0xD7E84B1B) {
      Serial.println("Direita");
      moverDireita();
      delay(200);

    } else if (results.value == 0x52A3D41F) {
      Serial.println("Esquerda");
      moverEsquerda();
      delay(200);

    }


    Stop();

    //


  }

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

