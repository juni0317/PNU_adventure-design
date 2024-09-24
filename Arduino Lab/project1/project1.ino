#include "DHT.h"
#include <LiquidCrystal.h> 
#define water 53

LiquidCrystal lcd(13,12,5,4,3,2);   //RS 핀, E핀, 데이터 핀 4개
String lcdString = "";
DHT dht(8, DHT22); /*8번 PIN에서 데이터가 들어오고, 
                     센서는 DHT22 센서를 사용한다고 정의합니다.
                     */

void setup() {
  Serial.begin(9600); //PC모니터를 이용하기 위하여, 
  lcd.begin(16,2);           //LCD 크기 지정, 2줄 16칸
  lcd.clear();               //화면 지우기  
  dht.begin(); //DHT22센서의 사용시작을 정의해줍니다.
  pinMode(water, OUTPUT);
}
 
void loop() {

  delay(2000);   //측정하는 시간사이에 2초간의 딜레이를 줘야 합니다.
 
  float h = dht.readHumidity();  //습도값을 읽어옴. 
  float t = dht.readTemperature(); //온도값을 읽어옴
  float hic = dht.computeHeatIndex(t, h, false); /*DHT22는 열지수(체감온도)
                                                   를 나타내줄수있는 함수가 포함되어있습니다.
                                                  */
  onOff(h);           //가습기 on/off 함수 호출
  lcdHumidity(h, t);     //현재 습도 lcd 출력 함수 호출
}

void onOff(float h) {

 if (h < 50 ) { //습도가 50%보다 작으면 
   digitalWrite(water, HIGH); //가습기 ON
 }else { 
   digitalWrite(water,LOW); 
 }
} 

void lcdHumidity(float hu, float t) { 
 lcd.setCursor(0,0); //커서 0,0에 배치 
 lcd.print("humid & temper"); //""안에 글자 출력 
 lcd.setCursor(1,3); //커서 위치 1,3으로 변경 후 
 char buffer[10];
 char buffer2[10]; //float를 string으로 변환하기 위한 임시 char 배열 선언 
 dtostrf(hu, 4, 1, buffer); //float -> char로 변환 
 dtostrf(t, 4, 1, buffer2);
 String humidity = " : "; //두번째 줄에 출력할 구문 만들기 ( : 습도 %) 
 humidity += (String)buffer; //char -> string 
 humidity += "%"; 
 String temperature = " "; //두번째 줄에 출력할 구문 만들기 ( : 습도 %) 
 temperature  += (String)buffer2; //char -> string 
 temperature += "C"; 
 Serial.print(humidity);
 Serial.print(temperature);
 lcd.print(humidity); //현재 습도 출력
 lcd.print(temperature);
}
