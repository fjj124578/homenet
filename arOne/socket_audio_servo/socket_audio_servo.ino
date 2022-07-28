#include<ESP8266WiFi.h>
#include <Servo.h>
//常数
//net work setting para
const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";
//instance make
WiFiServer wifiServer(1235);
Servo pipi;

void setup() {

  pipi.attach(4);
  Serial.begin(115200);
 
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
 
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
  pipi.write(20);
  


}

void loop() {
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
      
      while (client.available()>0) {
        byte c = client.read();   //byteデータ判断をつけます。
        Serial.write(c);
        
        if(c == 0){
          Serial.println("got in c=0");
          pipi.write(92);
          delay(1000);
          pipi.write(30);
        }else if(c==1){
          Serial.println("got in c=1");
          pipi.write(50);
        }
        else if(c==2){
          Serial.println("got in c=2");
        }
        else if(c==3){
          Serial.println("got in c=3");
        }
        else if(c==4){
          Serial.println("got in c=4");
        }else if(c==5){
          Serial.println("got in c=5");
        }
        else{
          Serial.println("got something wrong");
        }
        
      }
      
      
      delay(1000);
      client.println("Hello From ESP8266");
    }
 
    client.stop();
    delay(1000);
    Serial.println("Client disconnected");
    delay(1000);
    Serial.println("waiting new client");
    delay(1000);
 
  }

}
