#include <stdio.h>

const float unit = 5.0/1024.0;
const int ledPin = 10;
const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  int analogValue = analogRead(analogPin);
  int val = map(analogValue, 280, 580, 0, 255);
  analogWrite(ledPin, val);

  Serial.print(analogValue);
  Serial.print(", ");
  Serial.print(unit*analogValue, 5);
  Serial.println(" V");
}
