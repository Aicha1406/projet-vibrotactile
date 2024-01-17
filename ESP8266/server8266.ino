#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

// Set your access point network credentials
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup(){
  
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();

  server.on("/test1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "Message A");
  });
  server.on("/test2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "b" );
  });
  server.on("/test3", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "c" );
  });
  
  // Start server
  server.begin();
}
 
void loop(){
  
}
