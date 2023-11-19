// 전역변수
const int SW_0 = 2;
const int SW_1 = 3;
const int LED_0 = 9;
const int LED_1 = 10;

int led_0_flag = 0;  //0:OFF, 1:ON
int led_1_flag = 0;  //0:OFF, 1:ON

// 사용자 함수
// 스위치 입력 따른 상태값 변경
void SW_0_Pressed(void) {
  if (led_0_flag == 0) {
    led_0_flag = 1;
  } else {
    led_0_flag = 0;
  }
  delay(1);
}

// 스위치 입력 따른 상태값 변경
void SW_1_Pressed(void) {
  if (led_1_flag == 0) {
    led_1_flag = 1;
  } else {
    led_1_flag = 0;
  }
  delay(1);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);

  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);

  // 외부인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(SW_0), SW_0_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW_1), SW_1_Pressed, RISING);
}

void loop() {
  // 상태값에 따른 동작 구현
  if (led_0_flag == 1) {
    digitalWrite(LED_0, HIGH);
    delay(500);
    digitalWrite(LED_0, LOW);
    delay(500);
  } else {
    digitalWrite(LED_0, LOW);
  }

  // 상태값에 따른 동작 구현
  if (led_1_flag == 1) {
    digitalWrite(LED_1, HIGH);
    delay(300);
    digitalWrite(LED_1, LOW);
    delay(300);
  } else {
    digitalWrite(LED_1, LOW);
  }
}
