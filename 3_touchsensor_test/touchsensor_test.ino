int TOUCH_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH_PIN, INPUT);
}

void loop() {
  if(digitalRead(TOUCH_PIN)==HIGH) {
    Serial.println("Touch!");
  }
  delay(100);
}
