#define ONE_WIRE_BUS 3
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "SPI.h"
#include "Ethernet.h"
#include "sha1.h"
#include "mysql.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;
DHT dht(4, DHT22);
IPAddress server_addr(130, 211, 75, 60);

int sensorAmbi;
int sensorLuz;
int sensorTemp;
char sqlbuf[128];
char user[] = "root";
char password[] = "root";
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

Connector my_conn;

void setup() {
  Ethernet.begin(mac_addr);
  Serial.begin(115200);
  Serial.println("Connecting...");
  dht.begin();
  //sensor de agua
  sensors.begin();
  Serial.print(sensors.getDeviceCount(), DEC);
  sensors.getAddress(sensor1, 0) ? Serial.println("Sensor De Agua Ativado") : Serial.println("Sensor de Agua Desativado");
  my_conn.mysql_connect(server_addr, 3306, user, password) ;
}

void lerSensores() {
  delay(10000);
  sensorAmbi = (int)dht.readTemperature();
  delay(10000);
  sensors.requestTemperatures();
  sensorTemp = (int)sensors.getTempC(sensor1);
  delay(10000);
  sensorLuz = luz();
  delay(10000);
  UpdateMsql();
}


int luz() {
  int luz = analogRead(0);
  luz = map(luz, 0, 1024, 0, 100);
  return (luz - 100) * -1;
}
void UpdateMsql() {
  delay(10000);
  sprintf(sqlbuf, "INSERT INTO Hidroponia.sensores(luzSensor,tempSensor,tempAmbi,date) values ('%d','%d','%d',now())", sensorLuz, sensorTemp, sensorAmbi) ;
  my_conn.cmd_query(sqlbuf);
  Serial.println("Salvo!!");
  delay(10000);
}

void reconect() {
  while (true) {
    my_conn.disconnect();
    delay(120000);
    if (my_conn.mysql_connect(server_addr, 3306, user, password)) {
      Serial.println("Successful reconnect!");
      return; 
    } else {
      Serial.println("Reconnect!");
    }
  }
}
void loop() {
  delay(240000);
  if (my_conn.is_connected()) {
    lerSensores();
  } else {
    reconect();
    lerSensores();
  }
}
 
