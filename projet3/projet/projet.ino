#include<college.h>
#include <Bounce2.h>

const int capteurAimantPin = D3; //Pin de l'aiment

//SSID et mot de passe wifi
const char *ssid = "projet3T";
const char *password = "fabmstic";

Bounce debouncer = Bounce(); //Bounce objet pour la gestion des évenements du bouton

College c; //Utilitaire pour la gestion des moteurs, des leds et de l'interface web 

//Booléen permettant de changer la couleur uniquement à un changment de direction(ou arret)
bool avLum=false;
bool arLum=false;

//Pattern lumineux exécuté lorque le téléphone est posé ou retiré.
void patternPix()
{
    c.setPixs(0,100,150);
    delay(1000);
    c.setPixs(0,200,0);
    delay(1000);
    c.setPixs(250,0,0);
    delay(1000);
    c.setPixs(0,0,0);
    delay(1000);
}

//Initialisation
void setup() {
  Serial.begin(9600);
  c.initWeb(ssid,password);//Initialise l'interface web et le wifi
  c.initPix(D4,2); // Initialise les leds (Pin D4, nombre de leds 2)
  c.initRoues(D1,D2); //Initialise les moteurs connectés au pin D1 et D2
  
  //Initialise la pin de l'intérupteur et l'objet debouncer qui s'y ratache
  pinMode(capteurAimantPin,INPUT_PULLUP);
  debouncer.attach(capteurAimantPin);
  debouncer.interval(500);
  
  //éteint les leds
  c.setPixs(0,0,0);
}

void loop() {
  //ValeurLum est inversement proportinel a la lumière détecté. Plus il fait sombre plus la valeur est élever.
  //Cette valeur est ensuite utilisé pour les leds
  int valeurLum = 250-map(analogRead(A0),0,1023,0,250);
  
  Serial.print("");
  Serial.println(valeurLum);
  
  debouncer.update();//mise a jour du debouncer
  c.loopWeb(); // gestion des évenements de l'interface Web

  if((c.getVitesseDroite()>0 || c.getVitesseGauche()>0) && !avLum) //Si un des moteurs va en avant et que la led avant est éteinte on l'allume
  {
    avLum=true;
    c.setPix(0,valeurLum,valeurLum,valeurLum);
  }
  
  if(!(c.getVitesseDroite()>0 || c.getVitesseGauche()>0) && avLum) //Si aucun des moteurs va en avant et que la led avant est allumée on l'éteint
  {
    avLum=false;
    c.setPix(0,0,0,0);
  }
  if((c.getVitesseDroite()<0 || c.getVitesseGauche()<0) && !arLum) // Idem led arrière
  {
    arLum=true;
    c.setPix(1,valeurLum,valeurLum,valeurLum);
  }
  if(!(c.getVitesseDroite()<0 || c.getVitesseGauche()<0) && arLum) // Idem led arrière
  {
    arLum=false;
    c.setPix(1,0,0,0);
  }
  

  if(debouncer.fell()) //Si l'intérupteur passe de HIGH à LOW (l'aiment est prohe du capteur)
  {
	//La voiture s'arrête et le pattern lumineux est joué 3 fois.
    c.stop();
    for(int i=0;i<3;i++)
    {
      patternPix();
    }
  }

  if(debouncer.rose()) //Si l'intérupteur passe de LOW à HIGH (l'aiment est retiré du capteur)
  {
    c.stop();
    patternPix();
  }
  
  delay(20);
}
