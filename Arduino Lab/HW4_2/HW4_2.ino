int pins_button = 14;
int pins_LED[] = {5, 4, 3, 2};

void setup() {
  Serial.begin(9600);
  pinMode(pins_button, INPUT);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i], OUTPUT);
    digitalWrite(pins_LED[i], false);
  }
}

void loop() {
  while(1) {
    for(int i=0; i<4; i++){
      digitalWrite(pins_LED[i], true);
      delay(500);
      digitalWrite(pins_LED[i], false);
      delay(500);
    }
    if(digitalRead(pins_button) == 1)
      break;
  }
  while(1){
    for(int i=3; i>=0; i--){
      digitalWrite(pins_LED[i], true);
      delay(500);
      digitalWrite(pins_LED[i], false);
      delay(500);
    }
    if(digitalRead(pins_button) == 1)
      break;
  }
}
