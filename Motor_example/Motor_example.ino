#define MotorPin1 2
#define MotorPin2 3

void setup() {
  // put your setup code here, to run once:
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MotorPin1, HIGH); 
  digitalWrite(MotorPin2, LOW);
  delay(1000);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  delay(1000);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
  delay(1000);
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
  delay(1000);
}
