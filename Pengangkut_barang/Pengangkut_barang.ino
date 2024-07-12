#include <Servo.h>
#define IR_USE_AVR_TIMER 2
#include <IRremote.hpp>

const int recv_pin = 2;
const int motor1pin1 = 3;
const int motor1pin2 = 4;
const int motor1pinENA = 5;
const int motor2pin1 = 7;
const int motor2pin2 = 8;
const int motor2pinENA = 6;
const int pinServoGripper = 10;
const int pinServoTangan = 9;

Servo Tangan;
Servo Gripper;

void setup() {
  IrReceiver.begin(recv_pin);
  Serial.begin(9600);
  Gripper.attach(pinServoGripper);
  Tangan.attach(pinServoTangan);

  pinMode(pinServoGripper, OUTPUT);
  pinMode(pinServoTangan, OUTPUT);
  pinMode(recv_pin, INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pinENA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2pinENA, OUTPUT);

  Gripper.write(95);
  Tangan.write(140);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode())
  { 
    Serial.println(IrReceiver.decodedIRData.decodedRawData , HEX);
    
     switch(IrReceiver.decodedIRData.decodedRawData)
     {
       case 0xFF00DB24: //maju
        maju(150);
        break;

       case 0xE619DB24: //maju pelan
        maju(90);
        break;

       case 0xFE01DB24: //mundur
        mundur(150);
        break;

       case 0xEF10DB24: //mundur pelan
        mundur(90);
        break;

       case 0xFC03DB24: // kiri
        kiri(150);
        break;

       case 0xE31CDB24: // kanan pelan
        kanan(90);
        break;

       case 0xFD02DB24: // kanan
        kanan(150);
        break;

       case 0xF20DDB24: // kiri pelan
        kiri(90);
        break;

       case 0xF40BDB24: // tutup tangan
        Serial.println("tutup tangan");
        Gripper.write(170);
        break;

       case 0xBC43DB24: // buka tangan
        Serial.println("buka tangan");
        Gripper.write(95);
        break;

       case 0xB847DB24: // angkat tangan
        Serial.println("angkat tangan");
        Tangan.write(175);
        break;

       case 0xF30CDB24: // tengah tangan
        Serial.println("tengah tangan");
        Tangan.write(95);
        break;
        
       case 0xB24DDB24: // turun tangan
        Serial.println("turun tangan");
        Tangan.write(80);

       case 0xB04FDB24: // turun tangan
        Serial.println("turun tangan");
        Tangan.write(80);

        break;
       
       default:
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
      }
    
    delay(300);
    IrReceiver.resume();
  }
}

void maju(int kecepatan){
  Serial.println("maju");
     digitalWrite(motor1pin1, HIGH); //motor kanan maju
     digitalWrite(motor1pin2, LOW);
     analogWrite(motor1pinENA, kecepatan);
     digitalWrite(motor2pin1, HIGH); //motor kiri maju
     digitalWrite(motor2pin2, LOW);
     analogWrite(motor2pinENA, kecepatan);
}

void mundur(int kecepatan){
  Serial.println("mundur");
     digitalWrite(motor1pin1, LOW); //motor kanan mundur
     digitalWrite(motor1pin2, HIGH);
     analogWrite(motor1pinENA, kecepatan);
     digitalWrite(motor2pin1, LOW); //motor kiri mundur
     digitalWrite(motor2pin2, HIGH);
     analogWrite(motor2pinENA, kecepatan);
}

void kanan(int kecepatan){
  Serial.println("kanan");
     digitalWrite(motor1pin1, LOW); // motor kanan mundur
     digitalWrite(motor1pin2, HIGH);
     analogWrite(motor1pinENA, kecepatan);
     digitalWrite(motor2pin1, HIGH); //motor kiri maju
     digitalWrite(motor2pin2, LOW);
     analogWrite(motor2pinENA, kecepatan);
}

void kiri(int kecepatan){
  Serial.println("kiri");
     digitalWrite(motor1pin1, HIGH); //motor kanan maju
     digitalWrite(motor1pin2, LOW);
     analogWrite(motor1pinENA, kecepatan);
     digitalWrite(motor2pin1, LOW); //motor kiri mundur
     digitalWrite(motor2pin2, HIGH);
     analogWrite(motor2pinENA, kecepatan);
}
