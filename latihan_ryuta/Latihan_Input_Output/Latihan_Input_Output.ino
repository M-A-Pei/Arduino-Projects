int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  x = digitalRead(5);

  if(x == HIGH){
      digitalWrite(2, HIGH); //nyalain lampu 2
      digitalWrite(3, LOW); //matiin yang lain
      digitalWrite(4, LOW);
      delay(250); //tunggu 1 detik
      digitalWrite(2, LOW); //nyalain lampu 3
      digitalWrite(3, HIGH);//matiin yang lain
      digitalWrite(4, LOW);
      delay(250);
      digitalWrite(2, LOW); //nyalain lampu 4
      digitalWrite(3, LOW);//matiin yang lain
      digitalWrite(4, HIGH);
      delay(250);
  }else{
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);//matiin SEMUANYA
      digitalWrite(4, LOW);
  }

  
}
