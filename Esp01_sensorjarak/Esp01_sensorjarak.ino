#include <NewPingESP8266.h>

#define pin_trig 0
#define pin_echo 2
int jarak;
int jaraklama;

NewPingESP8266 sensor_jarak(pin_trig, pin_echo, 20);

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//wifi and pass
const String ssid = "IT KOMPUTER";
const String pass = "pelangi212";

//http client
const int port = 80;
const String host = "192.168.1.6";

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);

    delay(500);

    pinMode(pin_trig, INPUT);
    pinMode(pin_echo, INPUT);
    
    WiFi.begin(ssid, pass);
    
    Serial.println("connecting");
    while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    
    Serial.println("connected succesfully!");
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
  if(!client.connect(host, port)){
    Serial.println("couldnt connect to website");
    return;
  }

  jarak = sensor_jarak.ping_cm();

  if(jarak != jaraklama){

      Serial.print(jarak);
      Serial.println("cm");
     
      HTTPClient http;
    
      String link = "http://" + host + "/esp01/datatestinsert.php?data=" + jarak;
      http.begin(client ,link);
      http.GET();
    
      String respon = http.getString();
      Serial.println(respon);
      http.end();
      jaraklama = jarak;
  }

  
}
