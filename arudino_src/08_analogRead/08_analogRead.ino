#include <stdio.h>

const float unit = 5.0/1024.0;
const int ledPin = 10;
const int analogPin = A0;
char buf[100] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  int val = 0;
  int analogValue = analogRead(analogPin);
  val = map(analogValue, 0, 1023, 0, 255);
  analogWrite(ledPin, val);

  // sprintf(buf, "%d, %.2f V\n", analogValue, unit*analogValue);
  // Serial.print(buf);
  Serial.print(analogValue);
  Serial.print(", ");
  Serial.print(unit*analogValue, 5);
  Serial.println(" V");
}
