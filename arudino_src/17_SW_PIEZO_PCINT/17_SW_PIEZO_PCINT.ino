#include <TimerOne.h>
#include "PinChangeInterrupt.h"

// 전역변수
const int SW_0 = 4;
const int SW_1 = 5;
const int PIEZO = 9;
const int melody[] = {262,294,330,349,393,440,494,523};

int melody_state = LOW;

// 사용자 함수
// 스위치 입력 따른 상태값 변경
void SW_0_Pressed(void) {
  // 상태값 변경
  melody_state = (melody_state==LOW)? HIGH:LOW;
}

// 스위치 입력 따른 상태값 변경
void SW_1_Pressed(void) {
  Timer1.setPeriod(1000000/1);
  Timer1.setPwmDuty(PIEZO, 0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(PIEZO, OUTPUT);

  Timer1.initialize();    // 주기(1S)
  Timer1.pwm(PIEZO, 0);   // 듀티비

  // 외부인터럽트 설정
  attachPCINT(digitalPinToPCINT(SW_0), SW_0_Pressed, RISING);
  attachPCINT(digitalPinToPCINT(SW_1), SW_1_Pressed, RISING);
}

void loop() {
  // 상태값에 따른 동작 구현
  if(melody_state == HIGH){
    for(int i=0; i<8; i++){
      Timer1.setPeriod(1000000/melody[i]);
      Timer1.setPwmDuty(PIEZO, 512);
      delay(300);
    }
  }else{
    Timer1.setPeriod(1000000/1);
    Timer1.setPwmDuty(PIEZO, 0);
  }
}
