#include <SoftwareSerial.h>

#define BIA 9
#define BIB 10

int waterpump = 200;  
String thisString;

SoftwareSerial mySerial(2,3);

void setup() {
  mySerial.begin(9600);
}

void loop() {
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
}
