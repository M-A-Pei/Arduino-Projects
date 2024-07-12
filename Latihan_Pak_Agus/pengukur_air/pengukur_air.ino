#include <NewPing.h>
#define pin_trig 2
#define pin_echo 3
#define LED_red 4
#define LED_blue 5
#define LED_green 6

NewPing sensor_jarak(pin_trig,pin_echo, 15); //objek sensor

int jarak;
void setup() {


  Serial.begin(9600);
  pinMode(pin_trig, INPUT);
  pinMode(pin_echo, INPUT);
  pinMode(LED_blue, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(LED_green, OUTPUT);

}

void loop(){

  jarak = sensor_jarak.ping_cm();  //jarak dari sensor ke tembok

  Serial.println(jarak);
  
  if(jarak > 13){
    digitalWrite(LED_red, HIGH);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
  }else if(jarak > 8){
    digitalWrite(LED_blue, HIGH);
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, LOW);
  }else if(jarak == 0){
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
  }else{
    digitalWrite(LED_green, HIGH);
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_blue, LOW);
  }
  
  Serial.print(jarak);
  Serial.println("cm");
  delay(500);
}
