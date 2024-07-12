#include <NewPing.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trig 2
#define echo 3
#define pin_overflow 4
#define pin_full 5
#define pin_medium 6
#define pin_low 7
#define pin_empty 8
#define alarm 9

int jarak;
int persentase;
int air;

NewPing sensorjarak(trig, echo, 230);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  
  pinMode(trig, INPUT);
  pinMode(echo, INPUT);
  pinMode(pin_overflow, OUTPUT);
  pinMode(pin_full, OUTPUT);
  pinMode(pin_medium, OUTPUT);
  pinMode(pin_low, OUTPUT);
  pinMode(pin_empty, OUTPUT);
  pinMode(alarm, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  
  jarak = sensorjarak.ping_cm();

  persentase = map(jarak, 0, 60, 100, 0);
  
  Serial.println(persentase);
  Serial.println(jarak);

  lcd.setCursor(4, 1);
  

  if(jarak == 0){
   digitalWrite(alarm, LOW); 
   digitalWrite(pin_overflow, LOW);
   digitalWrite(pin_full, LOW); 
   digitalWrite(pin_medium, LOW);
   digitalWrite(pin_low, LOW);
   digitalWrite(pin_empty, LOW);
   Serial.println("sedang so signal");

   persentase = 0;
  }
  else if(jarak < 5){
      digitalWrite(pin_overflow, HIGH);
   digitalWrite(alarm, HIGH); 
   digitalWrite(pin_full, LOW); 
   digitalWrite(pin_medium, LOW);
   digitalWrite(pin_low, LOW);
   digitalWrite(pin_empty, LOW);

   Serial.println("sedang overflow");
  }else if(jarak > 5 && jarak < 20){
   digitalWrite(alarm, LOW); 
   digitalWrite(pin_overflow, LOW);
   digitalWrite(pin_full, HIGH); 
   digitalWrite(pin_medium, LOW);
   digitalWrite(pin_low, LOW);
   digitalWrite(pin_empty, LOW);
   Serial.println("sedang full"); 
  }else if(jarak > 20 && jarak < 50){
      digitalWrite(pin_overflow, LOW);
   digitalWrite(alarm, LOW); 
   digitalWrite(pin_full, LOW); 
   digitalWrite(pin_medium, HIGH);
   digitalWrite(pin_low, LOW);
   digitalWrite(pin_empty, LOW);
   Serial.println("sedang medium"); 
  }else if(jarak > 50 && jarak < 55){
   digitalWrite(alarm, LOW); 
   digitalWrite(pin_overflow, LOW);
   digitalWrite(pin_full, LOW); 
   digitalWrite(pin_medium, LOW);
   digitalWrite(pin_low, HIGH);
   digitalWrite(pin_empty, LOW);
   Serial.println("sedang low");
  }else if(jarak > 55){
   digitalWrite(alarm, HIGH); 
   digitalWrite(pin_overflow, LOW);
   digitalWrite(pin_full, LOW); 
   digitalWrite(pin_medium, LOW);
   digitalWrite(pin_low, LOW);
   digitalWrite(pin_empty, HIGH); 
   Serial.println("sedang empty");
  }

  lcd.setCursor(3,0);
  lcd.print("air sedang");
  lcd.setCursor(7,1);
  lcd.print(persentase);
  lcd.print("%");

  delay(500);
}
