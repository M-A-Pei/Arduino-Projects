#include <IRremote.hpp>
#define IR_USE_AVR_TIMER 2

const int recv_pin = 2;


void setup() {
   Serial.begin(9600);
   Serial.println("start");
   IrReceiver.begin(recv_pin);
}

void loop() {

  if(IrReceiver.decode()){ 
    Serial.println(IrReceiver.decodedIRData.decodedRawData , HEX);
    Serial.println("TEST BERHASIL");
    IrReceiver.printIRResultShort(&Serial);
    Serial.println(IrReceiver.decodedIRData.command);
     IrReceiver.resume();
  }
  
}
