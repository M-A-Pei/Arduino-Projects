int pinMotor1 = 2;
int pinMotor2 = 3;
int tombol = 4;

int posisi;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(tombol, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
posisi = digitalRead(tombol);

if(posisi == HIGH){
  //maju
}else{
  //mundur
}
  
//  digitalWrite(pinMotor1, HIGH); //maju
//  digitalWrite(pinMotor2, LOW);
//
//  delay(1000);
//
//  digitalWrite(pinMotor1, LOW); //mundur
//  digitalWrite(pinMotor2, HIGH);
//
//  delay(1000);
}
