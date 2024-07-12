#define DigitalPin 2
#define AnalogPin A0

int analogValue;
int digitalValue;

void setup() {
  pinMode(DigitalPin, INPUT);
  pinMode(AnalogPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalValue = digitalRead(DigitalPin);
  Serial.print("Nilai Sinyal Digital Adalah = ");
  Serial.println(digitalValue);

  analogValue = analogRead(AnalogPin);
  Serial.print("Nilai Sinyal Analog Adalah = ");
  Serial.println(analogValue);

  
  delay(500);

}
