#define soundPin 4
#define Led_v 2
#define Led_g 3

int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(Led_v, OUTPUT);
  pinMode(Led_g, OUTPUT);

  digitalWrite(Led_g, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(soundPin);
  
  Serial.println(value);

  if(value == HIGH){
    digitalWrite(Led_v, HIGH);
    delay(500);
  }else{
    digitalWrite(Led_v, LOW);
  }
  
}
