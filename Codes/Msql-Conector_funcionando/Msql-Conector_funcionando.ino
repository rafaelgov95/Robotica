
/**
  Example: Hello, MySQL!

  This code module demonstrates how to create a simple
  database-enabled sketch.
*/
#include <DHT.h>
#include "SPI.h"
#include "Ethernet.h"
#include "sha1.h"
#include "mysql.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 3
//sensor agua
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//sensor de tempertaura de ambiente
DeviceAddress sensor1;
int sensorAmbi = 0;
int sensorLuz = 0;
int sensorTemp = 0;
char sqlbuf[128];
char sqlDbase[] = " USE sensores";
/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(130, 211, 75, 60);
/* Setup for the Connector/Arduino */
Connector my_conn; // The Connector/Arduino reference
char user[] = "root";
char password[] = "root";
DHT dht(4, DHT22);
void setup() {
  Ethernet.begin(mac_addr);
  Serial.begin(115200);
  Serial.println("Connecting...");
  dht.begin();
  //sensor de agua
  sensors.begin();
  Serial.print(sensors.getDeviceCount(), DEC);
  sensors.getAddress(sensor1, 0) ? Serial.println("TRUE") : Serial.println("FALSE");
}

void lerSensores() {
  // Le a informacao do sensor
  delay(5000);
  sensorAmbi = (int)dht.readTemperature();
  sensors.requestTemperatures();
  sensorTemp = (int)sensors.getTempC(sensor1);
  sensorLuz = luz();
  Serial.println(" Ambiente : " + sensorAmbi);
  Serial.println(" Sensor Agua: " + sensorTemp);
  Serial.println("Sensor Luz " + sensorLuz);
  UpdateMsql();
}


int luz() {
  int luz = analogRead(0);
  luz = map(luz, 0, 1024, 0, 100);
  return (luz - 100) * -1;
}
void UpdateMsql() {
  delay(140000);
  sprintf(sqlbuf, "INSERT INTO Hidroponia.sensores(luzSensor,tempSensor,tempAmbi,date) values ('%d','%d','%d',now())", sensorLuz, sensorTemp, sensorAmbi) ;
  my_conn.cmd_query(sqlbuf);
  Serial.println("Salvo!!");
  delay(140000);
}
void loop() {
  delay(5000);
  if (my_conn.is_connected()) {
     delay(20000);
    lerSensores();
    delay(100000);
  } else {
    my_conn.disconnect();
    Serial.println("Connecting...");
    if (my_conn.mysql_connect(server_addr, 3306, user, password)) {
      delay(2500);
      Serial.println("Successful reconnect!");
      lerSensores();
    } else {
      Serial.println("Reconnect!");

    }
  }
}

