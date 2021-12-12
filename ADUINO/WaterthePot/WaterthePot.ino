# include <dht.h>
#include <SoftwareSerial.h>

#define DHT11_PIN 8
#define BIA 7
#define BIB 9

int Soil_Pin = A0;
int Soil_val;
int waterpump = 200;
String thisString;

dht DHT;
SoftwareSerial mySerial(2,3);

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}
void loop()
{
  Soil_val = analogRead(Soil_Pin); // 토양습도센서 값 측정
  Serial.println(Soil_val);

  int chk = DHT.read11(DHT11_PIN);
    mySerial.write(DHT.temperature);
  delay(2000);
  
 if(mySerial.available()){
    thisString=mySerial.readString();

    if(thisString=="water")
    {
      analogWrite(BIA, 0);
      analogWrite(BIB, waterpump);
      delay(5000);
      analogWrite(BIB, 0);
    }
  }
  
  if(Soil_val > 480)// 토양의 수분이 부족할 시
  {
     analogWrite(BIA, 0);
     analogWrite(BIB, waterpump);
     delay(5000);
     analogWrite(BIB, 0);
     delay(5000);
  }
  

  
}
