
#include <virtuabotixRTC.h>
#include <RvLib.h>
#include "Arduino.h"

virtuabotixRTC myRTC(2, 3, 4);
RvLib livfull;
void setup() {
    Serial.begin(9600);
    myRTC.setDS1302Time(00, 58, 23, 2, 17, 11, 2014);

}
void imprime_dia_da_semana(int dia)
{

    switch (dia)
    {
        case 1:
            Serial.print("Domingo");
            break;
        case 2:
            Serial.print("Segunda");
            break;
        case 3:
            Serial.print("Terca");
            break;
        case 4:
            Serial.print("Quarta");
            break;
        case 5:
            Serial.print("Quinta");
            break;
        case 6:
            Serial.print("Sexta");
            break;
        case 7:
            Serial.print("Sabado");
            break;
    }
}

void loop()
{
    digitalWrite(13,HIGH);
    Serial.println(livfull.getChave());
    delay(5000);
    digitalWrite(13,LOW);
    delay(5000);

    myRTC.updateTime();

    Serial.print("Data : ");
    imprime_dia_da_semana(myRTC.dayofweek);
    Serial.print(", ");
    Serial.print(myRTC.dayofmonth);
    Serial.print("/");
    Serial.print(myRTC.month);
    Serial.print("/");
    Serial.print(myRTC.year);
    Serial.print("  ");
    Serial.print("Hora : ");
    if (myRTC.hours < 10)
    {
        Serial.print("0");
    }
    Serial.print(myRTC.hours);
    Serial.print(":");
    if (myRTC.minutes < 10)
    {
        Serial.print("0");
    }
    Serial.print(myRTC.minutes);
    Serial.print(":");
    if (myRTC.seconds < 10)
    {
        Serial.print("0");
    }
    Serial.println(myRTC.seconds);

    delay( 1000);
}
