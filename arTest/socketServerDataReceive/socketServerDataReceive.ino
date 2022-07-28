#include<ESP8266WiFi.h>

//常数
//net work setting para
const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";

//0埋め関数定義
String strPad(String num,int zeroCount){
  String str = String(num);
  String returnStr = "";
  if(zeroCount <= str.length()){
    return str;
  }
  for(int i = 0;i < zeroCount - str.length();i++){
    returnStr += '0';
  }
  return returnStr + str;
}
//16文字のSTRINGをintに変換する 
int strToInt(String num){
  int result = 0;
  int k = 0;
  char one = '1';
  char zero = '0';
  for(int i=15;i>=0;i--){
   int beki = pow(2,k);
    if(num.charAt(i)==zero){
      result = result + 0*beki;
    }
    else if(num.charAt(i)==one){
      result = result + 1*beki;
      }
    k=k+1;
    }
    return result;
  }

WiFiServer wifiServer(1235);

void setup() {
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

}

void loop() {
  WiFiClient client = wifiServer.available();
 
  if (client) {
    String a[2];
    while (client.connected()) {
      
      int counter = 0;
      while (client.available()>0) {
        byte c = client.read();   //byteデータ判断をつけます。
        //Serial.write(c);
        //Serial.println(c);
        String temp = String(c,BIN);
        //Serial.println(temp);
        String zero_temp = strPad(temp,8);
        //Serial.println(zero_temp);
        a[counter] = zero_temp;
        counter = counter +1;
        
      }
      
      
      delay(10);
      client.println("Hello From ESP8266x2");
    }
    String out_String = a[0]+a[1];
    Serial.println("THE FINAL BIT_STRING_RESULT IS:"+ out_String);
    int test_result = strToInt(out_String);
    Serial.print("THE FINAL BIT_DEC_RESULT IS:");
    Serial.println(test_result);
    
  
    
 
    client.stop();
    delay(10);
    Serial.println("Client disconnected");
    delay(10);
    Serial.println("waiting new client");
    delay(10);
 
  }

}
