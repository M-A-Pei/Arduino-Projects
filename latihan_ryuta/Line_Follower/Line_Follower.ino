int motorKiri_1 = 2;   // pin untuk motor kiri
int motorKiri_2 = 3; 
int motorKanan_1 = 4;  // pin untuk motor kanan
int motorKanan_2 = 5;

int sensor_kiri = 6;  // pin untuk sensor kiri
int value_kiri;       // variable untuk nilai sensor kiri
int sensor_kanan = 7;  // pin untuk sensor kanan
int value_kanan;       // variable untuk nilai sensor kanan

void setup() {
  pinMode(motorKiri_1, OUTPUT);  // --|
  pinMode(motorKiri_2, OUTPUT);  //   |
  pinMode(motorKanan_1, OUTPUT); //   |~~> tentukan pin adalah OUTPUT atau INPUT
  pinMode(motorKanan_2, OUTPUT); //   |
  pinMode(sensor_kiri, INPUT);   //   |
  pinMode(sensor_kanan, INPUT);  // __|
}

void loop() {
  value_kiri = digitalRead(sensor_kiri);  // baca posisi pin "sensor kiri" lalu menaruhnya di dalam variable "value"
  value_kanan = digitalRead(sensor_kanan);  // baca posisi pin "sensor kanan" lalu menaruhnya di dalam variable "value"

  if(value_kiri == LOW && value_kanan == LOW){
    digitalWrite(motorKiri_1, HIGH);  // motor kiri maju
    digitalWrite(motorKiri_2, LOW);                          //mobil menjadi maju
    digitalWrite(motorKanan_1, HIGH);  //motor kanan maju
    digitalWrite(motorKanan_2, LOW);
  } else if(value_kiri == HIGH && value_kanan == LOW){
    digitalWrite(motorKiri_1, LOW);  // motor kiri mundur
    digitalWrite(motorKiri_2, HIGH);                          //mobil menjadi belok kiri
    digitalWrite(motorKanan_1, HIGH);  //motor kanan maju
    digitalWrite(motorKanan_2, LOW);
  } else if(value_kiri == LOW && value_kanan == HIGH){
    digitalWrite(motorKiri_1, HIGH);  // motor kiri maju
    digitalWrite(motorKiri_2, LOW);                          //mobil menjadi belok kanan
    digitalWrite(motorKanan_1, LOW);  //motor kanan mundur
    digitalWrite(motorKanan_2, HIGH);
  }

  delay(50);
}
