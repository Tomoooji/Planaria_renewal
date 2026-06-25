#include "Controller_PS4.h"
#include "MecanumDriver.h"

constexpr char mac[] = "00:00:00:00:00:01";
Controller_PS4 dualshock4(mac);

constexpr uint8_t FLpin[] = {27,14};
constexpr uint8_t BLpin[] = {25,26};
constexpr uint8_t BRpin[] = {32,33};
constexpr uint8_t FRpin[] = {17,16};
int leg_max[] = {170,170,170,170};
Mecanum leg;

void setup(){
  dualshock4.get_config().ignore_range_stick = 50;
  dualshock4.get_config().ignore_limit_triger = 50;

  *leg.get_config().max_speed = *leg_max;

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
  }
  else{
    leg.update(0, 0, 0);
  }
  leg.move();
}
