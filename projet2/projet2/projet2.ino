#include "projet2.h"


//SSID et mot de passe wifi
const char *ssid = "PJ2Y";
const char *password = "fabmstic";
//Pin du capteur de lumière
const int capteurLumierePin = A0;
//nombre de vie
int life=2;

//Utilitaire pour la gestion des moteurs, des leds et de l'interface web 
Projet2 p;

//Booléen utilisé pour savoir si la voiture a le droit d'avancer
bool avance = false;

void setup() {
  Serial.begin(9600);
  p.initWeb(ssid,password);
  p.initPix(D4,2);
  p.initRoues(D1,D2);
  
  pinMode(D3,INPUT_PULLUP); 
  
  //Allume la led 1 et deux. La gestion de la couleur se fait dans l'objet p
  p.pixOn(0);
  p.pixOn(1);

}

void loop() {
  p.loopWeb();// gestion des évenements de l'interface Web
  
  int val=digitalRead(D3); //Lit la valeur du capteur d'aiment
  int lum=analogRead(capteurLumierePin);//Lit la valeur du capteur de lumière
  if(!life==0)
  {
    if(lum>p.getSeuilMax() && !avance && p.getMode()==2) //Si (on depasse le seuil max et on n'avance pas et on est en mode 2)
    {
      //On avance
      Serial.println(lum);
      avance=true;//on met a jour l'état de la variable
      p.avancer();//on lance les moteurs
      Serial.println("Avance");
    }  
    else if(lum<p.getSeuilMin() && avance && p.getMode()==2)
    {
      Serial.println(lum);
      avance=false;
      p.stop();
      Serial.println("Stop");
    }
	
    if(val==LOW)
    {
      Serial.println("HIGH"); 
      p.setPixs(250,0,0);
      delay(500);
      p.setPixs(0,0,0);
      life=life-1 ;
      delay(4500);
      Serial.print("life="); 
      Serial.println(life);
      if(life==1)
      {
        p.setPix(1,0,0,0);//on éteint la led 2
        p.pixOn(0);//on allume la led 1
      }
      if(life==0)
      {
        p.setPixs(0,0,0); //on éteint les leds
      }
    }
    delay(10);
  }
  else
  {
   delay(10000);
   life=2;
   p.setPixs(200,50,0);
  }
}
