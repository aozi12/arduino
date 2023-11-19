#define delay_time 10
const unsigned int led[4] = { 2, 3, 4, 5 };
const unsigned int bit[4] = {0x01, 0x02, 0x04,0x08};
unsigned int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1번째 배열 이용
  // for (int i = 0; i < 4; i++) {
  //   if (cnt & bit[i]) {
  //     digitalWrite(led[i], HIGH);
  //   } else {
  //     digitalWrite(led[i], LOW);
  //   }
  // }

  // 2번째 시프트 연산자이용
  for (int i = 0; i < 4; i++) {
    if (cnt & (0x01<<i)) {
      digitalWrite(led[i], HIGH);
    } else {
      digitalWrite(led[i], LOW);
    }
  }

  // 0부터 15까지 1초마다 카운트
  cnt++;
  if (cnt >= 16) {
    cnt = 0;
  }
  delay(500);
}
