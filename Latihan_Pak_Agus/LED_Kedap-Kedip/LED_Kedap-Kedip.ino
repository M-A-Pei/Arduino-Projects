int nilai;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai = digitalRead(2);
  
  if(nilai == HIGH){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    delay(50);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    delay(50);

    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }else{
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  
}
