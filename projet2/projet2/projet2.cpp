#include "projet2.h"

#include "index.h"

//Initialise les différentes variables de l'utilitaire
Projet2::Projet2():collpixs(2, D4, NEO_GRB + NEO_KHZ800),VMAX(100),vitesseGauche(0),vitesseDroit(0),
server(80),webisstop(false),page(MAIN_page),modeEtat(1),colId(0),seuilMin(700),seuilMax(800)
{
  //Remplissage du tableau de choix des couleurs
 tcol[0]=collpixs.Color(200,50,0);
 tcol[1]=collpixs.Color(0,50,200);
 tcol[2]=collpixs.Color(0,200,0);
}

//Méthode d'initialisation des leds
void Projet2::initPix(int pin, int num) {
  collpixs.setPin(pin);
  collpixs.updateLength(num);
  collpixs.begin();
}

void Projet2::setPix(int idpix, int rval, int vval, int bval)
{
  collpixs.setPixelColor(idpix, collpixs.Color(rval,vval,bval));
  collpixs.show();
}
//Méthode qui allume une led selon la couleur choisie par l'interface web (Projet2::col())
void Projet2::pixOn(int id)
{
  collpixs.setPixelColor(id, tcol[colId]);
  collpixs.show();
}
void Projet2::setPixs(int r, int v, int b)
{
	for(int i=0; i<collpixs.numPixels(); i++) {
		collpixs.setPixelColor(i, collpixs.Color(r,v,b));
	}
	collpixs.show();
}

//Méthode pour initialisé les moteurs
void Projet2::initRoues(int pinG, int pinD)
{
  servoDroit.attach(pinG);
  servoGauche.attach(pinD);
  stop();
}

void Projet2::avancer()
{
	setVitesseDroite(VMAX);
	setVitesseGauche(VMAX);
}
void Projet2::reculer()
{
	setVitesseDroite(-VMAX);
	setVitesseGauche(-VMAX);
}
void Projet2::tournerGauche()
{
	setVitesseDroite(VMAX);
	setVitesseGauche(-VMAX);
}
void Projet2::tournerDroite()
{
	setVitesseDroite(-VMAX);
	setVitesseGauche(VMAX);
}
void Projet2::stop()
{
	setVitesseDroite(0);
	setVitesseGauche(0);
}
void Projet2::setVitesseDroite(int v)
{
	servoDroit.write(map(v, -VMAX, VMAX, 0, 180));
	vitesseDroit=v;
}
void Projet2::setVitesseGauche(int v)
{
	servoGauche.write(map(-v, -VMAX, VMAX, 0, 180)); 
	vitesseGauche=v;
}
int Projet2::getVitesseDroite()
{
	return vitesseDroit;
}
int Projet2::getVitesseGauche()
{
	return vitesseGauche;
}


int Projet2::getSeuilMin(){
  return seuilMin;
}
int Projet2::getSeuilMax(){
  return seuilMax;
}
int Projet2::getCol(){
  return colId;
}
int Projet2::getMode(){
  return modeEtat;
}

//Méthode apeller par le microserver web, elle affiche l'interface
void Projet2::handleRoot() {
  server.send(200, "text/html", page);
}

void Projet2::changeIndex(String ppage)
{
	page=ppage;
}

void Projet2::ron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
  if(!webisstop)
  {
    if(modeEtat==1)
	    setVitesseDroite(VMAX);
     else
      tournerDroite();
  }
}
void Projet2::rron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
  if(!webisstop)
  {
	  
    if(modeEtat==1)
	    setVitesseDroite(-VMAX);
  }
}
void Projet2::roff() {
  server.send(200, "text/html", "<h1>Right off</h1>");
  if(!webisstop)
  {
    if(modeEtat==1)
	    setVitesseDroite(0);
    else
      stop();
  }
}
void Projet2::lon() {
  server.send(200, "text/html", "<h1>Left on</h1>");
  if(!webisstop)
  {
	  
    if(modeEtat==1)
	    setVitesseGauche(VMAX);
     else
      tournerGauche();
  }
}
void Projet2::lron() {
  server.send(200, "text/html", "<h1>Left on</h1>");
  if(!webisstop)
  {
	  if(modeEtat==1)
	    setVitesseGauche(-VMAX);
  }
}
void Projet2::loff() {
  server.send(200, "text/html", "<h1>Left off</h1>");
  if(!webisstop)
  {
	  
    if(modeEtat==1)
	    setVitesseGauche(0);
    else
      stop();
  }
}


void Projet2::mode1() {
  server.send(200, "text/html", "<h1>OK</h1>");
  Serial.println("mode1");
 modeEtat=1;
 stop();
}
void Projet2::mode2() {
  server.send(200, "text/html", "<h1>OK</h1>");
  Serial.println("mode2");
 modeEtat=2;
 stop();
 
}
void Projet2::col() {
  server.send(200, "text/html", "<h1>OK</h1>");
  Serial.println("col");
 colId++;
 colId%=3;
 
 pixOn(0);
 pixOn(1);
}
void Projet2::seuilmin() {
  server.send(200, "text/html", "<h1>OK</h1>");
 seuilMin=analogRead(A0)+10;
  Serial.println(seuilMin);
  Serial.println("seuilmin");
}
void Projet2::seuilmax() {
  server.send(200, "text/html", "<h1>OK</h1>");
 seuilMax=analogRead(A0)-10;
  Serial.println(seuilMax);
  Serial.println("seuilmax");
 
}


//Initialise le wifi et le microserver web
void Projet2::initWeb(const char *ssid,const char *password)
{
	
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  //Attache les urls aux fonctions correspondantes
  server.on("/", std::bind(&Projet2::handleRoot,this));
  server.on("/ron", std::bind(&Projet2::ron,this));
  server.on("/rron", std::bind(&Projet2::rron,this));
  server.on("/roff", std::bind(&Projet2::roff,this));
  server.on("/lon", std::bind(&Projet2::lon,this));
  server.on("/lron", std::bind(&Projet2::lron,this));
  server.on("/loff", std::bind(&Projet2::loff,this));
  server.on("/mode1", std::bind(&Projet2::mode1,this));
  server.on("/mode2", std::bind(&Projet2::mode2,this));
  server.on("/col", std::bind(&Projet2::col,this));
  server.on("/seuilmin", std::bind(&Projet2::seuilmin,this));
  server.on("/seuilmax", std::bind(&Projet2::seuilmax,this));
  server.begin();
}


void Projet2::stopWeb(bool stop)
{
	webisstop=stop;
}

void Projet2::loopWeb()
{
  server.handleClient();
}
  

