include<college.h>


void setup() {
  Serial.begin(9600);
  initPix(D4,2);
  pinMode(D3,INPUT_PULLUP);
}

void loop() {
  int val=digitalRead(D3);
  if(val==HIGH)
  {
    setPix(0,200,0,0);
  }
  else
  {
    setPix(0,0,0,0);
  }
  delay(1);
}
