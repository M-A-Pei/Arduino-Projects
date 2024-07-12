void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  while(5 > 4){
    Serial.println("berulang");
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  String value = "apel";
  int value_1 = 19;

  //Serial.println(value + value_1);

//    if( value == "apel"){
//      Serial.println("apel");
//    }else if( value == "mangga" ){
//      Serial.println("mangga");
//    }else{
//      Serial.println("halo");
//    }
  
}
