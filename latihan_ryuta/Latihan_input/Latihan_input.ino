int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  x = digitalRead(5); //x jadi "1" klo 5 itu terhubung positif
                      //x jadi "0" klo 5 itu terhubung negatif 

  if(x == HIGH){
    Serial.println("nyala");
  }else{
    Serial.println("mati");
  }
}
