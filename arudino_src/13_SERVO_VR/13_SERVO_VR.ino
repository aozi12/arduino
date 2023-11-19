#include <Servo.h>

const int pinSERVO = 10;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo.attach(pinSERVO);
  servo.write(0);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int aVal = analogRead(A0);   // 0~1023
  servo.write(map(aVal,0,1023,0,180));
}
