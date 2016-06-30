
/**
  Example: Hello, MySQL!

  This code module demonstrates how to create a simple
  database-enabled sketch.
*/
#include "SPI.h"
#include "Ethernet.h"
#include "sha1.h"
#include "mysql.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 3
OneWire oneWire(ONE_WIRE_BUS);
float tempMax = 0;
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

//sql
int sensorLuz = 100;
int sensorTemp = 0;
boolean sqlconnect;
char sqlbuf[128];
char sqlDbase[] = " USE sensores";
/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(130, 211, 75, 60);

/* Setup for the Connector/Arduino */
Connector my_conn; // The Connector/Arduino reference

char user[] = "root";
char password[] = "root";

void setup() {
  Ethernet.begin(mac_addr);
  Serial.begin(115200);
  Serial.println("Connecting...");
  sensors.begin();
  Serial.print(sensors.getDeviceCount(), DEC);
  boolean teste = false;
  teste = sensors.getAddress(sensor1, 0);
  teste ? Serial.println("TRUE") : Serial.println("FALSE");
}
void loop() {
  conect ?


}
void lerSensores() {
  // Le a informacao do sensor
  sensors.requestTemperatures();
  sensorTemp = (int)sensors.getTempC(sensor1);
  sensorLuz = luz();
  Serial.println(sensorTemp);
  Serial.println(sensorLuz);
  UpdateMsql();
}
boolean conect() {
  while (!msql) {
    if (my_conn.mysql_connect(server_addr, 3306, user, password))
    {
      delay(500);
      msql = true;
      Serial.println("Conectado!!");
    }
    else {
      Serial.println("Connection failed.");

    }
    delay(2000);
  }
}

int luz() {
  int luz = analogRead(0);
  luz = map(luz, 0, 1024, 0, 100);
  return (luz - 100) * -1;
}
void UpdateMsql() {
  delay(150000);
  sprintf(sqlbuf, "INSERT INTO Hidroponia.sensores(luzSensor,tempSensor,date) values ('%d','%d',now())", sensorLuz, sensorTemp) ;
  my_conn.cmd_query(sqlbuf);
  Serial.println("Salvo!!");
  delay(150000);
}
