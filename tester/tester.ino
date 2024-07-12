void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String Secondinput = Serial.readStringUntil('\n');
    Serial.print( "SecondInput(" );
    Serial.print( Secondinput );
    Serial.println( ")." );
  }
}
