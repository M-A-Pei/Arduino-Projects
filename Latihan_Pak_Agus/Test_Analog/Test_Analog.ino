#define AnalogPin A0
#define red 2
#define blue 3
#define yellow 4

int analogValue;
void setup() {
  pinMode(AnalogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(analogPin);
  if(analogValue > 100 && analogValue < 500){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, LOW);
  }else if(analogValue > 500 && analogValue < 1023){
        digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, LOW);
  }else if(analogValue == 1023){
        digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, LOW);
  }
  delay(500);

}
