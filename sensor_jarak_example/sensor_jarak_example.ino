#include <NewPing.h>
#define pin_trig 2
#define pin_echo 3

NewPing sensor_jarak(pin_trig, pin_echo, 30);

int jarak;

void setup() {

  Serial.begin(9600);
  pinMode(pin_trig, INPUT);
  pinMode(pin_echo, INPUT);

}

void loop() {

  jarak = sensor_jarak.ping_cm();
  Serial.print(jarak);
  Serial.println("cm");
  delay(100);
}
