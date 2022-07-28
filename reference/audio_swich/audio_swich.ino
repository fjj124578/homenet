#include <ESP8266WiFi.h>
#include <Servo.h>

Servo pipi;
const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";

WiFiServer server(80);




void setup() {
  pipi.attach(4);

  Serial.begin(115200);
  delay(10);
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
  if (req.indexOf("/1/0") != -1){
   
   pipi.write(92);}
   
  else if (req.indexOf("/1/1") != -1){
   pipi.write(50);}
}
