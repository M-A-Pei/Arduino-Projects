#include <Servo.h>

#define pinServo 2
#define analog A0
int x;
int posisi;
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(pinServo);
  pinMode(pinServo, OUTPUT);
 pinMode(analog, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  x =  analogRead(analog);
  Serial.println(x);

  posisi = map(x, 0, 1023, 0, 255);

  servo1.write(posisi);
  Serial.println(posisi);
  delay(20);
}
