
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

    delay(2000);
    
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

  Serial.println("koneksi ke website berhasil");

  HTTPClient http;

  String link = "http://" + host + "/esp01/datatestinsert.php?data=8888";
  http.begin(client ,link);
  http.GET();

  String respon = http.getString();
  Serial.println(respon);
  http.end();

  delay(1000);
  

  
}
