                                //a,b,c,d,e,f,g
const unsigned int fnd_pin[7] = { 2, 3, 4, 5, 6, 7, 8 };
                              // com1, com2, com3, com4
const unsigned int com_pin[4] = {9,     10,   11,  12};

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

const unsigned int *fnd_num[10] = { num_0, num_1, num_2, num_3, num_4,
                                    num_5, num_6, num_7, num_8, num_9 };

unsigned long t1_prev= 0;
const unsigned long t1_delay = 1000;
unsigned long t2_prev= 0;
const unsigned long t2_delay = 10;

// 사용자 함수
void display_init(void) {
  for (int i = 0; i < 7; i++) {
    pinMode(fnd_pin[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(com_pin[i], OUTPUT);
  }
}

void display_clear(void){
  for (int i = 0; i < 7; i++) {
    digitalWrite(fnd_pin[i], LOW);
  }
}

void display_number(int n){
  for (int i = 0; i < 7; i++) {
    digitalWrite(fnd_pin[i], fnd_num[n][i]);
  }
}

void display_numbers(unsigned int num){
  unsigned int num_array[4] = {0,};
  num_array[0] = num/1000;
  num_array[1] = (num%1000)/100;
  num_array[2] = (num%100)/10;
  num_array[3] = num%10;
  
  for(int j=0; j<4; j++){
    for(int i=0; i<4; i++){
      digitalWrite(com_pin[i], HIGH);
    }
    digitalWrite(com_pin[j], LOW);
    display_number(num_array[j]);
    delay(1);
    display_clear();
    delay(1);
  }
}

void setup() {
  // put your setup code here, to run once:
  display_init();
}

unsigned int cnt=0;
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t1_now = millis();
  if((t1_now-t1_prev) >= t1_delay){
    t1_prev = t1_now;
    cnt++;
  }

  unsigned long t2_now = millis();
  if((t2_now-t2_prev) >= t2_delay){
    t2_prev = t2_now;
    display_numbers(cnt);
  }
}









