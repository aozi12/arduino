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
  while (Serial.available() == 0) {}     //wait for data available
  String angle = Serial.readString();  //read until timeout
  angle.trim();                      // remove any \r \n whitespace at the end of the String
  
  servo.write(angle.toInt());
}
