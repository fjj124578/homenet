#include<ESP8266WiFi.h>

//常数
  //net work setting para
  const char* ssid = "Buffalo-G-7470";
  const char* password = "5ipjsmgunw55s";

//関数定義
  //0埋め関数定義
  String strPad(String num,int zeroCount){
    /*
    二進数string numの桁数をzeroCountまで埋める
    eg 11011→00011011
    */
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
    /*
    二進数(String)→十進数(int)の変換
    */
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
  
  //2バイトずつ受信用関数
  int receiveTwoByte(WiFiClient client){
    /*２バイトずつ受信して、十進数intに変換して、returnする*/
    String a[2];
  byte c_1 = client.read();
  byte c_2 = client.read();  
  delay(10);
  //Serial.println(c_1);
  //Serial.println(c_2);
  String temp = String(c_1,BIN);
  String temp2 = String(c_2,BIN);
  //Serial.println(temp);
  String zero_temp_1 = strPad(temp,8);
  String zero_temp_2 = strPad(temp2,8);
  //Serial.println(zero_temp);
  a[0] = zero_temp_1;
  a[1] = zero_temp_2;

  String out_String = a[0]+a[1];
  Serial.println("THE FINAL BIT_STRING_RESULT IS:"+ out_String);
  delay(10);
  client.println("Hello From ESP8266x2");
  int test_result = strToInt(out_String);
  Serial.print("THE FINAL BIT_DEC_RESULT IS:");
  Serial.println(test_result);
  return test_result;
    }

WiFiServer wifiServer(1235); //サーバーのインスタンスを作成する

void setup() {
  Serial.begin(115200);
 
  delay(1000);
  
  WiFi.begin(ssid, password);  //set the init of server
 
  while (WiFi.status() != WL_CONNECTED) { //await server
    delay(1000);
    Serial.println("Connecting..");
  }
 
  Serial.print("Connected to WiFi. IP:");  //connect result out put
  Serial.println(WiFi.localIP()); //connect result out put
 
  wifiServer.begin();   //start a server

}

void loop() {
  WiFiClient client = wifiServer.available();   //Gets a client that is connected to the server and has data available for reading. 
  if (client) {
    while (client.connected()) {   //when get a client connection
        int listLen = receiveTwoByte(client);  //get first two bytes (in order to get data len)
        int rawData[listLen];          // declaration of rawData list
        int counter = 0;           //a counter for [available] loop
        delay(10);
        while (client.available()>0){   //when there is data behind
          int tempIntData = receiveTwoByte(client);    //get next two byte and convert it into int
          rawData[counter]=tempIntData;            // put int data into rawdata list
          counter = counter + 1;                   //set iterator increment
          delay(10);
         }
         client.println("受信オッケー");         //sent okay to python
         client.stop();                           //cut connection 
         delay(10);
         Serial.println("Client disconnected");
         delay(10);
         Serial.println("waiting new client");
         delay(10);
         Serial.println(rawData[0]); 
         
       
      } 
    }
    
  }
