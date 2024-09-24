const int ledPins[] = {2, 3, 4, 5}; // 디지털 핀 번호 배열
const int initialBrightness[] = {0, 63, 127, 191}; // 초기 밝기 배열

void setup() {
  for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT); // 디지털 핀을 출력 모드로 설정
    analogWrite(ledPins[i], initialBrightness[i]); // 초기 밝기 설정
  }
}

void loop() {
  
  // LED 점멸 동작
  for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    digitalWrite(ledPins[i], HIGH); // LED 켜기
    delay(500); // 대기 시간 (500ms)
    digitalWrite(ledPins[i], LOW); // LED 끄기
    delay(500); // 대기 시간 (500ms)
  }

  
   int brightness = initialBrightness[0]; 
   int increment = 5; 

   while(true) { 
      analogWrite(ledPins[2],brightness);
      brightness += increment;
      if(brightness >=255 || brightness <=0) increment *= -1;
      delay (20);
   } 
  
}
