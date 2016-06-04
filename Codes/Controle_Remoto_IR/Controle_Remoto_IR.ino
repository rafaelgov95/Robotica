
#include <IRremoteInt.h>

#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  switch (Serial.read()) {
        case 'a':{
        irsend.sendNEC(180BD9FF, 32);
        Serial.println("Canal 0"); 
        break;
        }
        case 'b':{
        irsend.sendNEC(0x20DF8877, 32); 
        Serial.println("Canal 1");  
        break;
        } 
        case 'c':{
        irsend.sendNEC(0x20DF48B7, 32); 
        Serial.println("Canal 2"); 
        break; 
        } 
        case 'd':{
        irsend.sendNEC(0x20DFC837, 32); 
        Serial.println("Canal 3");  
        break;
        } 
        case 'e':{
        irsend.sendNEC(0x20DF28D7, 32);
        Serial.println("Canal 4");  
        delay(100); 
        }  
        case 'f':{
        irsend.sendNEC(0x20DFA857, 32);
        Serial.println("Canal 5"); 
        break;
        }
        case 'g':{
        irsend.sendNEC(0x20DF6897, 32); 
        Serial.println("Canal 6"); 
        break;
        } 
        case 'h':{
        irsend.sendNEC(0x20DFE817, 32); 
        Serial.println("Canal 7"); 
        break;
        } 
        case 'i':{
        irsend.sendNEC(0x20DF18E7, 32);  
        Serial.println("Canal 8");
        break;
        } 
        case 'j':{
        irsend.sendNEC(0x20DF9867, 32); 
        Serial.println("Canal 9"); 
        break;
        }  
        case 'l':{
        irsend.sendNEC(0x20DF10EF, 32);
        Serial.println("Ligando...ou... Desligando");
        delay(100);
        break;
        }
        case 'm':{
        irsend.sendNEC(0x20DFC03F, 32);
        Serial.println("Vol -");
        delay(100);
        break;
        }        
        case 'n':{
        irsend.sendNEC(0x20DF40BF, 32);
        Serial.println("Vol +");
        delay(100);
        break;
        }
        case 'p':{
        irsend.sendNEC(0x20DF00FF, 32);
        Serial.println("CH+");
        delay(100);
        break;
        }
        case 'q':{
        irsend.sendNEC(0x20DF807F, 32);
        Serial.println("CH-");
        delay(100);
        break;
        }
  }
  
}
