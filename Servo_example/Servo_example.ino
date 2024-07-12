#include <Servo.h>
#define pin_Servo 2

Servo Servo_1;

void setup() {

  Servo_1.attach(pin_Servo);
  
}

void loop() {

  for(int i = 0; i <= 180; i++)
  {
    Servo_1.write(i);
    delay(20);
  }

}
