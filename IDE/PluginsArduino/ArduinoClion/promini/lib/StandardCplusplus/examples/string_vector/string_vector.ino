//Programa : Modulo bluetooth HC-06 - Configuracao
//Autor : Adilson Thomsen
 
//Carrega a biblioteca SoftwareSerial
#include <SoftwareSerial.h>
    
//Define os pinos para a serial  (RX, TX)
SoftwareSerial MinhaSerial(11,10);
String command = "";
    
void setup()  
{ 
  //Inicia a serial 
  Serial.begin(115200); 
  Serial.println("Digite os comandos AT :"); 
  //Inicia a serial configurada nas portas 6 e 7
  MinhaSerial.begin(9600); 
} 
    
void loop() 
{ 
  if (MinhaSerial.available())
  { 
     while(MinhaSerial.available())
     {
       command += (char)MinhaSerial.read(); 
     } 
   Serial.println(command); 
   command = ""; 
  } 
  
  if (Serial.available()) 
  { 
    delay(10);
    MinhaSerial.write(Serial.read()); 
  } 
}
