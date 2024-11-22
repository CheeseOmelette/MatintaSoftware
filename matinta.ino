#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h> // Biblioteca para o BMP180 (também conhecido como BMP085)

// Criar um objeto BMP180
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

void setup() {
  Serial.begin(9600);

  // Iniciar comunicação com o sensor BMP180
  if (!bmp.begin()) {
    Serial.print("Não foi possível encontrar o sensor BMP180");
    while (1);
  }
}

void loop() {
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure) {
    // Mostrar a pressão atmosférica
    Serial.print("Pressão: ");
    Serial.print(event.pressure);
    Serial.println(" hPa");

    // Calcular a altitude aproximada com base no nível do mar padrão (1013.25 hPa)
    float altitude = bmp.pressureToAltitude(1013.25, event.pressure);
    Serial.print("Altitude aproximada: ");
    Serial.print(altitude);
    Serial.println(" metros");
  } else {
    Serial.println("Erro ao ler a pressão");
  }

  delay(2000);  // Aguardar 2 segundos antes de fazer outra leitura
}
