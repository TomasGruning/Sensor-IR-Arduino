#include <Arduino.h>
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
