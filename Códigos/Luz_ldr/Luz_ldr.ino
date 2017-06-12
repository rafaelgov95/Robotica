int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.
int i; //Variável para contagem
void setup()
{
 pinMode(8,OUTPUT); 
 pinMode(7,OUTPUT); 
 pinMode(6,OUTPUT); 
 Serial.begin(9600);
 
}
 
void loop()
{
  int Sensor = analogRead(0);
  valorSensor = map(Sensor, 0, 1000, 0, 100);
  
   if (valorSensor < 750) {
    

    delay(900);
    
  }
   
  //Luminosidade média.
  if (valorSensor >= 750 && valorSensor<= 800) {
 
  }
   
  //Luminosidade alta.
  if (valorSensor > 800) {
  
  }


Serial.println(valorSensor);
}
