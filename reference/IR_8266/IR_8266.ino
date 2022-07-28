#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266WebServerSecureAxTLS.h>
#include <ESP8266WebServerSecureBearSSL.h>
//#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.


const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);



//set send
  //turn on
  uint16_t rawData_1[83] = {3450,1700, 450,450, 400,450, 400,1300, 400,1300, 400,450, 450,1250, 450,450, 400,450, 400,450, 450,1200, 450,450, 400,450, 400,1300, 500,350, 450,1250, 500,400, 450,1150, 600,350, 500,350, 500,1100, 600,400, 450,400, 450,400, 450,400, 450,1250, 500,350, 500,1200, 500,350, 500,1200, 500,1200, 500,400, 500,350, 500,350, 500,350, 500,1200, 500,1250, 450,1250, 450,1250, 450,400, 450,400, 500};
  //turn off
  uint16_t rawData_2[83] = {3450,1700, 400,450, 400,450, 400,1300, 450,1300, 400,400, 450,1300, 400,450, 400,450, 400,450, 400,1300, 450,400, 450,400, 450,1250, 450,400, 450,1300, 450,400, 450,1300, 400,400, 450,400, 450,1300, 400,400, 450,450, 400,450, 400,450, 450,1250, 450,1250, 450,1250, 450,450, 400,1300, 450,1300, 400,400, 450,400, 450,400, 450,1300, 400,1300, 450,1300, 400,1300, 400,1300, 400,450, 400,450, 450};
  //to be white
  uint16_t rawData_3[83] = {3450,1700, 450,400, 450,400, 450,1300, 400,1300, 400,450, 400,1300, 450,400, 450,400, 450,400, 450,1300, 400,400, 450,400, 450,1300, 400,450, 450,1250, 450,400, 450,1300, 400,400, 450,450, 400,1300, 450,1250, 450,1300, 400,400, 450,400, 450,400, 450,450, 400,1300, 450,400, 450,1300, 400,400, 450,400, 450,1300, 400,1300, 400,700, 150,1350, 400,1300, 400,400, 450,1300, 400,450, 400,1300, 450};
  //to be warm
  uint16_t rawData_4[83] = {3450,1950, 150,450, 400,450, 400,1300, 450,1300, 400,400, 450,1300, 400,450, 400,450, 400,450, 450,1300, 400,400, 450,400, 450,1300, 400,400, 450,1300, 450,400, 450,1250, 450,400, 450,400, 450,1300, 400,1300, 450,1250, 450,400, 450,400, 450,1300, 400,400, 450,1300, 450,400, 450,1300, 400,400, 450,400, 450,1250, 450,450, 400,450, 400,1300, 450,1250, 450,400, 450,1300, 400,450, 400,1300, 450};
  //more britter
  uint16_t rawData_5[83] = {3450,1700, 450,400, 450,400, 450,1300, 450,1250, 450,400, 450,1250, 450,400, 450,400, 450,400, 450,1300, 450,400, 450,400, 450,1250, 450,400, 450,1300, 400,450, 400,1300, 450,400, 450,400, 450,1250, 450,400, 450,400, 450,450, 400,450, 400,450, 450,1250, 450,400, 450,400, 450,1250, 450,1300, 400,450, 400,450, 450,1250, 450,1250, 450,400, 450,1300, 400,1300, 450,1250, 450,400, 450,400, 450};
  //less britter
  uint16_t rawData_6[83] = {3450,1700, 450,400, 450,400, 450,1300, 400,1300, 400,450, 400,1300, 450,400, 450,350, 500,350, 500,1300, 400,350, 500,300, 550,1300, 450,350, 500,1300, 400,300, 550,1300, 400,350, 500,400, 450,1300, 450,250, 600,400, 450,400, 450,400, 450,1300, 400,1300, 400,350, 550,400, 450,1300, 400,1300, 400,300, 550,300, 550,450, 550,1400, 150,450, 450,1300, 400,1300, 400,1300, 400,350, 550,400, 450};

 String message = "<html><head></head><body><h1>okay</h1></body></html>";
    

void setup() {
  Serial.begin(115200);
  delay(10);
  irsend.begin();
 
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);
  //prepare GPI05
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request_1
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match
  
  if (req.indexOf("/1/0") != -1){
   irsend.sendRaw(rawData_1,83,38);
   client.println("HTTP/1.1 200 OK");
  }
  else if (req.indexOf("/1/1") != -1){
   irsend.sendRaw(rawData_2,83,38);
   client.println("HTTP/1.1 200 OK");
  }
  else if (req.indexOf("/2/0") != -1){
   irsend.sendRaw(rawData_3,83,38);
   client.println("HTTP/1.1 200 OK");
  }
  else if (req.indexOf("/2/1") != -1){
   irsend.sendRaw(rawData_4,83,38);
   client.println("HTTP/1.1 200 OK");
  }
  else if (req.indexOf("/3/0") != -1){
   irsend.sendRaw(rawData_5,83,38);
   client.println("HTTP/1.1 200 OK");
  }
  else if (req.indexOf("/3/1") != -1){
   irsend.sendRaw(rawData_6,83,38);
   client.println("HTTP/1.1 200 OK");
  }

  
  else {
    client.println("HTTP/1.1 200 OK");
    Serial.println("invalid request");
    client.stop();
    return;
  }
  client.flush();
  String s="good";
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
  
  

}
