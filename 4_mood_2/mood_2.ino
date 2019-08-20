int RED_PIN = 6, GREEN_PIN = 3, BLUE_PIN = 5; //RGB LED 모듈 RED, GREEN, BLUE 핀 번호 설정
int POTEN_PIN = A5, TOUCH_PIN = 2; //가변저항, 터치센서 핀 번호 설정
bool cur_state = false;
int rainbow[6][3] = {
  {255, 0, 0}, //빨
  {255, 50, 0}, //주
  {255, 150, 0}, //노
  {0, 255, 0}, //초
  {0, 0, 255}, //파
  {100, 0, 200}, //보
};

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

void loop() {
  if (digitalRead(TOUCH_PIN) == HIGH) { // 터치 센서 터치시 On /Off
    Serial.println("Touch!");
    cur_state = !cur_state;
    delay(500);
  }
  if (cur_state) { // 켜진 상태일 경우
    int cur_value = map(analogRead(A5), 0, 1023, 0, 5);
    Serial.println(cur_value);
    analogWrite(RED_PIN, 255-rainbow[cur_value][0]);
    analogWrite(GREEN_PIN, 255-rainbow[cur_value][1]);
    analogWrite(BLUE_PIN, 255-rainbow[cur_value][2]);
  } else { //꺼진 상태일 경우
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);        
  }
}
