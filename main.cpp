#include <Arduino.h>

const int irReceiverPin = 2;
volatile unsigned long irCode = 0;
volatile bool irReceived = false;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(irReceiverPin), onIRReceived, CHANGE);
}

void loop() {
  if (irReceived) {
    Serial.println(irCode, HEX);
    irReceived = false;
  }
}

void onIRReceived() {
  static unsigned long startTime = 0;
  static unsigned int bitCount = 0;
  static unsigned long receivedCode = 0;

  unsigned long elapsedTime = micros() - startTime;

  startTime = micros();
  bitCount++;

  if (bitCount == 32) {
    receivedCode = elapsedTime;
  } else if (bitCount > 32) {
    if (elapsedTime > 2000) {
      irCode = receivedCode;
      irReceived = true;
      bitCount = 0;
      receivedCode = 0;
    } else {
      receivedCode = (receivedCode << 1) | (elapsedTime > 1000);
    }
  }
}