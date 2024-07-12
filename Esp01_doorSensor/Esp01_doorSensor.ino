#include <WiFiManager.h>

#define pin_sensor 3
#define led_m 1
#define led_h 2

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//http client
const int port = 80;
const String host = "192.168.1.6";

void setup() {
  // put your setup code here, to run once:

    delay(500);

    pinMode(pin_sensor, INPUT);
    pinMode(led_m, OUTPUT);
    pinMode(led_h, OUTPUT);

    digitalWrite(led_m, HIGH);
    digitalWrite(led_h, LOW);

    WiFiManager wm;

    //reset wifi credentials
    wm.resetSettings();

      bool res;
      res = wm.autoConnect("Sensor Deteksi Maling");
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
    return;
  }

  int sensor_val = digitalRead(pin_sensor);

  if(sensor_val == LOW){
      HTTPClient http;
    
      String link = "http://" + host + "/esp01/datatestinsert.php?data=1";
      http.begin(client ,link);
      http.GET();

      String respon = http.getString();
      
      http.end();
  }

  
}
