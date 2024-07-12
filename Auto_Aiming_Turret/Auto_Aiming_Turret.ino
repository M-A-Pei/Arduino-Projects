#include <SoftwareSerial.h>

char rxPin = 10;
char txPin = 11;

char c;
String dataIn;
char indexOfX, indexOfY;

int Xvalue, Yvalue;

SoftwareSerial python(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  python.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(python.available() > 0)
   {
     c = python.read();
     if(c == "/n"){break;}
     else{dataIn += c;}
   }

   if(c == "/n")
   {
     parseData();
     
     c = "";
     dataIn = "";

   Serial.print("x = ");
   Serial.println(Xvalue);
   Serial.print("y = ");
   Serial.println(Yvalue);
   Serial.print(" ");
   }
}

void parseData() {
  indexOfX = dataIn.indexOf("X");
  indexOfY = dataIn.indexOf("Y");

  Xvalue = dataIn.substring(0, indexOfX).toInt();
  Yvalue = dataIn.substring(indexOfX + 1, indexOfY).toInt();
}
