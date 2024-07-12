void setup() {
  Serial.begin(9600);
}

void loop() {
  String teks;

  if (Serial.available() > 0)
  {
    teks = Serial.readString();
  }

  if(teks.length() > 0)
  {
    Serial.println(teks); 
  }
}
