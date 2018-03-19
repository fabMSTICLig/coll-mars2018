#include<college.h>


const int pinInter = D3;

void setup() {
  Serial.begin(9600);
  initPix(D4,2);
  pinMode(pinInter,INPUT_PULLUP);
}

void loop() {
  int val=digitalRead(pinInter);
  if(val==LOW)
  {
    setPix(0,200,0,0);
  }
  else
  {
    setPix(0,0,0,0);
  }
  delay(1);
}
