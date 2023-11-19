const int SW_0 = 2;
const int SW_1 = 3;
const int LED_0 = 9;
const int LED_1 = 10;

int led_0_flag = 0; //0:OFF, 1:ON
int led_1_flag = 0; //0:OFF, 1:ON
int pre_sw_0 = 0; // 스위치 이전값
int cur_sw_0 = 0; // 스위치 현재값
int pre_sw_1 = 0; // 스위치 이전값
int cur_sw_1 = 0; // 스위치 현재값

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);

  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);
}

void loop() {
  cur_sw_0 = digitalRead(SW_0);
  cur_sw_1 = digitalRead(SW_1);

  // 스위치 입력 따른 상태값 변경
  if( (pre_sw_0 == false) && (cur_sw_0 == true)){   // 상승엣지
    if(led_0_flag == 0){     
      led_0_flag = 1;
    }
    else{
      led_0_flag = 0;
    }
    delay(1);
  }

  // 상태값에 따른 동작 구현
  if (led_0_flag == 1){
    digitalWrite(LED_0, HIGH);
    delay(500);
    digitalWrite(LED_0, LOW);
    delay(500);
  }
  else{
    digitalWrite(LED_0, LOW);
  }

  if( (pre_sw_1 == false) && (cur_sw_1 == true)){   // 상승엣지
    if(led_1_flag == 0){
      led_1_flag = 1;
    }
    else{
      led_1_flag = 0;
    }
    delay(1);
  }

  // 상태값에 따른 동작 구현
  if (led_1_flag == 1){
    digitalWrite(LED_1, HIGH);
    delay(300);
    digitalWrite(LED_1, LOW);
    delay(300);
  }
  else{
    digitalWrite(LED_1, LOW);
  }

  pre_sw_0 = cur_sw_0;
  pre_sw_1 = cur_sw_1;
}
