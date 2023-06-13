#include <Arduino.h>
#include <IRremote.h>


int sensorPin = 2;
IRrecv irReceiver(sensorPin);
decode_results irResults;

void setup() {
  Serial.begin(9600);
  irReceiver.enableIRIn();
  pinMode(sensorPin,INPUT);
}

void loop() {
  if (irReceiver.decode(&irResults)) {
    unsigned long irCode = irResults.value;
    Serial.println(irCode);
    irReceiver.resume();
  }
}