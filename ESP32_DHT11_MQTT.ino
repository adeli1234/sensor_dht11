#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Espera 2 segundos entre lecturas

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    return;
  }

  // Enviar trama JSON por puerto serie
  Serial.print("{\"equipo\":\"equipo01\",\"temperatura\":");
  Serial.print(t, 1);
  Serial.print(",\"humedad\":");
  Serial.print(h, 1);
  Serial.println("}");
}