#include <Arduino.h>
#include <WebServer.h>

const char *ssid = "Zenfone 10_5867";
const char *password = "uzptu2p5f66c6mx";

WebServer server(80);

void handleRoot ()
{
  server.send(200, "text/html; charset=UTF-8", "Hello World");
}

void handleNotFound()
{
  server.send(404, "text/plain; charset=UTF-8", "找不到檔案");
}

void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);

 while (WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print(".");
 }

 Serial.println("WiFi Connnected");
 Serial.print("My IP = ");
 Serial.println(WiFi.localIP());
 
 server.on("/",handleRoot);
 server.onNotFound(handleNotFound);
 server.begin();
 Serial.println("Server is running...");
}

void loop() {
  server.handleClient();
}

