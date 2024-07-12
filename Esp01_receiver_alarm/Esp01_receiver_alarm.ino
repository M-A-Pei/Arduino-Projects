#include <WiFiManager.h>

#define pin_alarm 0
#define led_m 1
#define led_h 2

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//http client
const int port = 80;
const String host = "192.168.1.4";

void setup() {
  // put your setup code here, to run once:

    delay(500);

    pinMode(pin_alarm, OUTPUT);
    pinMode(led_m, OUTPUT);
    pinMode(led_h, OUTPUT);

    digitalWrite(led_m, HIGH);
    digitalWrite(led_h, LOW);
    digitalWrite(pin_alarm, LOW);

    WiFiManager wm;

    //reset wifi credentials
    wm.resetSettings();

      bool res;
      res = wm.autoConnect("Alarm Deteksi Maling");
      if(res){
        //Berhasil connect
        digitalWrite(led_h, HIGH);
        digitalWrite(led_m, LOW);
      }
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
  if(!client.connect(host, port)){
    Serial.println("couldnt connect to website");
      digitalWrite(pin_alarm, HIGH);

      delay(500);
    
      digitalWrite(pin_alarm, LOW);
    
      delay(500);
    return;
  }

  HTTPClient http;
    
  String link = "http://" + host + "/esp01/datareceive.php";
  http.begin(client ,link);
  http.GET();

  String respon = http.getString();

  if(respon == "aktif"){
    digitalWrite(pin_alarm, HIGH);
//    delay(250);
//    digitalWrite(pin_alarm, LOW);
//    delay(10);
  }else{
    digitalWrite(pin_alarm, LOW);
  }
  
  http.end();

  delay(1000);

  
}
