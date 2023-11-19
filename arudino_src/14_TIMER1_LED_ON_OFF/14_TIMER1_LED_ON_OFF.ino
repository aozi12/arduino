#include <TimerOne.h>

#define duty_1 1024/100
const int LED = 9;
const int SERVO = 10;

int degree = 0;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(20000);
  Timer1.pwm(SERVO, 0); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<180; i++){
    degree = map(i,0,180,35,117);
    Timer1.setPwmDuty(SERVO,degree);
    delay(20);
  }
  for(int i=180; i>0; i--){
    degree = map(i,0,180,35,117);
    Timer1.setPwmDuty(SERVO,degree);
    delay(20);
  }

}
