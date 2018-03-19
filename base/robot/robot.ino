#include<college.h>


const char *ssid = "Microcar";
const char *password = "fabmstic";

College c;

void setup() {
  Serial.begin(9600);
  c.initWeb(ssid,password);
  c.initPix(D4,2);
  c.initRoues(D1,D2);

}

void loop() {
  c.loopWeb();

  int sec = millis()%10000;
  if(sec==0)
  {
    c.setPix(0,200,0,0);
  }

}
