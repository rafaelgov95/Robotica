
const int sensor = 0; // Analog pin 0
const int MOISTURE_LEVEL = 500; // the value after the LED goes ON

void setup() {
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    Serial.begin(9600);
}
 
void VermelhoLedState(int vermelhostate) {
    digitalWrite(13, vermelhostate);
}
void AmareloLedState(int amarelostate) {
    digitalWrite(12, amarelostate);
}
 void VerdeLedState(int verdestate) {
    digitalWrite(11, verdestate);
}

 
void loop() {
  int moisture = analogRead(sensor);
 
   moisture = map(moisture, 0, 1000, 0, 1000);
    
    Serial.println(moisture);
 
    if(moisture > MOISTURE_LEVEL) {
             VermelhoLedState(HIGH);
    } 
    else {
              VermelhoLedState(LOW);
         } 
    if(moisture < 500  && moisture > 130){
    
              AmareloLedState(HIGH);
    }else{
              AmareloLedState (LOW);
      } if(moisture < 130 ){
              VerdeLedState(HIGH);
    }else{
                 VerdeLedState(LOW);
    }
    delay(100);
}
