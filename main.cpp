#include <Arduino.h>
/*
#include <IRremote.h>


int sensorPin = 2;
IRrecv irReceiver(sensorPin);

void setup() {
  Serial.begin(9600);
  irReceiver.enableIRIn();
  pinMode(sensorPin,INPUT);
}

void loop() {
  if (irReceiver.decode()) {
    unsigned long irCode = irReceiver.decodedIRData.decodedRawData;
    Serial.println(irCode, HEX);
    irReceiver.resume();
  }
}
*/

// Constantes para la configuración del sensor IR
const int sensorPin = 2;

// Variables para almacenar los datos del sensor IR
unsigned int irData = 0;
unsigned int prevIrData = 0;

// Variables para el control del tiempo
unsigned long prevTime = 0;
const unsigned long debounceDelay = 100;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Lee el valor del sensor IR
  int irValue = digitalRead(sensorPin);

  // Comprueba si hay un cambio en el estado del sensor
  if (irValue != prevIrData) {
    // Espera un tiempo de rebote para evitar falsos positivos
    if (millis() - prevTime >= debounceDelay) {
      // Actualiza el tiempo previo
      prevTime = millis();

      // Actualiza el estado previo del sensor
      prevIrData = irValue;

      // Comprueba el valor del sensor IR
      if (irValue == HIGH) {
        // Se ha detectado una señal IR (botón presionado)
        // FALTA AGREGAR UNA FORMA DE QUE DETECTE LOS BOTONES PRESIONADOS

        unsigned int irCode = getIrCode();

        // Imprime el código hexadecimal en el Monitor Serie
        Serial.print("Código hexadecimal: 0x");
        Serial.println(irCode, HEX);
      }
    }
  }
}

// Función para obtener el código del botón
unsigned int getIrCode() {
  // FALTA AGREGAR UNA FORMA DE QUE DETECTE LOS BOTONES PRESIONADOS

  // DEBE DEVOLVER EL VALOR DEL BOTÓN
  //return ;
}