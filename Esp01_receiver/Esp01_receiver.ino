#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//http client
const int port = 80;
const String host = "192.168.1.6";

void setup() {
  // put your setup code here, to run once:

    delay(500);

    Serial.begin(115200);

    WiFiManager wm;

     //reset wifi credentials
     wm.resetSettings();

      bool res;
      res = wm.autoConnect("Alarm Deteksi Maling");
      if(res){
        //Berhasil connect
        Serial.println("berhasil connect");
      }else{
        Serial.println("gagal connect");
      }
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
  if(!client.connect(host, port)){
    Serial.println("couldnt connect to website");
    return;
  }

  HTTPClient http;

  String link = "http://" + host + "/esp01/datareceive.php";
  http.begin(client ,link);
  http.GET();

  String respon = http.getString();

  if(respon == "aktif"){
    Serial.println("alarm menyala");
    
  }else{
    Serial.println("mati");
  }
  
  http.end();

  delay(1000);
}
