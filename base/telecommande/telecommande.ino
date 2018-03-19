

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <Bounce2.h>
#include <ESP8266HTTPClient.h>


//const char* ssid = "fabMSTIC";
//const char* password = "plusdechocolatx2";
const char *ssid = "projet2";
const char *password = "fabmstic";

Bounce ron = Bounce();
Bounce rron = Bounce(); 
Bounce lon = Bounce();
Bounce lron = Bounce(); 

const IPAddress remote_ip(192, 168, 4, 1);

void httpreq(String s){
        HTTPClient http;
        int inheure=0;
        int inminute=0;
        Serial.print("[HTTP] begin...\n");
        String url= String("http://192.168.4.1/")+s;
        http.begin("192.168.4.1",80,"/"+s); //HTTP
        Serial.println("[HTTP] GET..."+url);
        int httpCode = http.GET();

        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);
            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
}


void setup() {
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
IPAddress ip(192,168,4,10);   
IPAddress gateway(192,168,4,1);   
IPAddress subnet(255,255,255,0);   
WiFi.config(ip, gateway, subnet);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(D4,INPUT_PULLUP);

  // After setting up the button, setup the Bounce instance :
  ron.attach(D1);
  rron.attach(D2);
  lon.attach(D3);
  lron.attach(D4);
  ron.interval(50); // interval in ms
  rron.interval(50); // interval in ms
  lon.interval(50); // interval in ms
  lron.interval(50); // interval in ms


  httpreq("");

}

void loop() {
  
  ron.update();
  rron.update();
  lon.update();
  lron.update();

  if(ron.fell())
  {
    httpreq("ron");
  }
  if(rron.fell())
  {
    httpreq("rron");
  }
  if(lon.fell())
  {
    httpreq("lon");
  }
  if(lron.fell())
  {
    httpreq("lron");
  }
  
  if(ron.rose())
  {
    httpreq("roff");
  }
  if(rron.rose())
  {
    httpreq("roff");
  }
  if(lon.rose())
  {
    httpreq("loff");
  }
  if(lron.rose())
  {
    httpreq("loff");
  }

}
