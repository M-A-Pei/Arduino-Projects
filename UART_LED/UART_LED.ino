#define LED_merah 2
#define LED_hijau 3

void setup() {
  Serial.begin(9600);
  pinMode(LED_merah, OUTPUT);
  pinMode(LED_hijau, OUTPUT);
}

void loop() {
  String input;
  if(Serial.available() > 0)
  {
    input = Serial.readString();
    input.trim();
  }
  
  if(input.length() > 0)
  {
    Serial.println(input);
    if(input == "LED merah nyala")
      digitalWrite(LED_merah, HIGH);
    else if(input == "LED merah mati")
      digitalWrite(LED_merah, LOW);
    else if(input == "LED hijau nyala")
      digitalWrite(LED_hijau, HIGH);
     else if(input == "LED hijau mati")
      digitalWrite(LED_hijau, LOW);
     else
      Serial.println("tidak terjadi apa apa");
  }
}
