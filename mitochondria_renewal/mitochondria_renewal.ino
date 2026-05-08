#include "src/Controller_PS4.h"
#include "src/MecanumDriver.h"

constexpr char mac[] = "00:00:00:00:00:00";
Controller_PS4 ds4(mac);

constexpr uint8_t FLpin[2] = {1,2};
constexpr uint8_t BLpin[2] = {1,2};
constexpr uint8_t BRpin[2] = {1,2};
constexpr uint8_t FRpin[2] = {1,2};
Mecanum leg;

void setup(){
  if(!ds4.begin()) return;
  leg.begin(FLpin,BLpin,BRpin,FRpin);
}

void loop(){
  if(ds4.update()){
    leg.update(
        ds4.get_input().angle,
        ds4.get_input().dist,
        ds4.get_input().turn
    );
    leg.move();
  }
  else{
    leg.update(0, 0, 0);
    leg.move();
  }
}
