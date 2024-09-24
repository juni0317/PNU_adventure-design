String words[5];

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 5; i++) {
    Serial.print("Enter the ");
    Serial.print(i + 1);
    Serial.println("th word:");
    
    while (Serial.available() == 0) {
      ;
    }
    
    words[i] = Serial.readStringUntil('\n');
    delay(100);
  }
  
  sort(words, words + 5);
  
  for (int i = 0; i < 5; i++) {
    Serial.println(words[i]);
  }
}

void loop() {
}
