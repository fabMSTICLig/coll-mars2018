#include<college.h>
const int capteurLumierePin = A0; 


void clignote(int intensite)
{
  int tempspattern=millis()%3000;
  if(tempspattern < 1000)
  {
    setPixs(intensite,0,0);
  }
  else if(tempspattern < 2000)
  {
     setPixs(0,intensite,0);
  }
  else
  {
     setPixs(0,0,intensite);
  }
}

void setup() {
  Serial.begin(9600);
  initPix(D4,2);
  setPixs(0,0,0);
  pinMode(D3,INPUT_PULLUP);
}

void loop() {
  int valeurLum = analogRead(capteurLumierePin);
  Serial.print("");
  Serial.println(valeurLum);
  int valeurAimant=digitalRead(D3);

  if(valeurAimant==LOW)
  {
    clignote(map(valeurLum,0,1023,0,250));
  }
  else
  {
    setPixs(0,0,0);
  }

  delay(2);
}
