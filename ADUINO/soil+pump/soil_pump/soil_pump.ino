# include <dht.h>
#include <SoftwareSerial.h>

#define BIA 9
#define BIB 10
int Soil_Pin = A0;
int Soil_val;
int waterpump = 200;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Soil_val = analogRead(Soil_Pin); // 토양습도센서 값 측정
  Serial.println(Soil_val);
  if(Soil_val > 480)// 토양의 수분이 부족할 시
  {
     analogWrite(BIA, 0);
     analogWrite(BIB, waterpump);
     delay(2000);
     analogWrite(BIB, 0);
     delay(2000);
  }
}
