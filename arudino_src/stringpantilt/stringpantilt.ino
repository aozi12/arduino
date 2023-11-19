String inputStirng = "";
void setup() {
Serial.begin(9600);

}

void loop() {
  if(Serial.available()> 0){
    char ch = Serial.read();
    if( ch != '\n'){
      inputStirng += ch;
    }

  }
 else{
   if(inputStirng.substring(0,3) == "pan")
   Serial.println(inputStirng.substring(4));
   else;
 }
}
