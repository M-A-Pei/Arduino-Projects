void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.println("program is ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char z = Serial.read();
    Serial.println(z);
    char state = z;

    if(state == 'a'){
   

    while(state != 'b')
    {
    digitalWrite(3, HIGH);
    digitalWrite(6, LOW);
    delay(25);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    delay(25);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(25);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    delay(25);

    z = Serial.read();
    state = z;
    }
  }

  if(state == 'b'){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  }
 }
