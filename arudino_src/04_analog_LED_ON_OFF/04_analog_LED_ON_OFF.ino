const int LED_0 = 3;
const int LED_1 = 5;
const int LED_2 = 6;
const int LED_3 = 9;

const int Array_LED[4] = {LED_0, LED_1, LED_2, LED_3};

// 사용자 함수
void func(int led){
  for(int i=0; i<256; i++){
    analogWrite(led, i);
    delay(4);
  }
  analogWrite(led, 0);
}

void setup() {
  // put your setup code here, to run once:
  analogWrite(LED_0, 0);   // Timer/counter 이용
  // analogWrite(LED_1, 25*5);
}

void loop() {
  // put your main code here, to run repeatedly:
  // // cpu를 이용
  // digitalWrite(LED_1, HIGH);
  // delay(5);
  // digitalWrite(LED_1, LOW);
  // delay(5);

  // 함수 호출
  for(int i=0; i<(sizeof(Array_LED)/sizeof(int)); i++){
    func(Array_LED[i]);
  }
}
