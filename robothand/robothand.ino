 #include <Servo.h>

  #define servo1 6
  #define servo2 7
  #define servo3 8
  #define servo4 9
  #define servo5 10

  Servo Mservo1;
  Servo Mservo2;
  Servo Mservo3;
  Servo Mservo4;
  Servo Mservo5;

  String Secondinput;
  int RealServo;

  long lgPreviousMillis = 0;   // time period for loop
  long lgPeriod = 100;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Mservo1.attach(servo1);
  Mservo2.attach(servo2);
  Mservo3.attach(servo3);
  Mservo4.attach(servo4);
  Mservo5.attach(servo5);

  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  pinMode(servo3, OUTPUT);
  pinMode(servo4, OUTPUT);
  pinMode(servo5, OUTPUT);

  Mservo1.write(90);
  Mservo2.write(90);
  Mservo3.write(180);
  Mservo4.write(90);
  Mservo5.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
  
if((millis() - lgPreviousMillis) > lgPeriod)
{
  lgPreviousMillis = millis();
  
    if(Serial.available()>0){
    Secondinput = Serial.readStringUntil('\n');

    Secondinput.trim();
    
    Serial.print("second input = ");
    Serial.println(Secondinput);

    RealServo = 0;
    RealServo = (RealServo + Secondinput.toInt());

    Serial.print("Real Servo = ");
    Serial.println(RealServo);
    
  if(RealServo >= 1000 && RealServo <= 1180)
  {
    int Servo1Input = RealServo;
    Servo1Input = map(Servo1Input, 1000, 1180, 0, 180);
    Mservo1.write(Servo1Input);
    Serial.print("servo 1 = ");
    Serial.println(Servo1Input);
  }
  else if(RealServo >= 2000 && RealServo <= 2180)
  {
    int Servo2Input = RealServo;
    Servo2Input = map(Servo2Input, 2000, 2180, 0, 180);
    Mservo2.write(Servo2Input);
    Serial.print("servo 2 = ");
    Serial.println(Servo2Input);
  }
  else if(RealServo >= 3000 && RealServo <= 3180)
  {
    int Servo3Input = RealServo;
    Servo3Input = map(Servo3Input, 3000, 3180, 0, 180);
    Mservo3.write(Servo3Input);
    Serial.print("servo 3 = ");
    Serial.println(Servo3Input);
  }
  else if(RealServo >= 4000 && RealServo <= 4180)
  {
    int Servo4Input = RealServo;
    Servo4Input = map(Servo4Input, 4000, 4180, 0, 180);
    Mservo4.write(Servo4Input);
    Serial.print("servo 4 = ");
    Serial.println(Servo4Input);
  }
  else if(RealServo >= 5000 && RealServo <= 5180)
  {
    
    int Servo5Input = RealServo;
    Servo5Input = map(Servo5Input, 5000, 5180, 0, 180);
    Mservo5.write(Servo5Input);
    Serial.print("servo 5 = ");
    Serial.println(Servo5Input);
  }
  }
}
}
