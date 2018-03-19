#include<college.h>

#include <index.h>


College::College():collpixs(2, D4, NEO_GRB + NEO_KHZ800),VMAX(100),vitesseGauche(0),vitesseDroit(0),
server(80),webisstop(false),page(MAIN_page)
{
	
}

void College::initPix(int pin, int num) {
  collpixs.setPin(pin);
  collpixs.updateLength(num);
  collpixs.begin();
}

void College::setPix(int idpix, int rval, int vval, int bval)
{
  collpixs.setPixelColor(idpix, collpixs.Color(rval,vval,bval));
  collpixs.show();
}
void College::setPixs(int r, int v, int b)
{
	for(int i=0; i<collpixs.numPixels(); i++) {
		collpixs.setPixelColor(i, collpixs.Color(r,v,b));
	}
	collpixs.show();
}


void College::initRoues(int pinG, int pinD)
{
  servoDroit.attach(pinG);
  servoGauche.attach(pinD);
  stop();
}

void College::avancer()
{
	setVitesseDroite(VMAX);
	setVitesseGauche(VMAX);
}
void College::reculer()
{
	setVitesseDroite(-VMAX);
	setVitesseGauche(-VMAX);
}
void College::tournerGauche()
{
	setVitesseDroite(VMAX);
	setVitesseGauche(-VMAX);
}
void College::tournerDroite()
{
	setVitesseDroite(-VMAX);
	setVitesseGauche(VMAX);
}
void College::stop()
{
	setVitesseDroite(0);
	setVitesseGauche(0);
}
void College::setVitesseDroite(int v)
{
	servoDroit.write(map(v, -VMAX, VMAX, 0, 180));
	vitesseDroit=v;
}
void College::setVitesseGauche(int v)
{
	servoGauche.write(map(-v, -VMAX, VMAX, 0, 180)); 
	vitesseGauche=v;
}
int College::getVitesseDroite()
{
	return vitesseDroit;
}
int College::getVitesseGauche()
{
	return vitesseGauche;
}




void College::handleRoot() {
  server.send(200, "text/html", page);
}

void College::changeIndex(String ppage)
{
	page=ppage;
}

void College::ron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
  if(!webisstop)
  {
	  setVitesseDroite(VMAX);
  }
}
void College::rron() {
  server.send(200, "text/html", "<h1>Right on</h1>");
  if(!webisstop)
  {
	  
	  setVitesseDroite(-VMAX);
  }
}
void College::roff() {
  server.send(200, "text/html", "<h1>Right off</h1>");
  if(!webisstop)
  {
	  
	  setVitesseDroite(0);
  }
}
void College::lon() {
  server.send(200, "text/html", "<h1>Left on</h1>");
  if(!webisstop)
  {
	  
	  setVitesseGauche(VMAX);
  }
}
void College::lron() {
  server.send(200, "text/html", "<h1>Left on</h1>");
  if(!webisstop)
  {
	  
	  setVitesseGauche(-VMAX);
  }
}
void College::loff() {
  server.send(200, "text/html", "<h1>Left off</h1>");
  if(!webisstop)
  {
	  
	  setVitesseGauche(0);
  }
}



void College::initWeb(const char *ssid,const char *password)
{
	
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", std::bind(&College::handleRoot,this));
  server.on("/ron", std::bind(&College::ron,this));
  server.on("/rron", std::bind(&College::rron,this));
  server.on("/roff", std::bind(&College::roff,this));
  server.on("/lon", std::bind(&College::lon,this));
  server.on("/lron", std::bind(&College::lron,this));
  server.on("/loff", std::bind(&College::loff,this));
  server.begin();
}


void College::stopWeb(bool stop)
{
	webisstop=stop;
}

void College::loopWeb()
{
  server.handleClient();
}
  

