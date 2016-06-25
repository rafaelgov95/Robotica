#include <virtuabotixRTC.h>
const int amarelo = 10;
const int verde = 11;
const int vermelho = 12;
const int botao = 5;
const int buzzer = 6;
const int clok = 4;
const int data = 3;
const int rst = 2;
boolean ativar = false;
virtuabotixRTC myRTC(clok, data, rst);
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT);
  myRTC.setDS1302Time(00, 00, 00, 2, 17, 11, 2014);
}
void detonar() {
  int fiovermelho = analogRead(1);
  fiovermelho = map(fiovermelho, 0, 1000, 0, 1000);
  Serial.println(fiovermelho);
  if (fiovermelho < 1000) {
    chamaBum();
  } else {
    return ;
  }
}
void chamaBum() {
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);

  while (true) {
    tone(buzzer, 1000, 200);
  }
}
void tempoDetona() {
  myRTC.updateTime();

  if ( myRTC.seconds > 40) {
    tone(buzzer, 1800, 100);
    delay(10);
  }
  if ( myRTC.seconds > 50) {
    chamaBum();


  }


}
void ativarr() {
  
   digitalWrite(verde,LOW);
    
  digitalWrite(amarelo,HIGH);

  while (ativar) {
    detonar();
    ativar = fioverde();
    tone();
    tempoDetona();

  }

}
void loop() {
   digitalWrite(verde,HIGH);
    
  Serial.println(myRTC.seconds);
  Serial.println(digitalRead(botao));
  if (digitalRead(botao) > 0) {
    ativar = true;
  } else {
    ativar = false;
  }

  if (ativar) {
    ativarr();
  }


}

void tone() {
  tone(buzzer, 1500, 20);
  delay(300);
}
boolean fioverde() {
  int fioverde = analogRead(0);
  fioverde = map(fioverde, 0, 1000, 0, 1000);
  Serial.println(fioverde);
  if (fioverde < 1000) {
    return false;
  } else {
    return true;
  }
}
