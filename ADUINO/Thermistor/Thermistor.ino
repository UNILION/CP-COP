#include <dht.h>
#include <SoftwareSerial.h>

#define DHT11_PIN 8

dht DHT;
SoftwareSerial mySerial(2,3);

void setup(){
  mySerial.begin(9600);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);

  if(chk==DHTLIB_OK){
    mySerial.write(DHT.temperature);
  }
  delay(2000);
}
