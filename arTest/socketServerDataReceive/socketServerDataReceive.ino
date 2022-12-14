#include<ESP8266WiFi.h>

//常数
//net work setting para
const char* ssid = "Buffalo-G-7470";
const char* password = "5ipjsmgunw55s";

//functions
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

//一回目の受信関数
int receiveDataLen(WiFiClient cc){
      int result;
      while (cc.connected()) {
        int result_two;
        String a[2];
        while (cc.available()>0) {
          int counter = 1;
          while(counter<=2){
            byte c = cc.read();   //byteデータ判断をつけます。
            String temp = String(c,BIN);
            String zero_temp = strPad(temp,8);
            a[counter] = zero_temp;
            counter = counter +1; 
          }
          String out_String = a[0]+a[1];
          int test_result = strToInt(out_String);
          Serial.print("THE FINAL BIT_DEC_RESULT IS:");
          Serial.println(test_result);
          delay(100);
        }
        
      }
      
      //Serial.println("THE FINAL BIT_STRING_RESULT IS:"+ out_String);
      //int test_result = strToInt(out_String);
      //Serial.print("THE FINAL BIT_DEC_RESULT IS:");
     // Serial.println(test_result);
      cc.stop();
      delay(1);
      Serial.println("Client disconnected");
      delay(1);
      Serial.println("waiting new client");
      delay(1);
      //result = test_result;
      //return result;
}

//IR情報受信関数(連続)

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

   //int listLen = receiveDataLen(client);
   if (client) {
     receiveDataLen(client);
     //Serial.println(listLen);
    }
   
   
  

}
