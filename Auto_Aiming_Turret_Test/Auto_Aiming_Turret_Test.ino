#include <SoftwareSerial.h>

char rxPin = 10;
char txPin = 11;

String text;

SoftwareSerial python(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  python.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(python.available() > 0)
  {
    text = python.readString();
    Serial.println(text);
    python.println(text);
  }
}
