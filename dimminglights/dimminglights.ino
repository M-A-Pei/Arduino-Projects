#define pwmpin 3
#define potentiopin A0
int potentiovalue;

void setup() {
  pinMode(pwmpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potentiovalue = analogRead(potentiopin);
  analogWrite(pwmpin, potentiovalue);
  Serial.println(potentiovalue);
  delay(500);

}
