const int R_LED = 11;
const int G_LED = 10;
const int B_LED = 9;

const int RGB_LED[3] = {R_LED, G_LED, B_LED};

// 사용자 함수 
void setColor(int col){
  for (int i = 0; i < 3; i++) {
    if (col & (0x01<<i)) {
      digitalWrite(RGB_LED[i], HIGH);
    } else {
      digitalWrite(RGB_LED[i], LOW);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<3; i++){
    pinMode(RGB_LED, OUTPUT);
  }
}

void loop() {
  // 함수 호출
  for(int i=0; i<8; i++){
    setColor(i);
    delay(500);
  }
}
