#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
}

void loop() {
  mySwitch.send("000101010101000101010101");
  delay(1000);  
  mySwitch.send("000101010101000101010100");
  delay(1000);  
  mySwitch.send("000101010101010001010101");
  delay(1000);  
  mySwitch.send("000101010101010001010100");
  delay(1000);
}
