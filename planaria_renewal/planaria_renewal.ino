#include "src/Controller_PS4.h"
#include "src/MecanumDriver.h"

constexpr char mac[] = "00:00:00:00:00:01";
Controller_PS4 ds4(mac);

constexpr uint8_t FLpin[] = {14,27};
constexpr uint8_t BLpin[] = {26,25};
constexpr uint8_t BRpin[] = {33,32};
constexpr uint8_t FRpin[] = {16,17};
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
