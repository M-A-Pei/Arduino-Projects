int variable_1 = 15;

#define Led_1 2
#define Led_2 3
#define input 4
#define analog A0

int value;
int value_2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(input, INPUT);
  pinMode(analog, INPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(input);
  value_2 = analogRead(analog);

  

  if(value == 1)
  {
      digitalWrite(Led_1, HIGH);
      digitalWrite(Led_2, LOW);
      delay(250);
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, HIGH);
      delay(250);
  }else
  {
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);
   }
  
  Serial.println(value);
  Serial.println(value_2);
  delay(250);


  
}
