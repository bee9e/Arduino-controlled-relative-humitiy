#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int rele = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("KlimaKontroller");
  dht.begin();
  pinMode(8, OUTPUT);
  
}

void loop() {
  delay(200);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
if (h <=40.00){
  digitalWrite(rele, HIGH);
}  else if (h>=70.00)
  {digitalWrite(rele, LOW);
  return;
}
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");




}
