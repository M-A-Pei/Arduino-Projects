int actPin = 0;

void setup() {

pinMode(1, OUTPUT);
pinMode(0, OUTPUT);
pinMode(2, OUTPUT);

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
}

void loop() {

  digitalWrite(actPin, LOW);
  
  if (actPin == 2) {
    actPin = 0;
  } else {
    actPin ++;
  }
  digitalWrite(actPin, HIGH);

  delay(2000);

}
