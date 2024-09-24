//HW2-202155656
int num1, num2;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter 2 Integers to add");
}

void loop() {
  if (Serial.available()) { // 데이터가 도착했는지 확인
    while(Serial.available() == 0); // 첫 번째 정수가 입력될 때까지 대기
    num1 = Serial.parseInt(); // 첫 번째 정수 읽기

    while(Serial.available() == 0); // 두 번째 정수가 입력될 때까지 대기
    num2 = Serial.parseInt(); // 두 번째 정수 읽기

    int sum = num1 + num2; 
    Serial.print(num1);
    Serial.print(" + ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(sum); // 두 수의 합 출력
    Serial.println("Enter 2 Integers to add");
  }
}

