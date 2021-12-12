int Soil_Pin = A0;
int Led_Pin = 2;
int Soil_val;
 
void setup() {
  pinMode(Led_Pin,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  Soil_val = analogRead(Soil_Pin); // 토양습도센서 값 측정
  Serial.println(Soil_val); // 측정된 센서값을 시리얼모니터로 전송
 
  // 토양의 수분이 부족할 시 LED ON
  // 수분에 대한 기준점은 임의로 조정
  if(Soil_val > 800) {
    digitalWrite(Led_Pin,1);
  } else {
    digitalWrite(Led_Pin,0);    
  }
}
