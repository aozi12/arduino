const int LED =13;

// 사용자 함수 
void func(int high, int low)
{
  digitalWrite(LED, HIGH);
  delay(high);
  digitalWrite(LED, LOW);
  delay(low);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 함수호출
  for(int i=0; i<9; i++){
    func(1+i,9-i);
    // Serial.print(1+i);
    // Serial.print(", ");
    // Serial.println(9-i);
  }
  // delay(2000);
}
