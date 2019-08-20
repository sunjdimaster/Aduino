void setup () {
  Serial.begin(9600);
}

void loop(){
  int val = analogRead(A5);
  Serial.println(val);
}
