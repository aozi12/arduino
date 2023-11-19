#include <DHT11.h>

                                //a,b,c,d,e,f,g
const unsigned int fnd_pin[7] = {2,3,4,5,6,7,8};

const unsigned int num_0[7] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW};
const unsigned int num_1[7] = {LOW,HIGH,HIGH,LOW,LOW,LOW,LOW};
const unsigned int num_2[7] = {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH};
const unsigned int num_3[7] = {HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH};
const unsigned int num_4[7] = {LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH};
const unsigned int num_5[7] = {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH};
const unsigned int num_6[7] = {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH};
const unsigned int num_7[7] = {HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW};
const unsigned int num_8[7] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};
const unsigned int num_9[7] = {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH};

const unsigned int fnd_num[10] = {num_0,num_1,num_2,num_3,num_4,
                                  num_5,num_6,num_7,num_8,num_9};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<7; i++) { 
    pinMode(fnd_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_0[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_1[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_2[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_3[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_4[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_5[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_6[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_7[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_8[i]);
  }
  delay(1000);

  for(int i=0; i<7; i++){
    digitalWrite(fnd_pin[i], num_9[i]);
  }
  delay(1000);
}
