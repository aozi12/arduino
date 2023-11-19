unsigned long t0_prev = 0;
const unsigned long t0_delay = 300;

unsigned long t1_prev = 0;
const unsigned long t1_delay = 500;

const unsigned int LED_0 = A0;
const unsigned int LED_1 = A1;
unsigned int led0_flag = LOW;
unsigned int led1_flag = LOW;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t0_now = millis();
  if (t0_now - t0_prev >= t0_delay) {
    t0_prev = t0_now;
    led0_flag = (led0_flag == LOW) ? HIGH : LOW;
    digitalWrite(LED_0, led0_flag);
  }

  unsigned long t1_now = millis();
  if (t1_now - t1_prev >= t1_delay) {
    t1_prev = t1_now;
    led1_flag = (led1_flag == LOW) ? HIGH : LOW;
    digitalWrite(LED_1, led1_flag);
  }
}
