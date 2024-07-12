#include <Servo.h>

#define pinServo 2

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(pinServo);
  pinMode(pinServo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;    i < 255;      i++){
    servo1.write(i);
    delay(20);
  }

  for(int j = 255; j > 0; j--){
    servo1.write(j);
    delay(20);
    
  }
  
}
