#include<college.h>
const int capteurLumierePin = A0; //Pin du capteur de lumière

//SSID et mot de passe wifi
const char *ssid = "projetsvV";
const char *password = "fabmstic";

College c;//Utilitaire pour la gestion des moteurs, des leds et de l'interface web 

//Booléens utilisés pour n'envoyer les commandes des leds que lorsque c'est nécéssaire.
bool lumOn=false;
bool aimentOn=false;
bool clingnoteOn=false;

//Fonction permettant de faire clignoté une led
void clignote()
{
  int tempspattern=millis()%1000;
  if(tempspattern < 500 && !clingnoteOn) //Si le temps est inférieur a 500 milisecondes et que la led est éteinte (!clingnoteOn) on l'allume
  {
    clingnoteOn=true;
    c.setPix(1,250,0,0);
  }
  if(tempspattern > 500 && clingnoteOn)
  {
    clingnoteOn=false;
     c.setPix(1,0,0,0);
  }
}

void setup() {
  Serial.begin(9600);
  c.initWeb(ssid,password);//Initialise l'interface web et le wifi
  c.initPix(D4,2); // Initialise les leds (Pin D4, nombre de leds 2)
  c.initRoues(D1,D2); //Initialise les moteurs connectés au pin D1 et D2
  //Initialise la pin de l'intérupteur 
  pinMode(capteurAimantPin,INPUT_PULLUP);
  
  //éteint les leds
  c.setPixs(0,0,0);
}

void loop() {
  
  c.loopWeb(); // gestion des évenements de l'interface Web
  
  int valeurLum = analogRead(capteurLumierePin);//Récupère la valeur du capteur de luminosité
  
  Serial.print("");
  Serial.println(valeurLum);
  
  
  int valeurAimant=digitalRead(D3);

  //Allume et éteint la led selon le taux de luminosité et de son propre état (lumOn)
  if(valeurLum<500 && !lumOn)
  {
    lumOn=true;
    c.setPix(0,250,0,225);
  }
  if(valeurLum>500 && lumOn)
  {
    lumOn=false;
    c.setPix(0,0,0,0);
  }  
  
  if(valeurAimant==LOW && !aimentOn) // Si l'aiment est présent et qu'il ne l'était pas au tour de boucle précédent (!aimentOn) on allume la Led
  {
    aimentOn=true;
    c.setPix(1,0,250,0);
  }
  
  if(valeurAimant==HIGH) //Si l'aiment n'est pas présent on fait clignoté la led
  {
    aimentOn=false;
    clignote();
  }


  delay(20);
}
