#define motor_1 2
#define motor_2 3

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor_1, HIGH);
  digitalWrite(motor_2, LOW);
}
