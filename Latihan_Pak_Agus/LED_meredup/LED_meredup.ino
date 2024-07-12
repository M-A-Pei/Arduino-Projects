#define AnalogPin A0

int analogValue = 1;

void setup() {
  pinMode(AnalogPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(analogValue < 1023){
    analogWrite(AnalogPin, analogValue);
    Serial.println(analogValue);
    analogValue++;
    delay(5);
  }

  while(analogValue > 1){
    analogWrite(AnalogPin, analogValue);
    Serial.println(analogValue);
    analogValue--;
    delay(5);
  }

}
