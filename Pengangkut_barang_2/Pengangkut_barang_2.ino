#include <Servo.h>
#include <AFMotor.h>
#include <IRremote.hpp>
//#define IR_USE_AVR_TIMER 2

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

void setup() {
  // put your setup code here, to run once:
  gripper.attach(10);
  arm.attach(9);
   Serial.begin(9600);
   Serial.println("start");

   motor_Kanan_Depan.setSpeed(100);
   motor_Kanan_Belakang.setSpeed(100);
   motor_Kiri_Depan.setSpeed(100);
   motor_Kiri_Belakang.setSpeed(150);

//   IrReceiver.begin(2);
}

void loop() {

//  if(IrReceiver.decode()){ 
//    Serial.println(IrReceiver.decodedIRData.decodedRawData , HEX);
//    IrReceiver.resume();
//  }

  gripper.write(0);

  right();
  delay(2000);
  move_stop();
  delay(1000);
  left();
  delay(2000);
  move_stop();
  delay(1000);

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
