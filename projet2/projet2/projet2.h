#ifndef PROJET2_H
#define PROJET2_H

#include <Adafruit_NeoPixel.h>

#include <Servo.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

//Déclaration de la classe de l'utilitaire pour la gestion des moteurs, des leds et de l'interface web
class Projet2{
	private:
	
	Adafruit_NeoPixel collpixs;

	Servo servoDroit;
	Servo servoGauche;
	const int VMAX;
	int vitesseGauche;
	int vitesseDroit;
	ESP8266WebServer server;
	bool webisstop;
	String page;

	int modeEtat;
	int colId;

	uint32_t tcol[3];

	int seuilMin;
	int seuilMax;


	void handleRoot();
	void ron();
	void rron();
	void roff();
	void lon();
	void lron();
	void loff();
	void mode1();
	void mode2();
	void col();
	void seuilmin();
	void seuilmax();


	public:
	Projet2();

	void initPix(int pin, int num);
	void setPix(int id, int r, int v, int b);
	void pixOn(int id);
	void setPixs(int r, int v, int b);

	void initRoues(int pinL, int pinR);

	void avancer();
	void reculer();
	void tournerGauche();
	void tournerDroite();
	void stop();
	void setVitesseDroite(int v);
	void setVitesseGauche(int v);
	int getVitesseDroite();
	int getVitesseGauche();

	int getSeuilMin();
	int getSeuilMax();
	int getCol();
	int getMode();



	void initWeb(const char *ssid,const char *password);
	void changeIndex(String page);
	void stopWeb(bool stop);

	void loopWeb();
};
#endif
