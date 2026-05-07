#pragma once
#include <Arduino.h>
#include "AnalogMotorDriver.h"

class Mecanum{
private:
  AnalogMotor motors[4];
  
  enum MOTOR{
    FRONTLEFT,BACKLEFT,BACKRIGHT,FRONTRIGHT
  };

  struct gain{
    bool reversed[4];
    int max_speed[4];
  } config;

public:
  Mecanum(){}
 
  void begin(const uint8_t pin_FR[], const uint8_t pin_BL[], const uint8_t pin_BR[], const uint8_t pin_FR[]){
     this->motors[FRONTLEFT].attach(pin_FR);
      this->motors[BACKLEFT].attach(pin_BL);
     this->motors[BACKRIGHT].attach(pin_BR);
    this->motors[FRONTRIGHT].attach(pin_FR);
  }

  void move(float direction, int speed_line, int speed_turn){
     this->motors[FRONTLEFT].move((speed_line *cos(0.25*PI +direction) +speed_turn)*(this->config.reversed[FRONTLEFT] ?-1:1));
      this->motors[BACKLEFT].move((speed_line *sin(0.25*PI +direction) +speed_turn)*(this->config.reversed[BACKLEFT]  ?-1:1));
     this->motors[BACKRIGHT].move((speed_line *cos(0.25*PI +direction) -speed_turn)*(this->config.reversed[BACKRIGHT] ?-1:1));
    this->motors[FRONTRIGHT].move((speed_line *sin(0.25*PI +direction) -speed_turn)*(this->config.reversed[FRONTRIGHT]?-1:1));
  }
};