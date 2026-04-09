// test program for PS4 controller //

#include <PS4Controller.h>
const char MACADDRESS[] = "b0:cb:d8:c0:45:d2";

void setup(){
  Serial.begin(115200);
  PS4.begin(MACADDRESS);
}

void loop(){
  if(PS4.isConnected()){
    Serial.print(PS4.LStickX());
    Serial.print(",");
    Serial.println(PS4.LStickY());
  }
}
