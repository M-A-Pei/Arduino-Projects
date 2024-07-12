

#define Led_ijo 2
#define Led_biru 3
#define Led_merah 4
#define analog A0

int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led_ijo, OUTPUT);
  pinMode(Led_biru, OUTPUT);
  pinMode(Led_merah, OUTPUT);
  pinMode(analog, INPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(analog);

 if(value > 100 && value < 500){
 digitalWrite(Led_ijo, HIGH);
 digitalWrite(Led_biru, LOW);
 digitalWrite(Led_merah, LOW);
 Serial.println("Led_ijo menyala");
 
  
 }else if(value > 500 && value < 1023){
 digitalWrite(Led_biru, HIGH);
 digitalWrite(Led_ijo, LOW);
 digitalWrite(Led_merah, LOW);
 Serial.println("Led_biru menyala");

  
 }else if(value == 1023){
digitalWrite(Led_merah, HIGH);
digitalWrite(Led_biru, LOW);
digitalWrite(Led_ijo, LOW);
Serial.println("Led_merah menyala");

  
 }

  Serial.println(value);
  


  
}
