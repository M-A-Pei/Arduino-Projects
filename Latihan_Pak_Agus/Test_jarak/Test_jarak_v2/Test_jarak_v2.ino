#include <NewPing.h>

#define trig 2
#define echo 3
#define pin_full 5
#define pin_medium 6
#define pin_low 7
#define pin_empty 8

int jarak;

NewPing sensorjarak(trig, echo, 230);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(trig, INPUT);
  pinMode(echo, INPUT);
  pinMode(pin_full, OUTPUT);
  pinMode(pin_medium, OUTPUT);
  pinMode(pin_low, OUTPUT);
  pinMode(pin_empty, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(jarak = 20; jarak <= 250; jarak++){
      Serial.print(jarak);
      Serial.print(" cm");
    
      if(jarak == 0){ 
       digitalWrite(pin_full, LOW); 
       digitalWrite(pin_medium, LOW);
       digitalWrite(pin_low, LOW);
       digitalWrite(pin_empty, LOW);
       Serial.println(" = sedang no signal");
      }else if(jarak >= 20 && jarak < 50){ //lebih dekat dengan 20cm = 100%
       digitalWrite(pin_full, HIGH); 
       digitalWrite(pin_medium, LOW);
       digitalWrite(pin_low, LOW);
       digitalWrite(pin_empty, LOW);
       Serial.println(" = 100%"); 
      }else if(jarak >= 50 && jarak < 105){ //lebig dekat dengan 80cm = 75%
       digitalWrite(pin_full, LOW); 
       digitalWrite(pin_medium, HIGH);
       digitalWrite(pin_low, LOW);
       digitalWrite(pin_empty, LOW);
       Serial.println(" = %75"); 
      }else if(jarak >= 105 && jarak < 162){ //lebih dekat dengan 130cm = 50%
       digitalWrite(pin_full, LOW); 
       digitalWrite(pin_medium, LOW);
       digitalWrite(pin_low, HIGH);
       digitalWrite(pin_empty, LOW);
       Serial.println(" = %50");
      }else if(jarak >= 162 && jarak < 212){ //lebih dekat dengan 195cm = 25%
       digitalWrite(pin_full, LOW); 
       digitalWrite(pin_medium, LOW);
       digitalWrite(pin_low, LOW);
       digitalWrite(pin_empty, HIGH); 
       Serial.println(" = 25%");
      }else if(jarak >= 212){ //lebih dekat dengan 230cm = 10%
       digitalWrite(pin_full, LOW); 
       digitalWrite(pin_medium, LOW);
       digitalWrite(pin_low, LOW);
       digitalWrite(pin_empty, HIGH); 
       Serial.println(" = 10%");
      }
    
      delay(50);
    
   }

}
