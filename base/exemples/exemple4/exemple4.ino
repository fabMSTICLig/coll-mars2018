#include<college.h>
const int capteurLumierePin = A0; 

void setup() {
  Serial.begin(9600);
  initPix(D4,2);
}

void loop() {
  int valeur = analogRead(capteurLumierePin);
  Serial.print("");
  Serial.println(valeur);

  if(valeur<300)
  {
    setPixs(250,0,0);
    
    Serial.println("Etat1");
  }else if(valeur>300 && valeur<600)
  {
    setPixs(0,250,0);
    Serial.println("Etat2");
  }
  else
  {
    setPixs(0,0,250);
    Serial.println("Etat3");
  }
  delay(2);
}
