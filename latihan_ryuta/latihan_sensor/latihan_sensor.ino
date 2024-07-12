int sensor_kiri = 10;
int value_kiri;
int sensor2 = 11;
int value2;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor1, INPUT);
  Serial.begin(9600);
  pinMode(sensor2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value1 = digitalRead(sensor1); //posisi 10, 1 atau 0
  value2 = digitalRead(sensor2);

  if(value1 == LOW && value2 == LOW){
    Serial.println("maju"); 
  }else if(value1 == HIGH && value2 == LOW){
    Serial.println("kiri");
  }else if(value1 == LOW && value2 == HIGH){
    Serial.println("kanan");
  }

  delay(50);
}
