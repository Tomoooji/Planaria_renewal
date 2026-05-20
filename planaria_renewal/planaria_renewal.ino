#include "src/Controller_PS4.h"
#include "src/MecanumDriver.h"

constexpr char mac[] = "00:00:00:00:00:01";
Controller_PS4 dualshock4(mac);

constexpr uint8_t FLpin[] = {14,27};
constexpr uint8_t BLpin[] = {26,25};
constexpr uint8_t BRpin[] = {33,32};
constexpr uint8_t FRpin[] = {16,17};
Mecanum leg;

void setup(){
  //leg.get_config().reversed[Mecanum::FRONTLEFT]=true;
  if(!dualshock4.begin()) return;
  leg.begin(FLpin,BLpin,BRpin,FRpin);
}

void loop(){
  if(dualshock4.update()){
    leg.update(
        dualshock4.get_input().angle,
        dualshock4.get_input().dist,
        dualshock4.get_input().turn
    );
    //leg.move();
  }
  else{
    leg.update(0, 0, 0);
  }
  leg.move();
}
