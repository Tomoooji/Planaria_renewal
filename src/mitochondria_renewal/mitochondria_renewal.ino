#include "Controller_PS4.h"
#include "MecanumDriver.h"

constexpr char mac[] = "00:00:00:00:00:00";
Controller_PS4 ds4(mac);

constexpr uint8_t pin_FR = {};
constexpr uint8_t pin_BR = {};
constexpr uint8_t pin_BL = {};
constexpr uint8_t pin_FL = {};
Mecanum leg;

void setup(){
  if(!ds4.begin()) return;
  leg.begin(pin_FR,pin_BR,pin_BL,pin_FL);
}

void loop(){
  if(ds4.update()){
    leg.move(
        ds4.get_data().angle,
        ds4.get_data().dist,
        ds4.get_data().turn
    );
  }
  else{
    leg.move(0,0,0);
  }
}
