#include "PinChangeInterrupt.h"

//  a  b  c  d  e  f  g
const unsigned int fnd_pin[7] = { 2, 3, 4, 5, 6, 7, 8 };
const unsigned int SW_0 = 10, SW_1 = 11;

const unsigned int num_0[7] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW };
const unsigned int num_1[7] = { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW };
const unsigned int num_2[7] = { HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH };
const unsigned int num_3[7] = { HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH };
const unsigned int num_4[7] = { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH };
const unsigned int num_5[7] = { HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH };
const unsigned int num_6[7] = { HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH };
const unsigned int num_7[7] = { HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW };
const unsigned int num_8[7] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH };
const unsigned int num_9[7] = { HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH };

const unsigned int *fnd_num[10] = { num_0, num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9 };
int cnt = 0;


//사용자 함수
void display_init(void) {       //초기화
  for (int i = 0; i < 7; ++i) {
    pinMode(fnd_pin[i], OUTPUT);
  }
}

void display_clear(void) {        //all 0
  for (int i = 0; i < 7; ++i) {
    pinMode(fnd_pin[i], LOW);
  }
}

void display_number(int n){
    for (int num = 0; num <= 10; ++num) {
    for (int i = 0; i < 7; ++i) {
      digitalWrite(fnd_pin[i], fnd_num[n][i]);
    }
    delay(1000);
}
}

void SW_0_Pressed(void){
  cnt++;
  if (cnt > 9) cnt = 0;
display_number(cnt);

}

void SW_1_Pressed(void){
cnt = 0;
display_number(cnt);
}

void setup() {
  //led 초기화
  display_init();
  display_number(cnt);

  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
 
  
  attachPCINT(digitalPinToPCINT(SW_0), SW_0_Pressed, RISING);
  attachPCINT(digitalPinToPCINT(SW_1), SW_1_Pressed, RISING);
}

void loop() {

}
