#include <Servo.h>
#define analog A0
#define pin_servo 2
#define buton 4
int y;
int f;
int b;
Servo servo;


void setup(){
  // put your setup code here, to run once:
pinMode(analog, INPUT);
pinMode(pin_servo, OUTPUT);
pinMode(buton, OUTPUT);
Serial.begin(9600);

servo.attach(pin_servo);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  b = digitalRead(buton);
  Serial.println(b);
  if(b == 1){
  y = analogRead(analog);
  Serial.println(y);
  f = map(y,0,1023,0,255);
  servo.write(f);}
  
  
  

}
