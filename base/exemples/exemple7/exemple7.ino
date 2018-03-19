#include<college.h>
const int capteurLumierePin = A0; 


void clignote(int id)
{
  int tempspattern=millis()%2000;
  if(tempspattern < 1000)
  {
    setPix(id,250,0,0);
  }
  else
  {
     setPix(id,0,0,0);
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

  if(valeurLum<400)
  {
    clignote(0);
  }
  if(valeurAimant==LOW)
  {
    clignote(1);
  }

  delay(2);
}
