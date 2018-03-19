#ifndef COLLEGE_H
#define COLLEGE_H

#include <Adafruit_NeoPixel.h>

#include <Servo.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

class College{
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
	
	
	void handleRoot();
	void ron();
	void rron();
	void roff();
	void lon();
	void lron();
	void loff();

	
	public:
	College();
	
void initPix(int pin, int num);
void setPix(int id, int r, int v, int b);
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



void initWeb(const char *ssid,const char *password);
void changeIndex(String page);
void stopWeb(bool stop);

void loopWeb();
};
#endif