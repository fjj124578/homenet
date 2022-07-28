#include<ESP8266WiFi.h>


//net work setting para
const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";

const uint16_t port = 50007;
const char * host = "192.168.11.20";         


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  //set up connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  

}

void connection1(){
  WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }

    Serial.println("Connected to server successful!");

    client.print("turn on");

    Serial.println("Disconnecting...");
    client.stop();
  }
  
void connection2(){
  WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }

    Serial.println("Connected to server successful!");

    client.print("turn off");

    Serial.println("Disconnecting...");
    client.stop();
  }
  
void connection3(){
  WiFiClient client;
  if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }

    Serial.println("Connected to server successful!");
    int i;
    for(i=1;i<11;i++){
      client.println("this is socket client connection3");
      client.println(i);
 
        
        
      delay(2000);
      } 
    client.println("stop");

    Serial.println("Disconnecting...");
    client.stop();
  }

  
void loop() {
  // put your main code here, to run repeatedly:
  connection3();
  delay(60000);
}
