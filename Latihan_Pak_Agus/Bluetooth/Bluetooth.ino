#define led_v 2
#define led_g 3

char sinyal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_v, OUTPUT);
  pinMode(led_g, OUTPUT);

  digitalWrite(led_g, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    sinyal = Serial.read();

    if(sinyal == 'a'){
      digitalWrite(led_v, HIGH);
    }else if(sinyal == 'b'){
      digitalWrite(led_v, LOW);
    }
    
  }
}
