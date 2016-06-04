#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
#define LAMP 8 //Define o LAMP como 8
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD
 
  //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.

 int i; //Variável para contagem
void setup()
{
 pinMode(LAMP,OUTPUT); //Define o pino D8 como saída
 lcd.begin(16, 2);
 Serial.begin(9600);
 
}
 
void loop()
{
  int Sensor = analogRead(0);
  valorSensor = map(Sensor, 0, 1000, 0, 100);
  
   if (valorSensor < 750) {
    lcd.clear();
   lcd.setCursor(0,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
   lcd.print("LUZ AMBIENTE:"); //Escreve no LCD "Olá Garagista!"
    lcd.setCursor(14,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
    lcd.print(valorSensor); //Escreve no LCD "Olá Garagista!"

    delay(900);
    
  }
   
  //Luminosidade média.
  if (valorSensor >= 750 && valorSensor<= 800) {
    lcd.clear();
      lcd.setCursor(0,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
   lcd.print("LUZ AMBIENTE:"); //Escreve no LCD "Olá Garagista!"
    lcd.setCursor(14,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
    lcd.print(valorSensor); //Escreve no LCD "Olá Garagista!"
       lcd.setCursor(0,1);  //posiciona o cursor na coluna 0 linha 1 do LCD.
    lcd.print("LUZ DESLIGADA "); //Escreve no LCD "Olá Garagista!"
    
    delay(900);
    
   
  }
   
  //Luminosidade alta.
  if (valorSensor > 800) {
    lcd.clear();
      lcd.setCursor(0,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
   lcd.print("LUZ AMBIENTE:"); //Escreve no LCD "Olá Garagista!"
    lcd.setCursor(14,0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
    lcd.print(valorSensor); //Escreve no LCD "Olá Garagista!"
    lcd.setCursor(0,1);  //posiciona o cursor na coluna 0 linha 1 do LCD.
    lcd.print("LUZ DESLIGADA "); //Escreve no LCD "Olá Garagista!"
                  delay(900);
 
  
  }



  int LDR=0; //Zera a variável LDR
  for(i=0;i<=10;i++) //Faz 10 vezes a leitura do sensor
  {
  Sensor=analogRead(A0); //Lê o valor do sensor (LDR ligado ao pino A0) e guarda na variável LDR
  LDR = LDR+Sensor; //Armazenamento na varíavel LDR o valor lido + o valor anterior
  delay(10); //Delay se 10 milissegundos
  }
  LDR=LDR/10; //Divide o valor armazenado por 10
  Serial.println(LDR); //Imprime o valor do LDR

  (LDR >= 400) ? (digitalWrite(LAMP,HIGH)) : (digitalWrite(LAMP,LOW));
  //Se o valor lido (luminosidade) for maior ou igual a 400, liga a lâmpada, senão desliga a lâmpada
  (LDR >= 400) ?   ( lcd.setCursor(0,1 lcd.print("LUZ LIGADA ");
    :( lcd.setCursor(0,1) 
    lcd.print("LUZ DESLIGADA"));


Serial.println(valorSensor);
}
