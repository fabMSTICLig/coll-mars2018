
const int capteurLumierePin = A0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valeur = analogRead(capteurLumierePin);
  Serial.print("");
  Serial.println(valeur);
  delay(50);
}
