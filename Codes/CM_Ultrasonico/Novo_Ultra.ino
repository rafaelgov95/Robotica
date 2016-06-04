#include <Ultrasonic.h>



Ultrasonic ultrasonic(3,4); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonic2(3,6  ); 
void setup() {
Serial.begin(9600);
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.print("CM || ");
  
  Serial.print(ultrasonic2.Ranging(CM)); // CM or INC
  Serial.println("CM");
  delay(100);
}
