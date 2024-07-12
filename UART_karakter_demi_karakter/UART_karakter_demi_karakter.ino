void setup() {
  Serial.begin(9600);
}

void loop() {
  String teks;

  while (Serial.available() > 0)
  {
    char karakter = Serial.read();
    teks = teks + karakter;
    delay(10);
  }

  if(teks.length() > 0)
  {
    Serial.println(teks); 
  }
}
