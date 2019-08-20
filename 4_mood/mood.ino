int RED_PIN = 6, GREEN_PIN = 3, BLUE_PIN = 5; //RGB LED 모듈 RED, GREEN, BLUE 핀 번호 설정
int POTEN_PIN = A5, TOUCH_PIN = 2; //가변저항, 터치센서 핀 번호 설정
int r, g, b, Mode, touch_count, rainbow_count, rain;
boolean touch = true, up = true;
int rainbow[6][3] = {
  {255, 0, 0}, //빨
  {255, 50, 0}, //주
  {255, 150, 0}, //노
  {0, 255, 0}, //초
  {0, 0, 255}, //파
  {100, 0, 200}, //보
}; //모드 6: 무지개 색 배열 선언

 void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
 }

void loop() {
  Mode_set();

  if ( Mode != 6) {
    int poten = analogRead(POTEN_PIN);
    analogWrite(RED_PIN, 255 - map(poten, 0, 1023, 0, r));
    analogWrite(GREEN_PIN, 255 - map(poten, 0, 1023, 0, g));
    analogWrite(BLUE_PIN, 255 - map(poten, 0, 1023, 0, b));
  }

  if ( digitalRead(TOUCH_PIN) == 1 ) {
    touch_count++;
    delay(10);

    if (touch_count >= 100) {
      Serial.println("Touch!"); // For debug purpose : detects long touch
      if (r ==0 && g ==0 && b ==0) {
        r = 255;
      } // 전원 ON (1초 동안 터치)
    else {
      r = 0;
      g = 0;
      b = 0;
      Mode = 0;
    } // 전원 OFF (1초 동안 터치)
    touch_count = 0; // 전원 ON/OFF 후 터치 카운트 초기화
    }

    else if ( touch && ( r !=0 || g !=0 || b !=0 )) {
      Mode++;
      if (Mode>6) {
        Mode = 1;
      } // 모드 6 다음에 모드 1로 돌아갈 수 있도록 Mode 변수값 1로 초기화
      touch = false; // 모드 변경 한 번만 할 수 있도록 boolean 값 false로 설정
    } // 모드 변경 (불이 켜져 있을 때)
}

else {
  touch = true;
  touch_count = 0;

  } // 터치 입력 없을 시 변수 초기화
}

void Mode_set() {
  if ( Mode == 1) {
    r = 210;
    g = 100;
    b = 10;
  } // 모드 1: 전구색

  else if ( Mode == 2) {
    r = 255;
    g = 0;
    b = 0;
  } // 모드2: 빨간색

   else if (Mode == 3) {
    r = 0;
    g = 255;
    b = 0;   
   } // 모드 3: 초록색

   else if (Mode == 4) {
    r = 0;
    g = 0;
    b = 255;
   } // 모드 4: 파란색
   else if ( Mode == 5 ) {
    r = random(255);
    g = random(255);
    b = random(255);
    delay(200);
   } // 모드 5: 무작위 색 변화 (0.2초 마다)

   else if (Mode == 6 ) {
    analogWrite(RED_PIN, 255- map(rainbow_count, 0, 1023, 0, rainbow[rain][0]));
    analogWrite(GREEN_PIN, 255- map(rainbow_count, 0, 1023, 0, rainbow[rain][1]));
    analogWrite(BLUE_PIN, 255- map(rainbow_count, 0, 1023, 0, rainbow[rain][2]));        

    if (up) {
      rainbow_count++;
      delayMicroseconds(500);
      if(rainbow_count==1023)
      up = false;
    }

    else if (!up) {
      rainbow_count--;
      delayMicroseconds(2000);
      if ( rainbow_count == 0 ) {
        up = true;
        rain++;
        if (rain == 6)
        rain = 0;
      }
    }
   }
}
