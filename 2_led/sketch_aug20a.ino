int RED_PIN = 3;
int BLUE_PIN = 6;
int GREEN_PIN = 9;
int POTEN_PIN = A5;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  RGB_set(0, 255, 255);
}

void RGB_set (int R, int G, int B) {
  int poten = analogRead(POTEN_PIN);
  analogWrite(RED_PIN, 255 - map(poten, 0, 1023, 0, R));
  analogWrite(GREEN_PIN, 255 - map(poten, 0, 1023, 0, G));
  analogWrite(BLUE_PIN, 255 - map(poten, 0, 1023, 0, B));
}
