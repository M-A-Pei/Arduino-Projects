#define LED 2
#define tombol 3
int nilai;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(tombol, INPUT);
}

void loop() {

  nilai = digitalRead(tombol);
    if(nilai == HIGH)
    {
    digitalWrite(LED, HIGH);
    delay(60);
    digitalWrite(LED, LOW);
    delay(60); 
    }
    
}
