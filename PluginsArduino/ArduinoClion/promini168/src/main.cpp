#include <../lib/StandardCplusplus/StandardCplusplus.h>
#include <../lib/StandardCplusplus/string>
#include <Arduino.h>
#include <../lib/StandardCplusplus/vector>
#include <./../lib/RvLib/RvLib.h>
//#include <StandardCplusplus.h>
//#include <./../lib/StandardCplusplus>
//#include <string>
//#include <vector>
#include <./../lib/StandardCplusplus/iterator>
#include <iostream>
//#include <sstream>
using namespace std;
string arte ="Loco funcionou";
string teste="teste";
vector<string> strings;
RvLib MinhaLib;
void setup()
{
    Serial.begin(9600);
    pinMode(5,OUTPUT);

}

void loop()

{

    Serial.print(teste.c_str());
    strings.push_back(MinhaLib.getChave().c_str());
    strings.push_back("world!");
    for (int i = 0; i < 2 ; ++i){
        string tes = strings.back();
        Serial.println(tes.c_str());
        strings.pop_back();
        delay(100);
    }
    delay(100);

}

// vim:cin:ai:sts=2 sw=2 ft=cpp