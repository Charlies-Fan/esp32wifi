#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "Zenfone 10_5867";
const char *password = "uzptu2p5f66c6mx";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("WiFi Connected");
  Serial.print("My IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Submask = ");
  Serial.println(WiFi.subnetMask());
}

void loop() {

}