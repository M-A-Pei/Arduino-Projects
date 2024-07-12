#include <Servo.h>
#include <AFMotor.h>

Servo gripper;
//0 is close 80 is open
//is servo 1

Servo arm;
//180 is up and 0 is down
//is servo 2

AF_DCMotor motor_Kanan_Depan(3);
AF_DCMotor motor_Kanan_Belakang(2);
AF_DCMotor motor_Kiri_Depan(1);
AF_DCMotor motor_Kiri_Belakang(4);

char input;

void setup() {
  // put your setup code here, to run once:
  gripper.attach(10);
  arm.attach(9);
   Serial.begin(9600);

   gripper.write(70);
   Serial.println("start");

   motor_Kanan_Depan.setSpeed(100);
   motor_Kanan_Belakang.setSpeed(100);
   motor_Kiri_Depan.setSpeed(100);
   motor_Kiri_Belakang.setSpeed(150);
}

void loop() {

  if(Serial.available()>0){
    
    input = Serial.read();
  
    Serial.print("real input = ");
    Serial.println(input);
  
    switch(input){
        case 'L':
          left();
        break;

        case 'R':
          right();
        break;

        case 'F':
          forward();
        break;

        case 'B':
          backward();
        break;

        case 'K':
          spin_right();
        break;

        case 'J':
          spin_left();
        break;

        case 'U':
          arm.write(0);
        break;

        case 'D':
          arm.write(180);
        break;

        case 'O':
          gripper.write(70);
        break;

        case 'C':
          gripper.write(0);
        break;

        case 'S':
          move_stop();
        break;

        case 'A':
          forward();
          delay(1500);
          move_stop();
          delay(500);
          spin_left();
          delay(800);
          move_stop();
          delay(500);
          forward();
          delay(2000);
          move_stop();
          delay(500);
          gripper.write(70);
          
          
        break;

        
    }
  }
}

void forward(){
   motor_Kanan_Depan.run(FORWARD);
   motor_Kanan_Belakang.run(FORWARD);
   motor_Kiri_Depan.run(FORWARD);
   motor_Kiri_Belakang.run(FORWARD);
}

void backward(){
   motor_Kanan_Depan.run(BACKWARD);
   motor_Kanan_Belakang.run(BACKWARD);
   motor_Kiri_Depan.run(BACKWARD);
   motor_Kiri_Belakang.run(BACKWARD);
}

void right(){
   motor_Kanan_Depan.run(BACKWARD);
   motor_Kanan_Belakang.run(FORWARD);
   motor_Kiri_Depan.run(FORWARD);
   motor_Kiri_Belakang.run(BACKWARD);
}

void left(){
   motor_Kanan_Depan.run(FORWARD);
   motor_Kanan_Belakang.run(BACKWARD);
   motor_Kiri_Depan.run(BACKWARD);
   motor_Kiri_Belakang.run(FORWARD);
}

void spin_right(){
   motor_Kanan_Depan.run(BACKWARD);
   motor_Kanan_Belakang.run(BACKWARD);
   motor_Kiri_Depan.run(FORWARD);
   motor_Kiri_Belakang.run(FORWARD);
}

void spin_left(){
   motor_Kanan_Depan.run(FORWARD);
   motor_Kanan_Belakang.run(FORWARD);
   motor_Kiri_Depan.run(BACKWARD);
   motor_Kiri_Belakang.run(BACKWARD);
}

void move_stop(){
   motor_Kanan_Depan.run(RELEASE);
   motor_Kanan_Belakang.run(RELEASE);
   motor_Kiri_Depan.run(RELEASE);
   motor_Kiri_Belakang.run(RELEASE);
}
