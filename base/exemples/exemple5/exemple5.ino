#include<college.h>
const int capteurLumierePin = A0; 

void setup() {
  Serial.begin(9600);
  initPix(D4,2);
  pinMode(D3,INPUT_PULLUP);
}

void loop() {
  int valeurLum = analogRead(capteurLumierePin);
  Serial.print("");
  Serial.println(valeurLum);
  int valeurAimant=digitalRead(D3);

  if(valeurLum<400)
  {
    setPix(0,250,0,0);
    delay(1000);
    setPix(0,0,0,0);
    delay(1000);
    setPix(0,250,0,0);
    delay(1000);
    setPix(0,0,0,0);
    delay(1000);
  }
  if(valeurAimant==LOW)
  {
    setPix(1,250,0,0);
    delay(1000);
    setPix(1,0,0,0);
    delay(1000);
    setPix(1,250,0,0);
    delay(1000);
    setPix(1,0,0,0);
    delay(1000);
  }

  delay(2);
}
