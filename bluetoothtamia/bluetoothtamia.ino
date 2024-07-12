int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);

  Serial.println("program is ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char z = Serial.read();
    Serial.println(z);
    char state = z;


    if(state == 'w')
    {
      //forward
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);  

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
    else if(state == 's')
    {
      //backwards
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);  

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);  
    }
    else if(state == 'a')
    {
      //right
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);  

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    }
    else if(state == 'd')
    {
      //left
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);  

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW); 
    }
    else if(state == 'o')
    {
      //off
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);  

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);  
    }
  }
}
